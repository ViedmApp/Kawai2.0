#include "Input.hpp"
Input::Input(GLFWwindow* window, Vehicle* firstPlayer, Vehicle* secondPlayer, Camera *camara, Camera* camara2, Mapa *mapa)
{
  this->window = window;
  this->firstPlayer = firstPlayer;
  this->secondPlayer = secondPlayer;
  this->camara=camara;
  this -> camara2 = camara2;
  this -> mapa = mapa;
}

void Input::initialiceInput(){
  prevPlayerX=firstPlayer->getX();
  prevPlayerZ=firstPlayer->getZ();

  prevPlayer2X=secondPlayer->getX();
  prevPlayer2Z=secondPlayer->getZ();



  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
      glfwSetWindowShouldClose(window, true);

  if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
    firstPlayer ->accelerate();
  if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_RELEASE)
    firstPlayer -> updatePhysics();
  if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
    firstPlayer -> turnRight();
  if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_RELEASE)
    firstPlayer -> updateTurn();
  if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
    firstPlayer -> turnLeft();
  if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_RELEASE)
    firstPlayer -> updateTurn();
  if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
    firstPlayer -> reverse();
  if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
    firstPlayer -> reverse();
  if (glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS and !trampa)
  {
    mapa -> crearTrampa(firstPlayer->getX(),firstPlayer->getY(),firstPlayer->getZ(),1);
    trampa = true;
  }
  else if(glfwGetKey(window, GLFW_KEY_P) == GLFW_RELEASE and trampa)
  {
    trampa = false;
  }


  if (glfwGetKey(window, GLFW_KEY_U) == GLFW_PRESS)
      secondPlayer ->accelerate();
  if (glfwGetKey(window, GLFW_KEY_U) == GLFW_RELEASE)
      secondPlayer -> updatePhysics();
  if (glfwGetKey(window, GLFW_KEY_K) == GLFW_PRESS)
    secondPlayer -> turnRight();
  if (glfwGetKey(window, GLFW_KEY_K) == GLFW_RELEASE)
    secondPlayer -> updateTurn();
  if (glfwGetKey(window, GLFW_KEY_H) == GLFW_PRESS)
    secondPlayer -> turnLeft();
  if (glfwGetKey(window, GLFW_KEY_H) == GLFW_RELEASE)
    secondPlayer -> updateTurn();
  if (glfwGetKey(window, GLFW_KEY_J) == GLFW_PRESS)
    secondPlayer -> reverse();

    

camara->setCameraPos(glm::vec3(camara->getCameraPos().x - 0.15*(camara->getCameraPos().x - prevPlayerX),
  0,
  camara->getCameraPos().z - 0.15*(camara->getCameraPos().z - prevPlayerZ)));


camara2->setCameraPos(glm::vec3(camara2->getCameraPos().x - 0.15*(camara2->getCameraPos().x - prevPlayer2X),
  0,
  camara2->getCameraPos().z - 0.15*(camara2->getCameraPos().z - prevPlayer2Z)));
}





Input::~Input(){}
