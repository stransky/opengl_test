#include "Renderer.h"
#include <iostream>


void GLClearError()
{
    while(glGetError() != GL_NO_ERROR);
}
void GLCheckError(const char *function)
{
    while (GLenum error = glGetError())
        std::cout << "<OpeGL error>: " << error << "\n" << function << std::endl;
}

void Renderer::Draw(const VertexArray &va, const IndexBuffer &ib, const Shader &shader) const
{
    shader.Bind();
    va.Bind();
    ib.Bind();
    GLCall(glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr));

}

void Renderer::Clear() const
{
    GLCall(glClear(GL_COLOR_BUFFER_BIT));
}
