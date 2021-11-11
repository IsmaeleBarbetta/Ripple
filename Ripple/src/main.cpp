//
// Created by ismaele on 11/11/21.
//

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "rppch.hpp"

void error_callback(int error, const char* desc) {
    fprintf(stderr, "Error: %s\n", desc);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

const char* vertexSource = R"(
    #version 330 core
    layout (location=0) in vec3 aPos;
    out vec3 col;

    void main() {
        gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
        col = vec3(aPos.x + 0.5, aPos.y + 0.5, aPos.z + 0.5);
    }
)";

const char* fragmentSource = R"(
    #version 330

    in vec3 col;
    out vec4 color;

    void main() {
        // color = vec4(1.0, 0.5, 0.2, 1.0);
        color = vec4(col, 1.0);
    }
)";

int main() {
    if(!glfwInit()) {
        std::cout << "Init failed" << std::endl;
        return 1;
    }

    glfwSetErrorCallback(error_callback);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    GLFWwindow* window = glfwCreateWindow(400, 400, "Ripple", NULL, NULL);

    if(!window) {
        std::cout << "Window creation failed" << std::endl;
        return 1;
    }

    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);
    gladLoadGL();
    glfwSwapInterval(1);

    float vertices[] = {
        -0.8, -0.5, 0.0,
         0.0,  -0.5, 0.0,
         0.8, -0.5, 0.0,
        -0.4,   0.0, 0.0,
         0.4,   0.0, 0,
         0.0,   0.5, 0
    };

    // Vertex Buffer
    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Vertex Array
    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Element Buffer
    unsigned int indices[] = {
        0, 1, 3,
        1, 2, 4,
        3, 4, 5
    };

    unsigned int EBO;
    glGenBuffers(1, &EBO);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // Shaders
    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexSource, NULL);
    glCompileShader(vertexShader);

    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
    glCompileShader(fragmentShader);

    unsigned int shader;
    shader = glCreateProgram();
    glAttachShader(shader, vertexShader);
    glAttachShader(shader, fragmentShader);
    glLinkProgram(shader);

    glUseProgram(shader);
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    // Loop

    while(!glfwWindowShouldClose(window)) {
        glClearColor(0.3, 0.3, 0.3, 1);
        glClear(GL_COLOR_BUFFER_BIT);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }


    glfwDestroyWindow(window);
    glfwTerminate();
}