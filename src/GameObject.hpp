#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H
#include "tools.h"

class GameObject{

protected:
    GLuint vao;
    GLuint ebo;
    btVector3 position;
    btDiscreteDynamicsWorld* world;
    btQuaternion rotation;
    btScalar mass;
    int vertNumber;
    int indicesNumber;
    btRigidBody* rigidBody;

    GLuint matloc;


    bool load_mesh (const char* file_name, GLuint& vao, int& vert_no, btCollisionShape** col);
    bool load_mesh (const char* file_name, GLuint& vao, int& vert_no); 
    


public:
    //TEXTURES
    GLuint texture;
    GLuint tex_location;
    unsigned int normalMap;
    unsigned int normalMapLoc;
    GLuint shader_programme;
    
    glm::mat4 modelMatrix;

    glm::mat4 model;

    GameObject();
    GameObject(const char* path, GLuint shaderprog, btScalar masa, btVector3 startPosition,
         btQuaternion startRotation,btDiscreteDynamicsWorld* dynamicsWorld,
         const char* texture_path);
    GameObject(const char* path, GLuint shaderprog, btScalar masa, btVector3 startPosition,
         btQuaternion startRotation,btDiscreteDynamicsWorld* dynamicsWorld);

    ~GameObject();

    //getter
    GLuint getVao();
    btScalar getMass();
    void setMass(btScalar masa);
    btVector3 getPosition();
    void setPosition(btVector3 posicion);
    btQuaternion getRotation();
    void setRotation(btQuaternion rotacion);
    btRigidBody* getRigidBody();
    int getNumVertices();
    void setModelMatrix(glm::mat4 model);
    void draw(GLuint model_mat_location);
    void setWorld(btDiscreteDynamicsWorld* world);
    btDiscreteDynamicsWorld* getWorld();
    bool load_texture (GLuint shaderprog, const char* texture_path, const char* normal_path); 
    bool load_texture2 (GLuint shaderprog, const char* texture_path, GLuint& texture, GLuint tex_location);

};

#endif
