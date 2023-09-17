#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "Model.h"
#include "Camera.h"
#include "ShaderTerrain.h"
#include "Renderer.h"



class GameManager {
public :
	static void drawTerrain(Model terrain , Camera c , ShaderTerrain shT);

};
#endif
