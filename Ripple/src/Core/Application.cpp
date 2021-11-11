//
// Created by ismaele on 11/11/21.
//

#include "Application.hpp"

#include "rppch.hpp"

namespace Ripple {
    Application* Application::s_Instance = nullptr;

    Application::Application(const std::string& name) : m_Running(false) {
        s_Instance = this;

        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

        m_Window = glfwCreateWindow(400, 400, name.c_str(), NULL, NULL);

        glfwMakeContextCurrent(m_Window);
        gladLoadGL();
        glfwSwapInterval(1);
    }

    Application::~Application() = default;

    void Application::Run() {
        while (!glfwWindowShouldClose(m_Window)) {
            glClearColor(0.3, 0.3, 0.3, 1);
            glClear(GL_COLOR_BUFFER_BIT);

            glfwSwapBuffers(m_Window);
            glfwPollEvents();
        }

        glfwDestroyWindow(m_Window);
        glfwTerminate();
    }

    void Application::Close() {
        this->m_Running = false;
    }
}