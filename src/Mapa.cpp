    #include "Mapa.hpp"

    Mapa::Mapa(btDiscreteDynamicsWorld* dynamicsWorld,GLuint shader_programme)
    {
    this -> dynamicsWorld = dynamicsWorld;
    this -> shader_programme = shader_programme;
    this -> trampa_P1 = new Trampa((char*)"mallas/box.obj",shader_programme,btScalar(0),
        btVector3(100,100,100),btQuaternion(0,1,0,sin(0)),dynamicsWorld, (char*)"textures/",1);
    this -> trampa_P2 = new Trampa((char*)"mallas/box.obj",shader_programme,btScalar(0),
        btVector3(100,100,100),btQuaternion(0,1,0,sin(0)),dynamicsWorld, (char*)"textures/pika_ae86_t.png",2);
    init();
    }
    Mapa::~Mapa()
    {

    }

void Mapa::init()
{
    srand (time(NULL));
    int map = /*rand()%2 +1;*/ 1;
    if (map == 1)
    {
        N = 31;
        int cont = 0;
        p1_Start_Position = btVector3(-3,1,90);
        p2_Start_Position = btVector3(4,1,90);
        mapa = (GameObject**)malloc(((N*3)+2)*sizeof(GameObject));
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat.obj",shader_programme,btScalar(0),
            btVector3( 0,-10,70),btQuaternion(0,1,0,sin(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_turn.obj",shader_programme,btScalar(0),
            btVector3(0,-10,15),btQuaternion(0,1,0,cos(0)),dynamicsWorld,(char*)"textures/map_track_turn_t.png");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat.obj",shader_programme,btScalar(0),
            btVector3( 55,-10,15),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat.obj",shader_programme,btScalar(0),
            btVector3( 125,-10,15),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_turn.obj",shader_programme,btScalar(0),
            btVector3(180,-10,15),btQuaternion(-2*PI,0,0),dynamicsWorld,(char*)"textures/map_track_turn_t.png");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat.obj",shader_programme,btScalar(0),
            btVector3( 180,-10,70),btQuaternion(0,1,0,sin(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_turn.obj",shader_programme,btScalar(0),  
            btVector3(180,-10,125),btQuaternion(0,1,0,sin(0)),dynamicsWorld,(char*)"textures/map_track_turn_t.png");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat.obj",shader_programme,btScalar(0),
            btVector3( 235,-10,125),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_turn.obj",shader_programme,btScalar(0),
            btVector3(290,-10,125),btQuaternion(-2*PI,0,0),dynamicsWorld,(char*)"textures/map_track_turn_t.png");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat.obj",shader_programme,btScalar(0),
            btVector3( 290,-10,180),btQuaternion(0,1,0,sin(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_turn.obj",shader_programme,btScalar(0),
            btVector3(290,-10,235),btQuaternion(3*PI/2,0,0),dynamicsWorld,(char*)"textures/map_track_turn_t.png");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat.obj",shader_programme,btScalar(0),
            btVector3( 235,-10,235),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat.obj",shader_programme,btScalar(0),
            btVector3( 180,-10,235),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat.obj",shader_programme,btScalar(0),
            btVector3( 125,-10,235),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_turn.obj",shader_programme,btScalar(0),  
            btVector3(70,-10,235),btQuaternion(0,1,0,sin(0)),dynamicsWorld,(char*)"textures/map_track_turn_t.png");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_turn.obj",shader_programme,btScalar(0),
            btVector3(70,-10,195),btQuaternion(-2*PI,0,0),dynamicsWorld,(char*)"textures/map_track_turn_t.png");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat.obj",shader_programme,btScalar(0),
            btVector3( 15,-10,195),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat.obj",shader_programme,btScalar(0),
            btVector3( -40,-10,195),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_turn.obj",shader_programme,btScalar(0),  
            btVector3(-95,-10,195),btQuaternion(0,1,0,sin(0)),dynamicsWorld,(char*)"textures/map_track_turn_t.png");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat.obj",shader_programme,btScalar(0),
            btVector3( -95,-10,140),btQuaternion(0,1,0,sin(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat.obj",shader_programme,btScalar(0),
            btVector3( -95,-10,85),btQuaternion(0,1,0,sin(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat.obj",shader_programme,btScalar(0),
            btVector3( -95,-10,30),btQuaternion(0,1,0,sin(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat.obj",shader_programme,btScalar(0),
            btVector3( -95,-10,-25),btQuaternion(0,1,0,sin(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_turn.obj",shader_programme,btScalar(0),
            btVector3(-95,-10,-80),btQuaternion(0,1,0,cos(0)),dynamicsWorld,(char*)"textures/map_track_turn_t.png");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat.obj",shader_programme,btScalar(0),
            btVector3( -40,-10,-80),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat.obj",shader_programme,btScalar(0),
            btVector3( 15,-10,-80),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat.obj",shader_programme,btScalar(0),
            btVector3( 70,-10,-80),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat.obj",shader_programme,btScalar(0),
            btVector3( 125,-10,-80),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat.obj",shader_programme,btScalar(0),
            btVector3( 180,-10,-80),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat.obj",shader_programme,btScalar(0),
            btVector3( 235,-10,-80),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat.obj",shader_programme,btScalar(0),
            btVector3( 290,-10,-80),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_R.obj",shader_programme,btScalar(0),
            btVector3( 0,-10,70),btQuaternion(0,1,0,sin(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_L.obj",shader_programme,btScalar(0),
            btVector3( 0,-10,70),btQuaternion(0,1,0,sin(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_turn_border_T.obj",shader_programme,btScalar(0),
            btVector3(0,-10,15),btQuaternion(0,1,0,cos(0)),dynamicsWorld,(char*)"textures/map_track_turn_t.png");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_turn_border_R.obj",shader_programme,btScalar(0),
            btVector3(0,-10,15),btQuaternion(0,1,0,cos(0)),dynamicsWorld,(char*)"textures/map_track_turn_t.png");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_L.obj",shader_programme,btScalar(0),
            btVector3( 55,-10,15),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_R.obj",shader_programme,btScalar(0),
            btVector3( 55,-10,15),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_L.obj",shader_programme,btScalar(0),
            btVector3( 125,-10,15),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_R.obj",shader_programme,btScalar(0),
            btVector3( 125,-10,15),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_turn_border_R.obj",shader_programme,btScalar(0),
            btVector3(180,-10,15),btQuaternion(-2*PI,0,0),dynamicsWorld,(char*)"textures/map_track_turn_t.png");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_turn_border_T.obj",shader_programme,btScalar(0),
            btVector3(180,-10,15),btQuaternion(-2*PI,0,0),dynamicsWorld,(char*)"textures/map_track_turn_t.png");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_L.obj",shader_programme,btScalar(0),
            btVector3( 180,-10,70),btQuaternion(0,1,0,sin(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_R.obj",shader_programme,btScalar(0),
            btVector3( 180,-10,70),btQuaternion(0,1,0,sin(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_turn_border_T.obj",shader_programme,btScalar(0),  
            btVector3(180,-10,125),btQuaternion(0,1,0,sin(0)),dynamicsWorld,(char*)"textures/map_track_turn_t.png");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_turn_border_R.obj",shader_programme,btScalar(0),  
            btVector3(180,-10,125),btQuaternion(0,1,0,sin(0)),dynamicsWorld,(char*)"textures/map_track_turn_t.png");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_L.obj",shader_programme,btScalar(0),
            btVector3( 235,-10,125),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_turn_border_T.obj",shader_programme,btScalar(0),
            btVector3(290,-10,125),btQuaternion(-2*PI,0,0),dynamicsWorld,(char*)"textures/map_track_turn_t.png");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_L.obj",shader_programme,btScalar(0),
            btVector3( 290,-10,180),btQuaternion(0,1,0,sin(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_turn_border_T.obj",shader_programme,btScalar(0),
            btVector3(290,-10,235),btQuaternion(3*PI/2,0,0),dynamicsWorld,(char*)"textures/map_track_turn_t.png");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_L.obj",shader_programme,btScalar(0),
            btVector3( 235,-10,235),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_L.obj",shader_programme,btScalar(0),
            btVector3( 180,-10,235),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_L.obj",shader_programme,btScalar(0),
            btVector3( 125,-10,235),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_turn_border_T.obj",shader_programme,btScalar(0),  
            btVector3(70,-10,235),btQuaternion(0,1,0,sin(0)),dynamicsWorld,(char*)"textures/map_track_turn_t.png");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_turn_border_T.obj",shader_programme,btScalar(0),
            btVector3(70,-10,195),btQuaternion(-2*PI,0,0),dynamicsWorld,(char*)"textures/map_track_turn_t.png");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_L.obj",shader_programme,btScalar(0),
            btVector3( 15,-10,195),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_L.obj",shader_programme,btScalar(0),
            btVector3( -40,-10,195),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_turn_border_T.obj",shader_programme,btScalar(0),  
            btVector3(-95,-10,195),btQuaternion(0,1,0,sin(0)),dynamicsWorld,(char*)"textures/map_track_turn_t.png");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_L.obj",shader_programme,btScalar(0),
            btVector3( -95,-10,140),btQuaternion(0,1,0,sin(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_L.obj",shader_programme,btScalar(0),
            btVector3( -95,-10,85),btQuaternion(0,1,0,sin(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_L.obj",shader_programme,btScalar(0),
            btVector3( -95,-10,30),btQuaternion(0,1,0,sin(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_L.obj",shader_programme,btScalar(0),
            btVector3( -95,-10,-25),btQuaternion(0,1,0,sin(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_turn_border_T.obj",shader_programme,btScalar(0),
            btVector3(-95,-10,-80),btQuaternion(0,1,0,cos(0)),dynamicsWorld,(char*)"textures/map_track_turn_t.png");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_L.obj",shader_programme,btScalar(0),
            btVector3( -40,-10,-80),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_L.obj",shader_programme,btScalar(0),
            btVector3( 15,-10,-80),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_L.obj",shader_programme,btScalar(0),
            btVector3( 70,-10,-80),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_L.obj",shader_programme,btScalar(0),
            btVector3( 125,-10,-80),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_L.obj",shader_programme,btScalar(0),
            btVector3( 180,-10,-80),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_L.obj",shader_programme,btScalar(0),
            btVector3( 235,-10,-80),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_L.obj",shader_programme,btScalar(0),
            btVector3( 290,-10,-80),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_R.obj",shader_programme,btScalar(0),
            btVector3( 235,-10,125),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_turn_border_R.obj",shader_programme,btScalar(0),
            btVector3(290,-10,125),btQuaternion(-2*PI,0,0),dynamicsWorld,(char*)"textures/map_track_turn_t.png");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_R.obj",shader_programme,btScalar(0),
            btVector3( 290,-10,180),btQuaternion(0,1,0,sin(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_turn_border_R.obj",shader_programme,btScalar(0),
            btVector3(290,-10,235),btQuaternion(3*PI/2,0,0),dynamicsWorld,(char*)"textures/map_track_turn_t.png");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_R.obj",shader_programme,btScalar(0),
            btVector3( 235,-10,235),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_R.obj",shader_programme,btScalar(0),
            btVector3( 180,-10,235),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_R.obj",shader_programme,btScalar(0),
            btVector3( 125,-10,235),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_turn_border_R.obj",shader_programme,btScalar(0),  
            btVector3(70,-10,235),btQuaternion(0,1,0,sin(0)),dynamicsWorld,(char*)"textures/map_track_turn_t.png");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_turn_border_R.obj",shader_programme,btScalar(0),
            btVector3(70,-10,195),btQuaternion(-2*PI,0,0),dynamicsWorld,(char*)"textures/map_track_turn_t.png");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_R.obj",shader_programme,btScalar(0),
            btVector3( 15,-10,195),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_R.obj",shader_programme,btScalar(0),
            btVector3( -40,-10,195),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_turn_border_R.obj",shader_programme,btScalar(0),  
            btVector3(-95,-10,195),btQuaternion(0,1,0,sin(0)),dynamicsWorld,(char*)"textures/map_track_turn_t.png");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_R.obj",shader_programme,btScalar(0),
            btVector3( -95,-10,140),btQuaternion(0,1,0,sin(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_R.obj",shader_programme,btScalar(0),
            btVector3( -95,-10,85),btQuaternion(0,1,0,sin(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_R.obj",shader_programme,btScalar(0),
            btVector3( -95,-10,30),btQuaternion(0,1,0,sin(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_R.obj",shader_programme,btScalar(0),
            btVector3( -95,-10,-25),btQuaternion(0,1,0,sin(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_turn_border_R.obj",shader_programme,btScalar(0),
            btVector3(-95,-10,-80),btQuaternion(0,1,0,cos(0)),dynamicsWorld,(char*)"textures/map_track_turn_t.png");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_R.obj",shader_programme,btScalar(0),
            btVector3( -40,-10,-80),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_R.obj",shader_programme,btScalar(0),
            btVector3( 15,-10,-80),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_R.obj",shader_programme,btScalar(0),
            btVector3( 70,-10,-80),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_R.obj",shader_programme,btScalar(0),
            btVector3( 125,-10,-80),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_R.obj",shader_programme,btScalar(0),
            btVector3( 180,-10,-80),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_R.obj",shader_programme,btScalar(0),
            btVector3( 235,-10,-80),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_R.obj",shader_programme,btScalar(0),
            btVector3( 290,-10,-80),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");

    }
    /*else if (map == 2)
    {
        N = 12;
        int cont = 0;
        p1_Start_Position = btVector3(-3,1,90);
        p2_Start_Position = btVector3(4,1,90);
        mapa = (GameObject**)malloc(((N*3)+2)*sizeof(GameObject));
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat.obj",shader_programme,btScalar(0),
            btVector3( 0,-10,70),btQuaternion(0,1,0,sin(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_turn.obj",shader_programme,btScalar(0),
            btVector3(0,-10,15),btQuaternion(-2*PI,0,0),dynamicsWorld,(char*)"textures/map_track_turn_t.png");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat.obj",shader_programme,btScalar(0),
            btVector3( -55,-10,15),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat.obj",shader_programme,btScalar(0),
            btVector3( 125,-10,15),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_turn.obj",shader_programme,btScalar(0),
            btVector3(180,-10,15),btQuaternion(-2*PI,0,0),dynamicsWorld,(char*)"textures/map_track_turn_t.png");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat.obj",shader_programme,btScalar(0),
            btVector3( 180,-10,70),btQuaternion(0,1,0,sin(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_turn.obj",shader_programme,btScalar(0),
            btVector3(180,-10,125),btQuaternion(0,1,0,sin(0)),dynamicsWorld,(char*)"textures/map_track_turn_t.png");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat.obj",shader_programme,btScalar(0),
            btVector3( 235,-10,125),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_turn.obj",shader_programme,btScalar(0),
            btVector3(290,-10,125),btQuaternion(-2*PI,0,0),dynamicsWorld,(char*)"textures/map_track_turn_t.png");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat.obj",shader_programme,btScalar(0),
            btVector3( 290,-10,180),btQuaternion(0,1,0,sin(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_turn.obj",shader_programme,btScalar(0),
            btVector3(290,-10,235),btQuaternion(3*PI/2,0,0),dynamicsWorld,(char*)"textures/map_track_turn_t.png");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat.obj",shader_programme,btScalar(0),
            btVector3( 235,-10,235),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
    }*/
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
        this->trampa_P1 -> setCd(2);
    }
    
    if (tag == 2)
    {
        this->trampa_P2 -> setPosition(x,y,z);
        this->trampa_P2_exists = true;
        this->trampa_P2 -> setCd(2);
    }
}
