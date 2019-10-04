#include "Renderer.h"
#include <GLFW/glfw3.h>
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "Shader.h"
#include "Texture.h"


int main(void)
{
    GLFWwindow *window;

    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(1280, 720, "test", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    float positions[] = {
            // positions    tex coords
            -1.0f, -1.0f,   0.0f, 0.0f,
             1.0f, -1.0f,   1.0f, 0.0f,
             1.0f,  1.0f,   1.0f, 1.0f,
            -1.0f,  1.0f,   0.0f, 1.0f
    };

    unsigned int indices[] = {
            0, 1, 2,
            0, 2, 3
    };

    VertexArray VA;
    VertexBuffer VB(&positions, sizeof(positions));
    VertexBufferLayout layout;
    layout.Push<float>(2);
    layout.Push<float>(2);
    VA.AddBuffer(VB, layout);

    IndexBuffer IB(&indices, sizeof(indices));

    Shader shader("../res/shaders/basic.shader");
    shader.Bind();
    shader.SetUniform4f("u_Color", 0.2f, 0.3f, 0.8f, 1.0f);

    Texture texture("../res/textures/island.jpg");
    texture.Bind();
    shader.SetUniform1i("u_Texture", 0);

    Renderer renderer;

    while(!glfwWindowShouldClose(window))
    {
        renderer.Clear();

        shader.Bind();
        renderer.Draw(VA, IB, shader);

        GLCall(glfwSwapBuffers(window));
        GLCall(glfwPollEvents());
    }

    glfwTerminate();
    return 0;
}