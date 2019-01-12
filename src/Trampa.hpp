#ifndef TRAMPA_H
#define TRAMPA_H
#include "tools.h"
#include <string>
#include "GameObject.hpp"
class Trampa: public GameObject{

protected:
	int tag;

public:
	float cdCount = 0.0f;
    Trampa(const char* path, GLuint shaderprog, btScalar masa, btVector3 startPosition,
    btQuaternion startRotation,btDiscreteDynamicsWorld* dynamicsWorld,
    const char* texture_path,int tag);
    ~Trampa();
    int getTag();
    void setCd(float cd);
};


#endif
