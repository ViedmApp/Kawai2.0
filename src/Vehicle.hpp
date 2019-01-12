#ifndef Vehicle_H
#define Vehicle_H
#include <bullet/btBulletDynamicsCommon.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "tools.h"
#include <GLFW/glfw3.h>
#include <GL/glew.h>
#include "GameObject.hpp"


class Vehicle: public GameObject{

protected:
    GLuint wheel_vao;
    int wheel_num_verts;
    btRaycastVehicle* vehicle;
    bool isAlive;
    float health;
    int tag;
    bool turned;
public:

    bool isSlowed = false;
    float cdCount = 0.0f;
    Vehicle(const char* path, GLuint shaderprog, btScalar masa, btVector3 startPosition,
        btQuaternion startRotation,btDiscreteDynamicsWorld* dynamicsWorld,
        const char* texture_path,int tag);
    Vehicle(const char* path, GLuint shaderprog, btScalar masa, btVector3 startPosition,
        btQuaternion startRotation,btDiscreteDynamicsWorld* dynamicsWorld, int tag);
    ~Vehicle();

    btVector3 dirr;
    void initialize();

    float getX();
    float getY();
    float getZ();
    float getHealth();
    bool getIsAlive();
    bool getBrake();
    bool getTurned();
    btRaycastVehicle* getVehicle();
    void accelerate();
    void brake();
    void reverse();
    void turnLeft();
    void turnRight();
    void updatePhysics();
    void updateTurn();
    void fire();
    void setTurned(bool turn);    //void spawn();
    //void despawn(btDiscreteDynamicsWorld *world);
    int getTag();
    void slowDown(int debuff_time);
    void setHealth(float vida);
    void setIsAlive(bool isAliv);
    void setBrake(bool brake);
    void setVehicle(btRaycastVehicle* vehicle);
    void draw(GLuint model_mat_location);

    GLuint getWheelVao();
    int getWheelNumVerts();



};

#endif
