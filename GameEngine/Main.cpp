#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include  <cstdlib>
#include "Display.h"
#include "Loader.h"
#include "Renderer.h"
#include "ShaderProgram.h"
#include "Model.h"
#include "Camera.h"
#include "Light.h"
#include "Maze.h"
#include "ShaderTerrain.h"


int main()
{
    
    GLFWwindow* window = DisplayManager::createDisplay();

    ShaderProgram sh = ShaderProgram("shader/vertexShader.txt", "shader/fragmentShader.txt");
    ShaderTerrain shT = ShaderTerrain("shader/vertexShaderTerrain.txt", "shader/fragmentShaderTerrain.txt");

    Model model = Model(Loader::loadToVao_PTN("wall.obj"), Loader::loadTexture("brique.jpg", GL_RGB), Material(5, 0.5));
    Model terrain = Model(Loader::loadToVao_PTN("terrain2.obj"), Loader::loadTexture("Ground037_1K_Color.jpg", GL_RGB), Material(1, 1.0));


    Light light = Light(glm::vec3(0, 1.0f, 0.0f), glm::vec3(1,1,1)) ;
    Camera c = Camera();

    sh.initProjection();
    sh.setLight(light);
    sh.initMaterial(model.getMaterial());


    shT.initProjection();
    
    

    Renderer::prepare();
    while (!DisplayManager::windowRequestClose(window))
    {
        Renderer::clear();
       
        c.move(window);


        model.setT(glm::scale(glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -2.0f)), glm::vec3(1, 1, 1)));
  
        sh.start();
        sh.setMat4("view", c.getViewMatrix());
        sh.setMat4("model", model.getT());
        //Renderer::render_N(model);
        sh.stop();

        

        DisplayManager::updateDisplay(window);
    }

    DisplayManager::destroyDisplay(window);
    
    /*
    vector<vector<char>> map = Maze::generate(10, 10);

    for (int i = 0; i < map.size(); ++i)
    {
        for (int j = 0; j < map[0].size(); ++j)
        {
            cout << map[i][j];
        }
        cout << endl;
    }
    */
    return 0;
}