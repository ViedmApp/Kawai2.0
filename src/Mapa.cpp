    #include "Mapa.hpp"

    Mapa::Mapa(btDiscreteDynamicsWorld* dynamicsWorld,GLuint shader_programme)
    {
    this -> dynamicsWorld = dynamicsWorld;
    this -> shader_programme = shader_programme;
    this -> trampa_P1 = new Trampa((char*)"mallas/ball.obj",shader_programme,btScalar(0),
        btVector3(100,100,100),btQuaternion(0,1,0,sin(0)),dynamicsWorld, (char*)"textures/map_track_flat_border_t.png",100,100,100,1);
    this -> trampa_P2 = new Trampa((char*)"mallas/ball.obj",shader_programme,btScalar(0),
        btVector3(100,100,100),btQuaternion(0,1,0,sin(0)),dynamicsWorld, (char*)"textures/map_track_flat_border_t.png",100,100,100,2);
    init();
    }
    Mapa::~Mapa()
    {

    }

void Mapa::init()
{
    N = 24;
    int cont = 0;
    p1_Start_Position = btVector3(80,1,170);
    p2_Start_Position = btVector3(4,1,70);
    mapa = (GameObject**)malloc((N)*sizeof(GameObject));
    mapa[cont++] = new GameObject((char*)"mallas/map_track_turn.obj",shader_programme,btScalar(0),
        btVector3(0,-10,10),btQuaternion(0,1,0,cos(0)),dynamicsWorld,(char*)"textures/map_track_turn_t.png");
    mapa[cont++] = new GameObject((char*)"mallas/map_track_turn_border_T.obj",shader_programme,btScalar(0),
        btVector3(0,-10,10),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_border_t.png");
    mapa[cont++] = new GameObject((char*)"mallas/map_track_turn_border_R.obj",shader_programme,btScalar(0),
        btVector3(0,-10,10),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_border_t.png");
    mapa[cont++] = new GameObject((char*)"mallas/map_track_flat.obj",shader_programme,btScalar(0),
        btVector3( 80,-10,10),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.png");
    mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_L.obj",shader_programme,btScalar(0),
        btVector3( 80,-10,10),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_border_t.png");
    mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_R.obj",shader_programme,btScalar(0),
        btVector3( 80,-10,10),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_border_t.png");
    mapa[cont++] = new GameObject((char*)"mallas/map_track_flat.obj",shader_programme,btScalar(0),
        btVector3(0,-10,90),btQuaternion(0,1,0,sin(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.png");
    mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_L.obj",shader_programme,btScalar(0),
        btVector3(0,-10,90),btQuaternion(0,1,0,sin(0)),dynamicsWorld, (char*)"textures/map_track_flat_border_t.png");
    mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_R.obj",shader_programme,btScalar(0),
        btVector3(0,-10,90),btQuaternion(0,1,0,sin(0)),dynamicsWorld, (char*)"textures/map_track_flat_border_t.png");
    mapa[cont++] = new GameObject((char*)"mallas/map_track_turn.obj",shader_programme,btScalar(0),
        btVector3(0,-10,170),btQuaternion(0,1,0,sin(0)),dynamicsWorld,(char*)"textures/map_track_turn_t.png");
    mapa[cont++] = new GameObject((char*)"mallas/map_track_turn_border_T.obj",shader_programme,btScalar(0),
        btVector3(0,-10,170),btQuaternion(0,1,0,sin(0)),dynamicsWorld, (char*)"textures/map_track_flat_border_t.png");
    mapa[cont++] = new GameObject((char*)"mallas/map_track_turn_border_R.obj",shader_programme,btScalar(0),
        btVector3(0,-10,170),btQuaternion(0,1,0,sin(0)),dynamicsWorld, (char*)"textures/map_track_flat_border_t.png");
    mapa[cont++] = new GameObject((char*)"mallas/map_track_flat.obj",shader_programme,btScalar(0),
        btVector3( 80,-10,170),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.png");
    mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_L.obj",shader_programme,btScalar(0),
        btVector3( 80,-10,170),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_border_t.png");
    mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_R.obj",shader_programme,btScalar(0),
        btVector3( 80,-10,170),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_border_t.png");
    mapa[cont++] = new GameObject((char*)"mallas/map_track_turn.obj",shader_programme,btScalar(0),
        btVector3(160,-10,170),btQuaternion(3*PI/2,0,0),dynamicsWorld,(char*)"textures/map_track_turn_t.png");
    mapa[cont++] = new GameObject((char*)"mallas/map_track_turn_border_T.obj",shader_programme,btScalar(0),
        btVector3(160,-10,170),btQuaternion(3*PI/2,0,0),dynamicsWorld, (char*)"textures/map_track_flat_border_t.png");
    mapa[cont++] = new GameObject((char*)"mallas/map_track_turn_border_R.obj",shader_programme,btScalar(0),
        btVector3(160,-10,170),btQuaternion(3*PI/2,0,0),dynamicsWorld, (char*)"textures/map_track_flat_border_t.png");
    mapa[cont++] = new GameObject((char*)"mallas/map_track_turn.obj",shader_programme,btScalar(0),
        btVector3(160,-10,10),btQuaternion(-2*PI,0,0),dynamicsWorld,(char*)"textures/map_track_turn_t.png");
    mapa[cont++] = new GameObject((char*)"mallas/map_track_turn_border_T.obj",shader_programme,btScalar(0),
        btVector3(160,-10,10),btQuaternion(-2*PI,0,0),dynamicsWorld, (char*)"textures/map_track_flat_border_t.png");
    mapa[cont++] = new GameObject((char*)"mallas/map_track_turn_border_R.obj",shader_programme,btScalar(0),
        btVector3(160,-10,10),btQuaternion(-2*PI,0,0),dynamicsWorld, (char*)"textures/map_track_flat_border_t.png");
    mapa[cont++] = new GameObject((char*)"mallas/map_track_flat.obj",shader_programme,btScalar(0),
        btVector3(160,-10,90),btQuaternion(0,1,0,sin(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.png");
    mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_L.obj",shader_programme,btScalar(0),
        btVector3(160,-10,90),btQuaternion(0,1,0,sin(0)),dynamicsWorld, (char*)"textures/map_track_flat_border_t.png");
    mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_R.obj",shader_programme,btScalar(0),
        btVector3(160,-10,90),btQuaternion(0,1,0,sin(0)),dynamicsWorld, (char*)"textures/map_track_flat_border_t.png");

}

btVector3 Mapa::getP1StartPosition()
{
    return p1_Start_Position;
}

btVector3 Mapa::getP2StartPosition()
{
    return p2_Start_Position;
}

void Mapa::draw(GLuint model_mat_location)
{
    for (int i = 0; i < N; ++i)
    {
        btTransform trans;
        mapa[i]->getRigidBody()->getMotionState()->getWorldTransform(trans);
        trans.getOpenGLMatrix(&mapa[i]->model[0][0]);
        mapa[i]->setModelMatrix(mapa[i]->model);
        glUniformMatrix4fv(model_mat_location, 1, GL_FALSE, &mapa[i]->modelMatrix[0][0]);
        
        glActiveTexture (GL_TEXTURE0);
    	glBindTexture (GL_TEXTURE_2D, mapa[i]->texture);
        glUniform1i (mapa[i]->tex_location, 0);
        
        glActiveTexture (GL_TEXTURE1);
    	glBindTexture (GL_TEXTURE_2D, mapa[i]->normalMap);
        //glUniform1i (normalMapLocation, 1);
        
        glBindVertexArray(mapa[i]->getVao());
        glDrawArrays(GL_TRIANGLES, 0, mapa[i]->getNumVertices());
    }
    if (trampa_P1_exists)
    {
        btTransform trans;
        trampa_P1->getRigidBody()->getMotionState()->getWorldTransform(trans);
        trans.getOpenGLMatrix(&trampa_P1->model[0][0]);
        trampa_P1->setModelMatrix(trampa_P1->model);
        glUniformMatrix4fv(model_mat_location, 1, GL_FALSE, &trampa_P1->modelMatrix[0][0]);
        
        glActiveTexture (GL_TEXTURE0);
        glBindTexture (GL_TEXTURE_2D, trampa_P1->texture);
        glUniform1i (trampa_P1->tex_location, 0);
        
        glActiveTexture (GL_TEXTURE1);
        glBindTexture (GL_TEXTURE_2D, trampa_P1->normalMap);
        //glUniform1i (normalMapLocation, 1);
        
        glBindVertexArray(trampa_P1->getVao());
        glDrawArrays(GL_TRIANGLES, 0, trampa_P1->getNumVertices());
    }
    if (trampa_P2_exists)
    {
        btTransform trans;
        trampa_P2->getRigidBody()->getMotionState()->getWorldTransform(trans);
        trans.getOpenGLMatrix(&trampa_P2->model[0][0]);
        trampa_P2->setModelMatrix(trampa_P2->model);
        glUniformMatrix4fv(model_mat_location, 1, GL_FALSE, &trampa_P2->modelMatrix[0][0]);
        
        glActiveTexture (GL_TEXTURE0);
        glBindTexture (GL_TEXTURE_2D, trampa_P2->texture);
        glUniform1i (trampa_P2->tex_location, 0);
        
        glActiveTexture (GL_TEXTURE1);
        glBindTexture (GL_TEXTURE_2D, trampa_P2->normalMap);
        //glUniform1i (normalMapLocation, 1);
        
        glBindVertexArray(trampa_P2->getVao());
        glDrawArrays(GL_TRIANGLES, 0, trampa_P2->getNumVertices());
    }
}
void Mapa::crearTrampa(float x, float y, float z, int tag)
{
    if (tag == 1)
    {
        this->trampa_P1 -> setPosition(x,y,z);
        this->trampa_P1_exists = true;
    }
    
    if (tag == 2)
    {
        this->trampa_P2 -> setPosition(x,y,z);
        this->trampa_P2_exists = true;
    }
}
