#ifndef SplashScreen_H
#define SplashScreen_H
#include "tools.h"
#include "Camera.hpp"
#include "Vehicle.hpp"
#include "Mapa.hpp"
#include "GLDebugDrawer.hpp"
#define GL_LOG_FILE "log/gl.log"

class SplashScreen
{
	protected:
		glm::mat4 projection;
		glm::mat4 view;
		glm::mat4 projection2;
		glm::mat4 view2;
		GLuint shader_programme;
		int view_mat_location;

		int proj_mat_location;
		int model_mat_location;
		btDiscreteDynamicsWorld* dynamicsWorld;
		Camera* camara;
		Camera* camara2;
		Vehicle* vehicle1;
		Vehicle* vehicle2;

		GLDebugDrawer* debug;
		Mapa* mapa;
		GameObject* piso2;
		Camera* camara3;
		GameObject* pantalla;




	public:
		SplashScreen();
		~SplashScreen();
		void init();
		void main_loop();
};
#endif
