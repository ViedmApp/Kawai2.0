#include "Light.hpp"

Light::Light(GLuint shader_programme)
{
    this->shader_programme=shader_programme;
}

void Light::addLight(glm::vec3 position, glm::vec3 Ls, glm::vec3 Ld, glm::vec3 La, glm::vec3 Ks, glm::vec3 Kd, glm::vec3 Ka, float power)
{
    
    this->Light_pos[numLights] = position;
    this->Ls[numLights] = Ls;
    this->La[numLights] = La;
    this->Ld[numLights] = Ld;
    this->Ks[numLights] = Ks;
    this->Kd[numLights] = Kd;
    this->Ka[numLights] = Ka;
    this->specular_power[numLights] = power;
    numLights++;
}

void Light::initLights()
{
    this->light_loc = glGetUniformLocation(shader_programme,"light_pos");
    glUseProgram(shader_programme);
    glUniform3fv(light_loc,2,(const GLfloat*)Light_pos);


    printf("---%d,%d,%d---\n",Ls[0].x,Ls[0].y,Ls[0].z);
    this->ls_loc = glGetUniformLocation(shader_programme,"light_spec");
    glUseProgram(shader_programme);
    glUniform3fv(ls_loc,2,(const GLfloat*)Ls);

    this->ld_loc = glGetUniformLocation(shader_programme,"light_diff");
    glUseProgram(shader_programme);
    glUniform3fv(ld_loc,2,(const GLfloat*)Ld);

    this->la_loc = glGetUniformLocation(shader_programme,"light_amb");
    glUseProgram(shader_programme);
    glUniform3fv(la_loc,2,(const GLfloat*)La);

        this->ks_loc = glGetUniformLocation(shader_programme,"light_ks");
    glUseProgram(shader_programme);
    glUniform3fv(ks_loc,2,(const GLfloat*)Ks);

        this->kd_loc = glGetUniformLocation(shader_programme,"light_kd");
    glUseProgram(shader_programme);
    glUniform3fv(kd_loc,2,(const GLfloat*)Kd);

        this->ka_loc = glGetUniformLocation(shader_programme,"light_ka");
    glUseProgram(shader_programme);
    glUniform3fv(ka_loc,2,(const GLfloat*)Ka);

    this->pow_loc = glGetUniformLocation(shader_programme, "light_pow");
    glUseProgram(shader_programme);
    glUniform3fv(pow_loc,2,specular_power);
}

Light::~Light()
{

}