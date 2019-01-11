#include "Trampa.hpp"
Trampa::Trampa(const char* path, GLuint shaderprog, btScalar masa, btVector3 startPosition,
    btQuaternion startRotation,btDiscreteDynamicsWorld* dynamicsWorld,
    const char* texture_path,float x,float y, float z,int tag)
: GameObject(path,shaderprog,masa,startPosition,startRotation,dynamicsWorld,texture_path)
{
	this -> x = x;
	this -> y = y;
	this -> z = z;
	this -> tag = tag;
}
Trampa::~Trampa()
{

}

void Trampa::setPosition(float x,float y,float z)
{
	this -> x = x;
	this -> y = y;
	this -> z = z;
	btVector3 position(x,y,z);
	btTransform aux;
	aux.setIdentity();
	aux.setOrigin(position);
	btDefaultMotionState* state = new btDefaultMotionState(aux);
	this -> getRigidBody() -> setMotionState(state);
}

float Trampa::getX()
{
	return x;
}
float Trampa::getY()
{
	return y;
}
float Trampa::getZ()
{
	return z;
}
