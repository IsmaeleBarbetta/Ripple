//
// Created by ismaele on 10/08/20.
//

#ifndef RIPPLE_ENTRYPOINT_H
#define RIPPLE_ENTRYPOINT_H

int main(int argc, char** argv) {
  Ripple::Log::Init();
  RP_CORE_INFO("Ripple Engine.");

  auto app = Ripple::createApplication();
  app->run();
  delete app;

  return 0;
}

#endif // RIPPLE_ENTRYPOINT_H
