#ifndef RENDERER_H
#define RENDERER_H

#include <glad/glad.h>
#include "Model.h"

class Renderer {
public:
    static void prepare();
    static void render(Model m);
    static void render_N(Model m);
    static void clear();
};

#endif