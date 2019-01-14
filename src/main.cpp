#include "Game.hpp"
#include "SplashScreen.hpp"
#include <bits/stdc++.h>

#pragma comment(lib, "irrKlang.lib") // link with irrKlang.dll

using namespace irrklang;
using namespace std;

int g_gl_width = 1366;
int g_gl_height = 768;
GLFWwindow* g_window = NULL;

int main()
{

	SplashScreen* splash= new SplashScreen();

	splash->main_loop();

	ISoundEngine* engine = createIrrKlangDevice();
	if(!engine)	return 0;

	srand(time(NULL));
	int eleccion = rand()%3;
	Game* game = new Game();
	if (eleccion == 0)
	{
		engine->play2D("multi/bbm.ogg", true);
	}
	else if (eleccion == 1)
	{
		engine->play2D("multi/aam.ogg", true);
	}
	else 
	{
		engine->play2D("multi/idz.ogg", true);
	}
	printf("\nReglas del Juego:\n");
	printf("Player 1:\n");
	printf("Movimiento: W A S D, Disparo: F, Trampa: G, Respawn: R\n\n");
	printf("Player 2:\n");
	printf("Movimiento: UP RIGHT DOWN LEFT, Disparo: J, Trampa: K, Respawn: I\n\n");
	game -> main_loop();

	engine->drop();

	return 0;
}
