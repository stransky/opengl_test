#pragma once

#define GL_GLEXT_PROTOTYPES
#include <GL/gl.h>

#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"


#define GLCall(x)       \
    GLClearError();     \
    x;                  \
    GLCheckError(#x)

void GLClearError();
void GLCheckError(const char *function);

class Renderer
{
public:
    void Clear() const;
    void Draw(const VertexArray &va, const IndexBuffer &ib, const Shader& shader) const;
};