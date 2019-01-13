#include "Vehicle.hpp"


Vehicle::Vehicle(const char* path, GLuint shaderprog, btScalar masa, btVector3 startPosition,
    btQuaternion startRotation,btDiscreteDynamicsWorld* dynamicsWorld,
    const char* texture_path, int tag)
: GameObject(path,shaderprog,masa,startPosition,startRotation,dynamicsWorld,texture_path)
{
    initialize();
    this -> tag = tag;
    assert(load_mesh((char*)"mallas/tire_20.obj",this -> wheel_vao,this -> wheel_num_verts));
    this->bala= new GameObject((char*)"mallas/ball.obj",shader_programme,btScalar(3.2),
btVector3(100,100,100),btQuaternion(0,1,0,0),world, (char*)"textures/metalestrella.png");
}

Vehicle::Vehicle(const char* path, GLuint shaderprog, btScalar masa, btVector3 startPosition,
    btQuaternion startRotation,btDiscreteDynamicsWorld* dynamicsWorld,int tag)
: GameObject(path,shaderprog,masa,startPosition,startRotation,dynamicsWorld)
{
    initialize();
    this -> tag = tag;
    assert(load_mesh((char*)"mallas/tire_20.obj",this -> wheel_vao,this -> wheel_num_verts));
}



Vehicle::~Vehicle(){}

void Vehicle::initialize()
{
    btRaycastVehicle::btVehicleTuning *tuning = new btRaycastVehicle::btVehicleTuning();
    btVehicleRaycaster *defvehicle = new btDefaultVehicleRaycaster(this->getWorld());
    this -> getRigidBody()->setActivationState(DISABLE_DEACTIVATION);
    this -> setVehicle(new btRaycastVehicle(*tuning, this->getRigidBody(), defvehicle));
    this -> getVehicle()->setCoordinateSystem(0, 1, 2);

    this -> getWorld() -> addAction(this -> getVehicle());

    btVector3 wheelDirection(0.0f, -1.0f, 0.0f);
    btVector3 wheelAxis(-1.0f, 0.0f, 0.0f);
    btScalar suspensionRestLength(0.2f);                                                                                                                 //TODO: PARAM
    btScalar wheelRadius(0.790165f);

    this -> getVehicle() -> addWheel(btVector3(-1.31f, -1.f,2.2f), wheelDirection, wheelAxis, suspensionRestLength, wheelRadius, *tuning, false);  //TODO: PARAM
    this -> getVehicle() -> addWheel(btVector3(1.31f, -1.f, 2.2f), wheelDirection, wheelAxis, suspensionRestLength, wheelRadius, *tuning, false); //TODO: PARAM

                                                                                                                        //TOCO: PARAM
    this -> getVehicle() -> addWheel(btVector3(-1.36640f, -1, -3.f), wheelDirection, wheelAxis, suspensionRestLength, wheelRadius, *tuning, true);   //TODO: PARAM
    this -> getVehicle() -> addWheel(btVector3(1.36640, -1,-3.f), wheelDirection, wheelAxis, suspensionRestLength, wheelRadius, *tuning, true);    //TODO: PARAM


    for (int i = 0; i < this -> getVehicle()-> getNumWheels(); i++)
    {
        btWheelInfo &wheel = this -> getVehicle() -> getWheelInfo(i);
        wheel.m_wheelsDampingRelaxation = 2.5f;    //TODO: PARAM
        wheel.m_wheelsDampingCompression = 2.8f;   //TODO: PARAM
        wheel.m_suspensionStiffness = 8.88f;
        wheel.m_frictionSlip = btScalar(1500); //TODO: PARAM
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
 if (vehicle->getCurrentSpeedKmHour() < 120.f)    {
        this->vehicle->applyEngineForce(60.f, 0); //TODO: Param
        this->vehicle->applyEngineForce(60.f, 1);
    }
}
void Vehicle::brake()
{
    this->vehicle->setBrake(btScalar(3), 0); //TODO: PARAM
    this->vehicle->setBrake(btScalar(3), 1); //TODO: PARAM
    this->vehicle->setBrake(btScalar(3), 2); //TODO: PARAM
    this->vehicle->setBrake(btScalar(3), 3); //TODO: PARAM

}

void Vehicle::noBrake()
{
    this->vehicle->setBrake(btScalar(0), 0); //TODO: PARAM
    this->vehicle->setBrake(btScalar(0), 1); //TODO: PARAM
    this->vehicle->setBrake(btScalar(0), 2); //TODO: PARAM
    this->vehicle->setBrake(btScalar(0), 3); //TODO: PARAM
}
void Vehicle::reverse()
{
    //TODO: ADD LIMIT
    this->vehicle->applyEngineForce(-50, 0); //TODO: Param
    this->vehicle->applyEngineForce(-50, 1); //TODO:
}

void Vehicle::slowDown(float debuff_time)
{
    this -> isSlowed = true;
    this->vehicle->applyEngineForce(-5000, 0); //TODO: Param
    this->vehicle->applyEngineForce(-5000, 1); //TODO:
    this -> cdCount = 60.0f * debuff_time + cdCount;
}

void Vehicle::turnRight()
{
    if (this->vehicle->getSteeringValue(0) > -0.45f && this->vehicle->getSteeringValue(1) > -0.45f)
    {
        this->vehicle->setSteeringValue(this->vehicle->getSteeringValue(0) - 0.02f, 0); //TODO: Param
        this->vehicle->setSteeringValue(this->vehicle->getSteeringValue(1) - 0.02f, 1); //TODO: PARAM
    }
    setTurned(true);
}
void Vehicle::turnLeft()
{
    if (this->vehicle->getSteeringValue(0) < 0.45f && this->vehicle->getSteeringValue(1) < 0.45f)
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

int Vehicle::getTag()
{
    return this->tag;
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
    btVector3 valores = this->getRigidBody()->getCenterOfMassPosition() - (this->getRigidBody()->getLinearVelocity().normalized() *6);
    this -> getRigidBody()->getMotionState()->getWorldTransform(trans);
    return valores[0];
}

float Vehicle::getY()
{
    btTransform trans;
    btVector3 valores = this->getRigidBody()->getCenterOfMassPosition() - (this->getRigidBody()->getLinearVelocity().normalized() *6);
    this -> getRigidBody()->getMotionState()->getWorldTransform(trans);
    return valores[1];
}

float Vehicle::getZ()
{
    btTransform trans;
    btVector3 valores = this->getRigidBody()->getCenterOfMassPosition() - (this->getRigidBody()->getLinearVelocity().normalized() *6);
    this -> getRigidBody()->getMotionState()->getWorldTransform(trans);
    return valores[2];
}
void Vehicle::shootBullet(){

        existBala = true;
        bool en_movimiento = this->getRigidBody()->getLinearVelocity().norm() > 0.01;


        if (en_movimiento){
            btVector3 valores = this->getRigidBody()->getCenterOfMassPosition() + (this->getRigidBody()->getLinearVelocity().normalized() *4);
            bala -> setPosition(valores[0],valores[1],valores[2]);
        }
        else {
            btVector3 valores = this->getRigidBody()->getCenterOfMassPosition() + btVector3(1.5 ,0,0);
            bala -> setPosition(valores[0],valores[1],valores[2]);

        }


        if (en_movimiento)
            bala->getRigidBody()->setLinearVelocity(100 * this->getRigidBody()->getLinearVelocity().normalized());
        else
            bala->getRigidBody()->setLinearVelocity(btVector3(35, 0, 0));

        bala->getRigidBody()->setGravity(btVector3(0,0,0));
        firerate = 60.0f * 1.5f;
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
