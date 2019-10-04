cmake_minimum_required(VERSION 3.14)
project(opengl_test)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_MODULE_PATH /usr/local/lib/cmake)
set(CMAKE_PREFIX_PATH /usr/local/lib/cmake/glfw3)

find_package(glfw3 3.3 REQUIRED)

add_executable(opengl_test
        src/main.cpp
        src/std_image.h
        src/std_image.cpp
        src/Renderer.cpp src/Renderer.h
        src/VertexBuffer.cpp src/VertexBuffer.h
        src/IndexBuffer.cpp src/IndexBuffer.h
        src/VertexArray.cpp src/VertexBufferLayout.h
        src/Shader.h src/Shader.cpp
        src/Texture.cpp src/Texture.h)

target_link_libraries(opengl_test
        glfw
        GL
)