#include "Game.hpp"
using namespace irrklang;
//ISoundEngine *SoundEngine = createIrrKlangDevice();

Game::Game()
{
	init();

}

Game::~Game()
{

}

void Game::init()
{



	glm::vec3 cameraPos   = glm::vec3(3.0f, 5.0f, 30.0f);
	glm::vec3 cameraFront = glm::vec3(0.0f, -1.0f, -1.0f);
	glm::vec3 cameraLook = glm::vec3(0.0f,0.0f,0.0f);
	glm::vec3 cameraUp    = glm::vec3(0.0f, 1.0f, 0.0f);

	//SoundEngine->play2D("multi/encendido_auto.ogg",GL_FALSE);
	
	

	bool firstMouse = true;
	float yaw   = -90.0f;	
	float pitch =  0.0f;
	float lastX =  g_gl_width / 2.0;
	float lastY =  g_gl_height / 2.0;
	float fov   =  45.0f;
	
	this->camara=new Camera(cameraPos,cameraFront,cameraUp,fov,pitch,yaw,g_gl_width,g_gl_height);

	cameraPos   = glm::vec3(-3.0f, 5.0f, 30.0f);
	cameraFront = glm::vec3(0.0f, -1.0f, -1.0f);
	cameraLook = glm::vec3(0.0f,0.0f,0.0f);
	cameraUp    = glm::vec3(0.0f, 1.0f, 0.0f);

	firstMouse = true;
	yaw   = -90.0f;	
	pitch =  0.0f;
	lastX =  g_gl_width / 2.0;
	lastY =  g_gl_height / 2.0;
	fov   =  45.0f;

	this->camara2=new Camera(cameraPos,cameraFront,cameraUp,fov,pitch,yaw,g_gl_width,g_gl_height);

	
	restart_gl_log ();
	start_gl ();
	glEnable (GL_DEPTH_TEST); 
	glDepthFunc (GL_LESS); 
	glEnable (GL_CULL_FACE); 
	glCullFace (GL_BACK); 
	glFrontFace (GL_CCW); 
	glClearColor (0.2, 0.2, 0.2, 1.0);
	glViewport (0, 0, g_gl_width/2, g_gl_height);

	this->shader_programme = create_programme_from_files (
		VERTEX_SHADER_FILE, FRAGMENT_SHADER_FILE
	);
    this->projection = camara->getPerspectiva();
    this->view = camara->getViewMatrix();

    this->projection2 = camara2->getPerspectiva();
    this->view2 = camara2->getViewMatrix();

	this->view_mat_location = glGetUniformLocation (shader_programme, "view");
	glUseProgram (shader_programme);
	glUniformMatrix4fv(view_mat_location, 1, GL_FALSE, &view[0][0]);
	this->proj_mat_location = glGetUniformLocation (shader_programme, "proj");
	glUseProgram (shader_programme);
	glUniformMatrix4fv (proj_mat_location, 1, GL_FALSE, &projection[0][0]);

	this->model_mat_location = glGetUniformLocation (shader_programme, "model");


	btDefaultCollisionConfiguration* collisionConfiguration = new btDefaultCollisionConfiguration();
	btCollisionDispatcher* dispatcher = new btCollisionDispatcher(collisionConfiguration);
	btBroadphaseInterface* overlappingPairCache = new btDbvtBroadphase();
	btSequentialImpulseConstraintSolver* solver = new btSequentialImpulseConstraintSolver;
	
	this->dynamicsWorld = new btDiscreteDynamicsWorld(dispatcher, overlappingPairCache, solver, collisionConfiguration);
	dynamicsWorld->setGravity(btVector3(0, -10, 0));
	this->mapa = new Mapa(dynamicsWorld,shader_programme);

	this->vehicle1 = new Vehicle((char*)"mallas/ae86-t.obj",shader_programme,btScalar(25),
		mapa -> getP1StartPosition(),btQuaternion(0,1,0,0),dynamicsWorld,(char*)"textures/ae86_t2.png", 1);
	this->vehicle2 = new Vehicle((char*)"mallas/pika_ae86.obj",shader_programme,btScalar(25),
		mapa -> getP2StartPosition(),btQuaternion(0,1,0,0),dynamicsWorld,(char*)"textures/pika_ae86_t.png",2);

	this->input=new Input(g_window,vehicle1,vehicle2,camara,camara2,mapa);
	this->debug = new GLDebugDrawer();


	debug->setDebugMode(btIDebugDraw::DBG_DrawWireframe );
	debug->setView(&view);
	debug->setProj(&projection);
	dynamicsWorld->setDebugDrawer(debug);
	
	vehicle1 -> updatePhysics();
	vehicle2 -> updatePhysics();



}


void Game::main_loop()
{
	float deltaTime = 0.0f;
	float lastFrame = 0.0f;
	while (!glfwWindowShouldClose(g_window))
	{
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        if (deltaTime < 0.016f)
            continue;
	    lastFrame = currentFrame;
        this->timer++;
        dynamicsWorld->stepSimulation(1.f / 60.f, 10);
        input->initialiceInput();

        glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glUseProgram (shader_programme);

		glViewport (0, 0, g_gl_width/2, g_gl_height);
        projection = camara->getPerspectiva();
        glUniformMatrix4fv (proj_mat_location, 1, GL_FALSE, &projection[0][0]);
        view = camara->getViewMatrix();
        glUniformMatrix4fv(view_mat_location, 1, GL_FALSE, &view[0][0]);
        vehicle1->draw(model_mat_location);
    	vehicle2->draw(model_mat_location);
		mapa -> draw(model_mat_location);

        glViewport (g_gl_width/2, 0, g_gl_width/2, g_gl_height);
        projection2 = camara2->getPerspectiva();
        glUniformMatrix4fv (proj_mat_location, 1, GL_FALSE, &projection2[0][0]);
        view2 = camara2->getViewMatrix();
        glUniformMatrix4fv(view_mat_location, 1, GL_FALSE, &view2[0][0]);
    	vehicle1->draw(model_mat_location);
    	vehicle2->draw(model_mat_location);
		mapa -> draw(model_mat_location);


		DetectCollision();

		detectDebuffs();

		checkWinCondition();
		
    	/*debug->setView(&view);
		debug->setProj(&projection);
		dynamicsWorld->debugDrawWorld();
		debug->drawLines();*/
	    
		
        glfwSwapBuffers(g_window);
        glfwPollEvents();
        
	}
	
	glfwTerminate();
}

void Game::DetectCollision()
{
	int numManifolds = dynamicsWorld->getDispatcher()->getNumManifolds();
	//printf("NumeroManifolds %d\n",numManifolds);
	for (int i = 0; i < numManifolds; i++)
    {
        btPersistentManifold* contactManifold = dynamicsWorld->getDispatcher()->getManifoldByIndexInternal(i);
        const btCollisionObject* obA = contactManifold->getBody0();
        const btCollisionObject* obB = contactManifold->getBody1();
 
        //if (!obA->getCollisionShape()->isNonMoving() && !obB->getCollisionShape()->isNonMoving()) {
            IsCollision = true;
			if (mapa->trampa_P1 == obA->getUserPointer() and vehicle2 == obB->getUserPointer())
			{
				vehicle2 -> slowDown(1);
				mapa->trampa_P1 -> setPosition(100,100,100);
				win_P2 = true;
			}
			else if (vehicle2 == obA->getUserPointer() and mapa->trampa_P1 == obB->getUserPointer())
			{
				vehicle2 -> slowDown(1);
				mapa->trampa_P1 -> setPosition(100,100,100);
			}
			
			if (mapa->trampa_P2 == obA->getUserPointer() and vehicle1 == obB->getUserPointer())
			{
				vehicle1 -> slowDown(1);
				mapa->trampa_P2 -> setPosition(100,100,100);
				win_P1 = true;
			}
			else if ( vehicle1 == obA->getUserPointer() and mapa->trampa_P2 == obB->getUserPointer())
			{
				vehicle1 -> slowDown(1);
				mapa->trampa_P2 -> setPosition(100,100,100);
			}
			
			//if () printf("vehicle 2 collision\n");
			//printf("collision detected\n");
        //}
    }
 
    IsCollision = false;

}

void Game::detectDebuffs()
{
	if (vehicle2->isSlowed and vehicle2 -> cdCount <= 0.01f)
	{
		vehicle2 -> isSlowed = false;
	}
	else
	{
		vehicle2 -> cdCount--;
	}
	if (vehicle1->isSlowed and vehicle1 -> cdCount <= 0.01f)
	{
		vehicle1 -> isSlowed = false;
	}
	else
	{
		vehicle1 -> cdCount--;
	}
}

void Game::checkWinCondition()
{
	if (win_P1 and vehicle1->self_timer == 0.0f)
	{
		vehicle1 -> self_timer = timer/60.0f;
		printf("Player 1 reachs in %.3f seconds\n", timer/60.0f);
	}
	if (win_P2 and vehicle2->self_timer == 0.0f)
	{
		vehicle2 -> self_timer = timer/60.0f;
		printf("Player 2 reachs in %.3f seconds\n", timer/60.0f);
	}
	if (win_P1 and win_P2)
	{
		if (vehicle1 -> self_timer < vehicle2 -> self_timer)
		{
			printf("Player 1 wins\n");
		}
		else
		{
			printf("Player 2 wins\n");
		}
		glfwSetWindowShouldClose(g_window, true);
	}
}