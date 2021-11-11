//
// Created by ismaele on 11/11/21.
//

#ifndef RIPPLEFULL_APPLICATION_HPP
#define RIPPLEFULL_APPLICATION_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <string>

int main(int argc, char* argv[]);

namespace Ripple {
    class Application {
      public:
        Application(const std::string& name = "Ripple Engine");
        virtual ~Application();

      private:
        void Run();
        void Close();

        virtual void onCreate() = 0;
        virtual void onUpdate() = 0;

      private:
        bool m_Running;
        GLFWwindow* m_Window;

      private:
        friend int ::main(int argc, char* argv[]);
        static Application* s_Instance;
    };

    Application* Create();
}

#endif    //RIPPLEFULL_APPLICATION_HPP
