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


	printf("Cargando todo\n");
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
	printf("Creando Camaras\n");
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
	printf("Camaras Creadas\n");
	printf("Seteando Camaras\n");
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
    printf("Camaras seteadas\n");
    printf("Seteando mundo\n");
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
	printf("Mundo Listo\n");
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

	printf("Creando Luces\n");
	Light* lights_arr = new Light(shader_programme);
	lights_arr->addLight(glm::vec3(10.0, 10.0, 10.0),
		glm::vec3 (1.0, 0.0, 0.0),
		glm::vec3 (0.0, 0.0, 0.0),
		glm::vec3 (0.0, 0.0, 0.0),
		glm::vec3 (1.0, 0.7, 0.7),
		glm::vec3 (0.0, .6, 0.0),
		glm::vec3 (.04, 0.3, 0.8),32);

		
	lights_arr->addLight(glm::vec3(50.0, 60.0, 100.0),
		glm::vec3 (0.0, 1.0, 1.0),
		glm::vec3 (0.2, 0.2, 0.2),
		glm::vec3 (0.0, 0.0, 0.0),
		glm::vec3 (0.7, 0.2, 0.7),
		glm::vec3 (1.0, 1.0, 1.0),
		glm::vec3 (1.0, 1.0, 1.0),12);
	
	lights_arr->initLights();
	printf("Luces Listas\n");
	printf("Iniciando Juego \n");
}


void Game::main_loop()
{
	printf("A jugar\n");
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

		
        if (!win_P1)
        {
        	glViewport (0, 0, g_gl_width/2, g_gl_height);
        	projection = camara->getPerspectiva();
        	glUniformMatrix4fv (proj_mat_location, 1, GL_FALSE, &projection[0][0]);
        	view = camara->getViewMatrix();
        	glUniformMatrix4fv(view_mat_location, 1, GL_FALSE, &view[0][0]);
	        vehicle1->draw(model_mat_location);
	    	vehicle2->draw(model_mat_location);
			mapa -> draw(model_mat_location);
			vehicle1->bala->draw(model_mat_location);
			vehicle2->bala->draw(model_mat_location);
        }

/*
		    	debug->setView(&view);
		debug->setProj(&projection);
		dynamicsWorld->debugDrawWorld();
		debug->drawLines();

*/
        
    	if (!win_P2)
        {
        	glViewport (g_gl_width/2, 0, g_gl_width/2, g_gl_height);
        	projection2 = camara2->getPerspectiva();
	        glUniformMatrix4fv (proj_mat_location, 1, GL_FALSE, &projection2[0][0]);
	        view2 = camara2->getViewMatrix();
	        glUniformMatrix4fv(view_mat_location, 1, GL_FALSE, &view2[0][0]);
	        vehicle1->draw(model_mat_location);
	    	vehicle2->draw(model_mat_location);
			mapa -> draw(model_mat_location);
			vehicle1->bala->draw(model_mat_location);
			vehicle2->bala->draw(model_mat_location);
        }

		DetectCollision();

		detectDebuffs();

		checkCds();

		checkWinCondition();
		
	    
		
        glfwSwapBuffers(g_window);
        glfwPollEvents();
        
	}
	
	glfwTerminate();
}

void Game::DetectCollision()
{
	int numManifolds = dynamicsWorld->getDispatcher()->getNumManifolds();
	for (int i = 0; i < numManifolds; i++)
    {
        btPersistentManifold* contactManifold = dynamicsWorld->getDispatcher()->getManifoldByIndexInternal(i);
        const btCollisionObject* obA = contactManifold->getBody0();
        const btCollisionObject* obB = contactManifold->getBody1();
		if (mapa->trampa_P1 == obA->getUserPointer() and vehicle2 == obB->getUserPointer())
		{
			vehicle2 -> slowDown(1.5f);
			mapa->trampa_P1 -> setPosition(100,100,100);
			mapa -> trampa_P1_exists = false;
		}
		else if (vehicle2 == obA->getUserPointer() and mapa->trampa_P1 == obB->getUserPointer())
		{
			vehicle2 -> slowDown(1.5f);
			mapa->trampa_P1 -> setPosition(100,100,100);
			mapa -> trampa_P1_exists = false;
		}
		
		if (mapa->trampa_P2 == obA->getUserPointer() and vehicle1 == obB->getUserPointer())
		{
			vehicle1 -> slowDown(1.5f);
			mapa->trampa_P2 -> setPosition(100,100,100);
			mapa -> trampa_P2_exists = false;
		}
		else if ( vehicle1 == obA->getUserPointer() and mapa->trampa_P2 == obB->getUserPointer())
		{
			vehicle1 -> slowDown(1.5f);
			mapa->trampa_P2 -> setPosition(100,100,100);
			mapa -> trampa_P2_exists = false;
		}
		if (vehicle1->bala == obA->getUserPointer() and vehicle2 == obB->getUserPointer())
        {
			vehicle2 -> slowDown(0.5f);
			vehicle1-> bala->setPosition(100,100,100);
        }
        else if (vehicle2 == obA->getUserPointer() and vehicle1->bala == obB->getUserPointer())
        {
        	vehicle2 -> slowDown(0.5f);
        	vehicle1->bala->setPosition(100,100,100);
        }

		if (vehicle2->bala == obA->getUserPointer() and vehicle1 == obB->getUserPointer())
        {
			vehicle1 -> slowDown(0.5f);
			vehicle2-> bala->setPosition(100,100,100);
        }
        else if (vehicle1 == obA->getUserPointer() and vehicle2->bala == obB->getUserPointer())
        {
        	vehicle1 -> slowDown(0.5f);
        	vehicle2->bala->setPosition(100,100,100);
        }
        if (mapa->meta == obA->getUserPointer() and vehicle1 == obB->getUserPointer())
		{
			win_P1 = true;
			vehicle1 -> setPosition(0,100,0);
		}
		else if ( vehicle1 == obA->getUserPointer() and mapa->meta == obB->getUserPointer())
		{
			win_P1 = true;
			vehicle1 -> setPosition(0,100,0);
		}
		if (mapa->meta == obA->getUserPointer() and vehicle2 == obB->getUserPointer())
		{
			win_P2 = true;
			vehicle2 -> setPosition(0,100,0);
		}
		else if ( vehicle2 == obA->getUserPointer() and mapa->meta == obB->getUserPointer())
		{
			win_P2 = true;
			vehicle2 -> setPosition(0,100,0);
		}

    }
}

void Game::detectDebuffs()
{
	if (vehicle2->isSlowed and vehicle2 -> cdCount <= 0.01f)
	{
		vehicle2 -> isSlowed = false;
		vehicle2 -> noBrake();
	}
	else
	{
		vehicle2 -> cdCount--;
	}
	if (vehicle1->isSlowed and vehicle1 -> cdCount <= 0.01f)
	{
		vehicle1 -> isSlowed = false;
		vehicle1 -> noBrake();
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

void Game::checkCds()
{
	if (mapa->trampa_P1->cdCount>0.0f)
	{
		mapa->trampa_P1->cdCount--;	
	}
	if (mapa->trampa_P2->cdCount>0.0f)
	{
		mapa->trampa_P2->cdCount--;	
	}
	if (vehicle1 -> firerate >0.0f)
	{
		vehicle1 -> firerate--;
	}
	if (vehicle2 -> firerate >0.0f)
	{
		vehicle2 -> firerate--;
	}
}