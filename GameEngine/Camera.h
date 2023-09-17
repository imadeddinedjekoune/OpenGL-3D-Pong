#ifndef CAMERA_H
#define CAMERA_H

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Camera {
public:
    glm::vec3 position ;
    float pitch = 0 , yaw = 0.0f ;

    Camera();
    void move(GLFWwindow* window);
    glm::mat4 getViewMatrix();


};
#endif
