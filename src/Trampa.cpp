#include "Trampa.hpp"
Trampa::Trampa(const char* path, GLuint shaderprog, btScalar masa, btVector3 startPosition,
    btQuaternion startRotation,btDiscreteDynamicsWorld* dynamicsWorld,
    const char* texture_path,int tag)
: GameObject(path,shaderprog,masa,startPosition,startRotation,dynamicsWorld,texture_path)
{
	this -> tag = tag;
}
Trampa::~Trampa()
{

}
