//
// Created by ismaele on 10/18/21.
//

#include <Ripple.hpp>

class Sandbox : public Ripple::Application {
  public:
    void onCreate() override {}
    void onUpdate() override {}
};

Ripple::Application * Ripple::Create() {
    return new Sandbox();
}