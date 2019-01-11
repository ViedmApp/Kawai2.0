#ifndef TRAMPA_H
#define TRAMPA_H
#include "tools.h"
#include <string>
#include "GameObject.hpp"
class Trampa: public GameObject{

protected:
	float x,y,z;
	int tag;
	int N;

public:
    Trampa(const char* path, GLuint shaderprog, btScalar masa, btVector3 startPosition,
    btQuaternion startRotation,btDiscreteDynamicsWorld* dynamicsWorld,
    const char* texture_path,float x,float y, float z,int tag);
    ~Trampa();
    void draw(GLuint model_mat_location);
    float getX();
    float getY();
    float getZ();
    int getTag();
    void setPosition(float x,float y,float z);
};


#endif
