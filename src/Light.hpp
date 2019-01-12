#pragma once
#include "tools.h"

#define MAX_LIGHTS 2

class Light
{
    private:
        glm::vec3* Light_pos = (glm::vec3*) malloc (sizeof(glm::vec3)*2);
        int numLights = 0;

        int light_loc, ls_loc, ld_loc, la_loc;
        int ks_loc, kd_loc, ka_loc;
        int pow_loc;


        GLuint shader_programme;

        //Colours
        glm::vec3* Ls = (glm::vec3*) malloc (sizeof(glm::vec3)*MAX_LIGHTS);
        glm::vec3* Ld = (glm::vec3*) malloc (sizeof(glm::vec3)*MAX_LIGHTS);
        glm::vec3* La = (glm::vec3*) malloc (sizeof(glm::vec3)*MAX_LIGHTS);

        //Surface Reflectance
        glm::vec3 *Ks = (glm::vec3*) malloc (sizeof(glm::vec3)*MAX_LIGHTS);
        glm::vec3 *Kd = (glm::vec3*) malloc (sizeof(glm::vec3)*MAX_LIGHTS);
        glm::vec3 *Ka = (glm::vec3*) malloc (sizeof(glm::vec3)*MAX_LIGHTS);

        float* specular_power = (float*) malloc (sizeof(float)*MAX_LIGHTS);

    public:
    Light(GLuint shader_programme);
    ~Light();
    void addLight(glm::vec3 position, glm::vec3 Ls, glm::vec3 Ld, glm::vec3 La, glm::vec3 Ks, glm::vec3 Kd, glm::vec3 Ka, float power);
    void initLights();

};