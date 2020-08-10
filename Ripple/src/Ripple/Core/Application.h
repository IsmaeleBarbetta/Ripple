//
// Created by ismaele on 10/08/20.
//

#ifndef RIPPLE_APPLICATION_H
#define RIPPLE_APPLICATION_H

namespace Ripple {

class Application {
public:
  Application();
  virtual ~Application();

  virtual void run();

private:
};

Application* createApplication();

}

#endif // RIPPLE_APPLICATION_H
