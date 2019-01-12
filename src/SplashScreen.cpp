#include "SplashScreen.hpp"
using namespace irrklang;
//ISoundEngine *SoundEngine = createIrrKlangDevice();

SplashScreen::SplashScreen()
{
	init();

}

SplashScreen::~SplashScreen()
{

}

void SplashScreen::init()
{



	glm::vec3 cameraPos   = glm::vec3(0.0f, 0.0f, -0.0f);
	glm::vec3 cameraFront = glm::vec3(0.0f, -1.0f, -1.0f);
	glm::vec3 cameraLook = glm::vec3(0.0f,0.0f,0.0f);
	glm::vec3 cameraUp    = glm::vec3(0.0f, -1.0f, 0.0f);

//	SoundEngine->play2D("multi/encendido_auto.ogg",GL_FALSE);





	bool firstMouse = true;
	float yaw   = -90.0f;
	float pitch =  0.0f;
	float lastX =  g_gl_width / 2.0;
	float lastY =  g_gl_height / 2.0;
	float fov   =  45.0f;

	this->camara=new Camera(cameraPos,cameraFront,cameraUp,fov,pitch,yaw,g_gl_width,g_gl_height);




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
	this->pantalla= new GameObject((char*)"mallas/menu.obj",shader_programme,btScalar(0),
			btVector3(0,0,0),btQuaternion(0,1,0,0),dynamicsWorld, (char*)"mallas/background.png");
	this->debug = new GLDebugDrawer();


	debug->setDebugMode(btIDebugDraw::DBG_DrawWireframe );
	debug->setView(&view);
	debug->setProj(&projection);
	dynamicsWorld->setDebugDrawer(debug);


}


void SplashScreen::main_loop()
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
        dynamicsWorld->stepSimulation(1.f / 60.f, 10);

        glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glUseProgram (shader_programme);

		glViewport (0, 0, g_gl_width, g_gl_height);
        projection = camara->getPerspectiva();
        glUniformMatrix4fv (proj_mat_location, 1, GL_FALSE, &projection[0][0]);
        view = camara->getViewMatrix();
        glUniformMatrix4fv(view_mat_location, 1, GL_FALSE, &view[0][0]);

				pantalla->draw(model_mat_location);
				if (glfwGetKey(g_window, GLFW_KEY_ENTER) == GLFW_PRESS)
						glfwSetWindowShouldClose(g_window, true);

    	/*debug->setView(&view);
		debug->setProj(&projection);
		dynamicsWorld->debugDrawWorld();
		debug->drawLines();*/


        glfwSwapBuffers(g_window);
        glfwPollEvents();

	}

	glfwTerminate();
}
