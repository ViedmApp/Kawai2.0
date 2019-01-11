#ifndef MAPA_H
#define MAPA_H
#include "tools.h"
#include "GameObject.hpp"
#include "Trampa.hpp"

class Mapa{

protected:
	btVector3 p1_Start_Position;
	btVector3 p2_Start_Position;
	GameObject** mapa;
	Trampa *trampa_P1;
	Trampa *trampa_P2;
	bool trampa_P1_exists = false;
	bool trampa_P2_exists = false;
	btDiscreteDynamicsWorld* dynamicsWorld;
	GLuint shader_programme;
	void init();
	int N;

public:
    Mapa(btDiscreteDynamicsWorld* dynamicsWorld,GLuint shader_programme);
    ~Mapa();
    btVector3 checkpoints[8];
    void draw(GLuint model_mat_location);
    btVector3 getP1StartPosition();
    btVector3 getP2StartPosition();
    void crearTrampa(float x, float y, float z, int tag);


};


#endif
