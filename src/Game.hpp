#ifndef GAME_H
#define GAME_H
#include "tools.h"
#include "Camera.hpp"
#include "Vehicle.hpp"
#include "Input.hpp"
#include "Mapa.hpp"
#include "GLDebugDrawer.hpp"
#define GL_LOG_FILE "log/gl.log"
#define VERTEX_SHADER_FILE "shaders/test_vs.glsl"
#define FRAGMENT_SHADER_FILE "shaders/test_fs.glsl"

class Game
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
		Input* input;
		GLDebugDrawer* debug;
		Mapa* mapa;


		

	public:
		Game();
		~Game();
		void init();
		void main_loop();
};
#endif