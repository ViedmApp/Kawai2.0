    #include "Mapa.hpp"

    Mapa::Mapa(btDiscreteDynamicsWorld* dynamicsWorld,GLuint shader_programme)
    {
    printf("Cargandoo Mapa...\n");
    this -> dynamicsWorld = dynamicsWorld;
    this -> shader_programme = shader_programme;
    this -> trampa_P1 = new Trampa((char*)"mallas/box.obj",shader_programme,btScalar(0),
        btVector3(1000,-100,1000),btQuaternion(0,1,0,sin(0)),dynamicsWorld, (char*)"textures/metalestrella.png",1);
    this -> trampa_P2 = new Trampa((char*)"mallas/box.obj",shader_programme,btScalar(0),
        btVector3(1000,-100,1000),btQuaternion(0,1,0,sin(0)),dynamicsWorld, (char*)"textures/pika_ae86_t.png",2);
    init();
    }
    Mapa::~Mapa()
    {

    }

void Mapa::init()
{
    srand (time(NULL));
    int map = rand()%2 +1;
    if (map == 1)
    {
        N = 20;
        int cont = 0;
        p1_Start_Position = btVector3(-4,3,90);
        p2_Start_Position = btVector3(4,3,90);
        mapa = (GameObject**)malloc(((N*3))*sizeof(GameObject));
        mapa[cont++] = new GameObject((char*)"mallas/grass_bg.obj",shader_programme,btScalar(0),
            btVector3( 0,-7.9,80),btQuaternion(0,0,0),dynamicsWorld, (char*)"textures/pastito.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/start.obj",shader_programme,btScalar(0),
            btVector3( 0,-11,118.15),btQuaternion(0,0,0),dynamicsWorld, (char*)"textures/start.png");
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
        mapa[cont++] = new GameObject((char*)"mallas/map_track_turn.obj",shader_programme,btScalar(0),
            btVector3( 290,-10,-80),btQuaternion(3*PI/2,0,0),dynamicsWorld, (char*)"textures/map_track_turn_t.png");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat.obj",shader_programme,btScalar(0),
            btVector3( 290,-10,-135),btQuaternion(0,1,0,sin(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        N = cont;
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
        mapa[cont++] = new GameObject((char*)"mallas/map_track_turn_border_T.obj",shader_programme,btScalar(0),
            btVector3( 290,-10,-80),btQuaternion(3*PI/2,0,0),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_L.obj",shader_programme,btScalar(0),
            btVector3( 290,-10,-135),btQuaternion(0,1,0,sin(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
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
        mapa[cont++] = new GameObject((char*)"mallas/map_track_turn_border_R.obj",shader_programme,btScalar(0),
            btVector3( 290,-10,-80),btQuaternion(3*PI/2,0,0),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_R.obj",shader_programme,btScalar(0),
            btVector3( 290,-10,-135),btQuaternion(0,1,0,sin(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        meta = new GameObject((char*)"mallas/goal2.obj",shader_programme,btScalar(0),
            btVector3( 290,-10,-170),btQuaternion(0,0,0),dynamicsWorld, (char*)"textures/Rainbow-Texture.jpg");
    }
    else if (map == 2)
    {
        N = 20;
        int cont = 0;
        p1_Start_Position = btVector3(-3,1,90);
        p2_Start_Position = btVector3(4,1,90);
        mapa = (GameObject**)malloc(((N*3)+2)*sizeof(GameObject));
        mapa[cont++] = new GameObject((char*)"mallas/grass_bg.obj",shader_programme,btScalar(0),
            btVector3( 0,-7.9,80),btQuaternion(0,0,0),dynamicsWorld, (char*)"textures/pastito.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/start.obj",shader_programme,btScalar(0),
            btVector3( 0,-11,118.15),btQuaternion(0,0,0),dynamicsWorld, (char*)"textures/start.png");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat.obj",shader_programme,btScalar(0),
            btVector3( 0,-10,70),btQuaternion(0,1,0,sin(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_turn.obj",shader_programme,btScalar(0),
            btVector3(0,-10,15),btQuaternion(-2*PI,0,0),dynamicsWorld,(char*)"textures/map_track_turn_t.png");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat.obj",shader_programme,btScalar(0),
            btVector3( -55,-10,15),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_turn.obj",shader_programme,btScalar(0),
            btVector3(-110,-10,15),btQuaternion(0,1,0,cos(0)),dynamicsWorld,(char*)"textures/map_track_turn_t.png");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat.obj",shader_programme,btScalar(0),
            btVector3( -110,-10,70),btQuaternion(0,1,0,sin(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat.obj",shader_programme,btScalar(0),
            btVector3( -110,-10,125),btQuaternion(0,1,0,sin(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_turn.obj",shader_programme,btScalar(0),  
            btVector3(-110,-10,180),btQuaternion(0,1,0,sin(0)),dynamicsWorld,(char*)"textures/map_track_turn_t.png");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat.obj",shader_programme,btScalar(0),
            btVector3( -55,-10,180),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat.obj",shader_programme,btScalar(0),
            btVector3( 0,-10,180),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat.obj",shader_programme,btScalar(0),
            btVector3( 55,-10,180),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_turn.obj",shader_programme,btScalar(0),  
            btVector3(110,-10,180),btQuaternion(3*PI/2,0,0),dynamicsWorld,(char*)"textures/map_track_turn_t.png");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat.obj",shader_programme,btScalar(0),
            btVector3( 110,-10,125),btQuaternion(0,1,0,sin(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat.obj",shader_programme,btScalar(0),
            btVector3( 110,-10,70),btQuaternion(0,1,0,sin(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat.obj",shader_programme,btScalar(0),
            btVector3( 110,-10,15),btQuaternion(0,1,0,sin(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat.obj",shader_programme,btScalar(0),
            btVector3( 110,-10,-40),btQuaternion(0,1,0,sin(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_turn.obj",shader_programme,btScalar(0),
            btVector3(110,-10,-95),btQuaternion(-2*PI,0,0),dynamicsWorld,(char*)"textures/map_track_turn_t.png");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat.obj",shader_programme,btScalar(0),
            btVector3( 55,-10,-95),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat.obj",shader_programme,btScalar(0),
            btVector3( 0,-10,-95),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat.obj",shader_programme,btScalar(0),
            btVector3( -55,-10,-95),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat.obj",shader_programme,btScalar(0),
            btVector3( -110,-10,-95),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat.obj",shader_programme,btScalar(0),
            btVector3( -165,-10,-95),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_turn.obj",shader_programme,btScalar(0),
            btVector3(-220,-10,-95),btQuaternion(0,1,0, sin(0)),dynamicsWorld,(char*)"textures/map_track_turn_t.png");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat.obj",shader_programme,btScalar(0),
            btVector3(-220,-10,-150),btQuaternion(0,1,0,sin(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_turn.obj",shader_programme,btScalar(0),
            btVector3(-220,-10,-205),btQuaternion(0,1,0,cos(0)),dynamicsWorld,(char*)"textures/map_track_turn_t.png");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat.obj",shader_programme,btScalar(0),
            btVector3( -165,-10,-205),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat.obj",shader_programme,btScalar(0),
            btVector3( -110,-10,-205),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat.obj",shader_programme,btScalar(0),
            btVector3( -55,-10,-205),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat.obj",shader_programme,btScalar(0),
            btVector3( 0,-10,-205),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_turn.obj",shader_programme,btScalar(0),
            btVector3(55,-10,-205),btQuaternion(3*PI/2,0,0),dynamicsWorld,(char*)"textures/map_track_turn_t.png");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat.obj",shader_programme,btScalar(0),
            btVector3( 55,-10,-260),btQuaternion(0,1,0,sin(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
       N=cont;
       mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_R.obj",shader_programme,btScalar(0),
            btVector3( 0,-10,70),btQuaternion(0,1,0,sin(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_turn_border_R.obj",shader_programme,btScalar(0),
            btVector3(0,-10,15),btQuaternion(-2*PI,0,0),dynamicsWorld,(char*)"textures/map_track_turn_t.png");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_R.obj",shader_programme,btScalar(0),
            btVector3( -55,-10,15),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_turn_border_R.obj",shader_programme,btScalar(0),
            btVector3(-110,-10,15),btQuaternion(0,1,0,cos(0)),dynamicsWorld,(char*)"textures/map_track_turn_t.png");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_R.obj",shader_programme,btScalar(0),
            btVector3( -110,-10,70),btQuaternion(0,1,0,sin(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_R.obj",shader_programme,btScalar(0),
            btVector3( -110,-10,125),btQuaternion(0,1,0,sin(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_turn_border_R.obj",shader_programme,btScalar(0),  
            btVector3(-110,-10,180),btQuaternion(0,1,0,sin(0)),dynamicsWorld,(char*)"textures/map_track_turn_t.png");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_R.obj",shader_programme,btScalar(0),
            btVector3( -55,-10,180),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_R.obj",shader_programme,btScalar(0),
            btVector3( 0,-10,180),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_R.obj",shader_programme,btScalar(0),
            btVector3( 55,-10,180),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_turn_border_R.obj",shader_programme,btScalar(0),  
            btVector3(110,-10,180),btQuaternion(3*PI/2,0,0),dynamicsWorld,(char*)"textures/map_track_turn_t.png");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_R.obj",shader_programme,btScalar(0),
            btVector3( 110,-10,125),btQuaternion(0,1,0,sin(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_R.obj",shader_programme,btScalar(0),
            btVector3( 110,-10,70),btQuaternion(0,1,0,sin(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_R.obj",shader_programme,btScalar(0),
            btVector3( 110,-10,15),btQuaternion(0,1,0,sin(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_R.obj",shader_programme,btScalar(0),
            btVector3( 110,-10,-40),btQuaternion(0,1,0,sin(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_turn_border_R.obj",shader_programme,btScalar(0),
            btVector3(110,-10,-95),btQuaternion(-2*PI,0,0),dynamicsWorld,(char*)"textures/map_track_turn_t.png");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_R.obj",shader_programme,btScalar(0),
            btVector3( 55,-10,-95),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_R.obj",shader_programme,btScalar(0),
            btVector3( 0,-10,-95),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_R.obj",shader_programme,btScalar(0),
            btVector3( -55,-10,-95),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_R.obj",shader_programme,btScalar(0),
            btVector3( -110,-10,-95),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_R.obj",shader_programme,btScalar(0),
            btVector3( -165,-10,-95),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_turn_border_R.obj",shader_programme,btScalar(0),
            btVector3(-220,-10,-95),btQuaternion(0,1,0, sin(0)),dynamicsWorld,(char*)"textures/map_track_turn_t.png");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_R.obj",shader_programme,btScalar(0),
            btVector3(-220,-10,-150),btQuaternion(0,1,0,sin(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_turn_border_R.obj",shader_programme,btScalar(0),
            btVector3(-220,-10,-205),btQuaternion(0,1,0,cos(0)),dynamicsWorld,(char*)"textures/map_track_turn_t.png");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_R.obj",shader_programme,btScalar(0),
            btVector3( -165,-10,-205),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_R.obj",shader_programme,btScalar(0),
            btVector3( -110,-10,-205),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_R.obj",shader_programme,btScalar(0),
            btVector3( -55,-10,-205),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_R.obj",shader_programme,btScalar(0),
            btVector3( 0,-10,-205),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_turn_border_R.obj",shader_programme,btScalar(0),
            btVector3(55,-10,-205),btQuaternion(3*PI/2,0,0),dynamicsWorld,(char*)"textures/map_track_turn_t.png");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_R.obj",shader_programme,btScalar(0),
            btVector3( 55,-10,-260),btQuaternion(0,1,0,sin(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_L.obj",shader_programme,btScalar(0),
            btVector3( 0,-10,70),btQuaternion(0,1,0,sin(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_turn_border_T.obj",shader_programme,btScalar(0),
            btVector3(0,-10,15),btQuaternion(-2*PI,0,0),dynamicsWorld,(char*)"textures/map_track_turn_t.png");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_L.obj",shader_programme,btScalar(0),
            btVector3( -55,-10,15),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_turn_border_T.obj",shader_programme,btScalar(0),
            btVector3(-110,-10,15),btQuaternion(0,1,0,cos(0)),dynamicsWorld,(char*)"textures/map_track_turn_t.png");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_L.obj",shader_programme,btScalar(0),
            btVector3( -110,-10,70),btQuaternion(0,1,0,sin(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_L.obj",shader_programme,btScalar(0),
            btVector3( -110,-10,125),btQuaternion(0,1,0,sin(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_turn_border_T.obj",shader_programme,btScalar(0),  
            btVector3(-110,-10,180),btQuaternion(0,1,0,sin(0)),dynamicsWorld,(char*)"textures/map_track_turn_t.png");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_L.obj",shader_programme,btScalar(0),
            btVector3( -55,-10,180),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_L.obj",shader_programme,btScalar(0),
            btVector3( 0,-10,180),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_L.obj",shader_programme,btScalar(0),
            btVector3( 55,-10,180),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_turn_border_T.obj",shader_programme,btScalar(0),  
            btVector3(110,-10,180),btQuaternion(3*PI/2,0,0),dynamicsWorld,(char*)"textures/map_track_turn_t.png");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_L.obj",shader_programme,btScalar(0),
            btVector3( 110,-10,125),btQuaternion(0,1,0,sin(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_L.obj",shader_programme,btScalar(0),
            btVector3( 110,-10,70),btQuaternion(0,1,0,sin(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_L.obj",shader_programme,btScalar(0),
            btVector3( 110,-10,15),btQuaternion(0,1,0,sin(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");     
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_L.obj",shader_programme,btScalar(0),
            btVector3( 110,-10,-40),btQuaternion(0,1,0,sin(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_turn_border_T.obj",shader_programme,btScalar(0),
            btVector3(110,-10,-95),btQuaternion(-2*PI,0,0),dynamicsWorld,(char*)"textures/map_track_turn_t.png");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_L.obj",shader_programme,btScalar(0),
            btVector3( 55,-10,-95),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_L.obj",shader_programme,btScalar(0),
            btVector3( 0,-10,-95),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_L.obj",shader_programme,btScalar(0),
            btVector3( -55,-10,-95),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_L.obj",shader_programme,btScalar(0),
            btVector3( -110,-10,-95),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_L.obj",shader_programme,btScalar(0),
            btVector3( -165,-10,-95),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_turn_border_T.obj",shader_programme,btScalar(0),
            btVector3(-220,-10,-95),btQuaternion(0,1,0, sin(0)),dynamicsWorld,(char*)"textures/map_track_turn_t.png");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_L.obj",shader_programme,btScalar(0),
            btVector3(-220,-10,-150),btQuaternion(0,1,0,sin(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_turn_border_T.obj",shader_programme,btScalar(0),
            btVector3(-220,-10,-205),btQuaternion(0,1,0,cos(0)),dynamicsWorld,(char*)"textures/map_track_turn_t.png");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_L.obj",shader_programme,btScalar(0),
            btVector3( -165,-10,-205),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_L.obj",shader_programme,btScalar(0),
            btVector3( -110,-10,-205),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_L.obj",shader_programme,btScalar(0),
            btVector3( -55,-10,-205),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_L.obj",shader_programme,btScalar(0),
            btVector3( 0,-10,-205),btQuaternion(0,1,0,cos(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_turn_border_T.obj",shader_programme,btScalar(0),
            btVector3(55,-10,-205),btQuaternion(3*PI/2,0,0),dynamicsWorld,(char*)"textures/map_track_turn_t.png");
        mapa[cont++] = new GameObject((char*)"mallas/map_track_flat_border_L.obj",shader_programme,btScalar(0),
            btVector3( 55,-10,-260),btQuaternion(0,1,0,sin(0)),dynamicsWorld, (char*)"textures/map_track_flat_t.jpg");
        meta = new GameObject((char*)"mallas/goal2.obj",shader_programme,btScalar(0),
            btVector3( 55,-10,-295),btQuaternion(0,0,0),dynamicsWorld, (char*)"textures/Rainbow-Texture.jpg");
    }
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
    btTransform trans;
    meta->getRigidBody()->getMotionState()->getWorldTransform(trans);
    trans.getOpenGLMatrix(&meta->model[0][0]);
    meta->setModelMatrix(meta->model);
    glUniformMatrix4fv(model_mat_location, 1, GL_FALSE, &meta->modelMatrix[0][0]);

    glActiveTexture (GL_TEXTURE0);
    glBindTexture (GL_TEXTURE_2D, meta->texture);
    glUniform1i (meta->tex_location, 0);

    glActiveTexture (GL_TEXTURE1);
    glBindTexture (GL_TEXTURE_2D, meta->normalMap);
    //glUniform1i (normalMapLocation, 1);

    glBindVertexArray(meta->getVao());
    glDrawArrays(GL_TRIANGLES, 0, meta->getNumVertices());
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
