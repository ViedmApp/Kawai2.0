#include "Game.hpp"

#pragma comment(lib, "irrKlang.lib") // link with irrKlang.dll

using namespace irrklang;


int g_gl_width = 1366;
int g_gl_height = 768;
GLFWwindow* g_window = NULL;

int main()
{


	Game* game = new Game();

	//ISoundEngine* engine = createIrrKlangDevice();

	//if(!engine)	return 0;
	
	//engine->play2D("multi/7. Run.wav", true);
	
	game -> main_loop();
	
	//engine->drop();

	return 0;
}

