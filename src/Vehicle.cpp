#include "Vehicle.hpp"


Vehicle::Vehicle(const char* path, GLuint shaderprog, btScalar masa, btVector3 startPosition,
    btQuaternion startRotation,btDiscreteDynamicsWorld* dynamicsWorld,
    const char* texture_path)
: GameObject(path,shaderprog,masa,startPosition,startRotation,dynamicsWorld,texture_path)
{
    initialize();
    assert(load_mesh((char*)"mallas/tire_20.obj",this -> wheel_vao,this -> wheel_num_verts));
}

Vehicle::Vehicle(const char* path, GLuint shaderprog, btScalar masa, btVector3 startPosition,
    btQuaternion startRotation,btDiscreteDynamicsWorld* dynamicsWorld)
: GameObject(path,shaderprog,masa,startPosition,startRotation,dynamicsWorld)
{
    initialize();
    assert(load_mesh((char*)"mallas/tire_20.obj",this -> wheel_vao,this -> wheel_num_verts));
}



Vehicle::~Vehicle(){}

void Vehicle::initialize()
{
    btRaycastVehicle::btVehicleTuning *tuning = new btRaycastVehicle::btVehicleTuning();
    btVehicleRaycaster *defvehicle = new btDefaultVehicleRaycaster(this->getWorld());
    this -> getRigidBody()->setActivationState(DISABLE_DEACTIVATION);
    this -> getRigidBody()->setUserPointer(this);
    this -> setVehicle(new btRaycastVehicle(*tuning, this->getRigidBody(), defvehicle));
    this -> getVehicle()->setCoordinateSystem(0, 1, 2);

    this -> getWorld() -> addAction(this -> getVehicle());

    btVector3 wheelDirection(0.0f, -1.0f, 0.0f);
    btVector3 wheelAxis(-1.0f, 0.0f, 0.0f);
    btScalar suspensionRestLength(0.2f);                                                                                                                 //TODO: PARAM
    btScalar wheelRadius(0.790165f);

    this -> getVehicle() -> addWheel(btVector3(-1.45459f, -0.777563f,2.2f), wheelDirection, wheelAxis, suspensionRestLength, wheelRadius, *tuning, false);  //TODO: PARAM
    this -> getVehicle() -> addWheel(btVector3(1.45459f, -0.777563, 2.2f), wheelDirection, wheelAxis, suspensionRestLength, wheelRadius, *tuning, false); //TODO: PARAM

                                                                                                                        //TOCO: PARAM
    this -> getVehicle() -> addWheel(btVector3(-1.45459f, -0.777563, -2.87147), wheelDirection, wheelAxis, suspensionRestLength, wheelRadius, *tuning, true);   //TODO: PARAM
    this -> getVehicle() -> addWheel(btVector3(1.45459, -0.777563,-2.827147f), wheelDirection, wheelAxis, suspensionRestLength, wheelRadius, *tuning, true);    //TODO: PARAM


    for (int i = 0; i < this -> getVehicle()-> getNumWheels(); i++)
    {
        btWheelInfo &wheel = this -> getVehicle() -> getWheelInfo(i);
        //wheel.m_wheelsDampingRelaxation = 1.7f;    //TODO: PARAM
        //wheel.m_wheelsDampingCompression = -1.7f;   //TODO: PARAM
        wheel.m_frictionSlip = btScalar(10000.); //TODO: PARAM
        wheel.m_rollInfluence = btScalar(0.f);   //TODO: PARAM
        wheel.m_maxSuspensionTravelCm = 150.f;   //TODO: PARAM
    }
    setIsAlive(true);

  }



float Vehicle::getHealth(){
    return this->health;
}

bool Vehicle::getIsAlive(){
    return this->isAlive;
}

btRaycastVehicle* Vehicle::getVehicle(){
    return this->vehicle;
}


void Vehicle::setHealth(float vida){
    this->health = vida;
}

void Vehicle::setIsAlive(bool isAliv){
    this->isAlive = isAliv;
}

void Vehicle::setVehicle(btRaycastVehicle* vehicle){
    this->vehicle = vehicle;
}

void Vehicle::accelerate()
{
 if (vehicle->getCurrentSpeedKmHour() < 150.f)    {
        this->vehicle->applyEngineForce(40.f, 0); //TODO: Param
        this->vehicle->applyEngineForce(40.f, 1);
    }
}
void Vehicle::brake()
{
    this->vehicle->setBrake(btScalar(1.15), 0); //TODO: PARAM
    this->vehicle->setBrake(btScalar(1.15), 1); //TODO: PARAM
    this->vehicle->setBrake(btScalar(1.15), 2); //TODO: PARAM
    this->vehicle->setBrake(btScalar(1.15), 3); //TODO: PARAM

}
void Vehicle::reverse()
{
    //TODO: ADD LIMIT
    this->vehicle->applyEngineForce(-50, 0); //TODO: Param
    this->vehicle->applyEngineForce(-50, 1); //TODO:
}

void Vehicle::turnRight()
{
    if (this->vehicle->getSteeringValue(0) > -0.4f && this->vehicle->getSteeringValue(1) > -0.4f)
    {
        this->vehicle->setSteeringValue(this->vehicle->getSteeringValue(0) - 0.02f, 0); //TODO: Param
        this->vehicle->setSteeringValue(this->vehicle->getSteeringValue(1) - 0.02f, 1); //TODO: PARAM
    }
    setTurned(true);
}
void Vehicle::turnLeft()
{
    if (this->vehicle->getSteeringValue(0) < 0.4f && this->vehicle->getSteeringValue(1) < 0.4f)
    {
        this->vehicle->setSteeringValue(this->vehicle->getSteeringValue(0) + 0.02f, 0); //TODO: PARAM
        this->vehicle->setSteeringValue(this->vehicle->getSteeringValue(1) + 0.02f, 1); //TODO: PARAM
    }
    setTurned(true);
}

bool Vehicle::getTurned(){
    return this->turned;
}

void Vehicle::setTurned(bool turn){
    this->turned = turn;
}


void Vehicle::updatePhysics()
{

    this->getVehicle()->applyEngineForce(0, 0); //TODO: Param
    this->getVehicle()->applyEngineForce(0, 1);
}

void Vehicle::updateTurn()
{
     if (!this -> getTurned())
    {
        if (this -> getVehicle()->getSteeringValue(0) > 0)
        {
            this -> getVehicle()->setSteeringValue(getVehicle()->getSteeringValue(0) - 0.030f, 0); //TODO: PARAM
            this -> getVehicle()->setSteeringValue(getVehicle()->getSteeringValue(1) - 0.030f, 1); //TODO: PARAM
            if (this -> getVehicle()->getSteeringValue(0) < 0)
            {
                this -> getVehicle()->setSteeringValue(0, 0);
                this -> getVehicle()->setSteeringValue(0, 1);
            }
        }
        else if (this -> getVehicle()->getSteeringValue(0) < 0)
        {
            this -> getVehicle()->setSteeringValue(getVehicle()->getSteeringValue(0) + 0.03f, 0); //TODO: PARAM
            this -> getVehicle()->setSteeringValue(getVehicle()->getSteeringValue(1) + 0.03f, 1); //TODO: PARAM
            if (this -> getVehicle()->getSteeringValue(0) > 0)
            {
                this -> getVehicle()->setSteeringValue(0, 0);
                this -> getVehicle()->setSteeringValue(0, 1);
            }
        }
    }
    else
    {
        this -> setTurned(false);
    }
}

GLuint Vehicle::getWheelVao()
{
    return this -> wheel_vao;
}

int Vehicle::getWheelNumVerts()
{
    return this -> wheel_num_verts;
}

float Vehicle::getX()
{
    btTransform trans;
    this -> getRigidBody()->getMotionState()->getWorldTransform(trans);
    return trans.getOrigin()[0];
}

float Vehicle::getY()
{
    btTransform trans;
    this -> getRigidBody()->getMotionState()->getWorldTransform(trans);
    return trans.getOrigin()[1];
}

float Vehicle::getZ()
{
    btTransform trans;
    this -> getRigidBody()->getMotionState()->getWorldTransform(trans);
    return trans.getOrigin()[2];
}



void Vehicle::draw(GLuint model_mat_location)
{
    btTransform trans;
    this -> getRigidBody()->getMotionState()->getWorldTransform(trans);
    trans.getOpenGLMatrix(&model[0][0]);
    this -> setModelMatrix(this->model);
    glUniformMatrix4fv(model_mat_location, 1, GL_FALSE, &modelMatrix[0][0]);
    
        glActiveTexture (GL_TEXTURE0);
	glBindTexture (GL_TEXTURE_2D, this->texture);
    glUniform1i (tex_location, 0);
    
    glActiveTexture (GL_TEXTURE1);
	glBindTexture (GL_TEXTURE_2D, this->normalMap);
    //glUniform1i (normalMapLocation, 1);
    
    glBindVertexArray(this->getVao());
    glDrawArrays(GL_TRIANGLES, 0, this -> getNumVertices());
    for (int i = 0; i < this -> getVehicle() -> getNumWheels(); i++)
    {
        trans = this->getVehicle()->getWheelInfo(i).m_worldTransform;
        trans.getOpenGLMatrix(&model[0][0]);
        this -> setModelMatrix(this->model);
        glUniformMatrix4fv(model_mat_location, 1, GL_FALSE, &this->modelMatrix[0][0]);
        glBindVertexArray(this->getWheelVao());
        glDrawArrays(GL_TRIANGLES, 0, this->getWheelNumVerts());
    }
}
