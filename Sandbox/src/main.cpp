//
// Created by ismaele on 10/08/20.
//

#include <Ripple.h>

class Sandbox : public Ripple::Application {
public:
  Sandbox() = default;
  virtual ~Sandbox() = default;

  void run() override {
    RP_INFO("Created client Application");
    Application::run();
  }
};

Ripple::Application* Ripple::createApplication() {
  return new Sandbox();
}