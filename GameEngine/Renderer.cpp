#include "Renderer.h"

void Renderer::prepare()
{
    glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
    glEnable(GL_DEPTH_TEST);  
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::render(Model m)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, m.getId());
    glBindVertexArray(m.getMesh().getVaoID());
    glDrawElements(GL_TRIANGLES,m.getMesh().getVertexCount(), GL_UNSIGNED_INT, 0);
}


void Renderer::render_N(Model m)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, m.getId());
    glBindVertexArray(m.getMesh().getVaoID());
    glDrawArrays(GL_TRIANGLES, 0, m.getMesh().getVertexCount());
}

void Renderer::clear()
{
    glClear(GL_COLOR_BUFFER_BIT);
}
