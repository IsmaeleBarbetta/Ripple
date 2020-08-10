//
// Created by ismaele on 10/08/20.
//

#ifndef RIPPLE_EVENTHANDLER_H
#define RIPPLE_EVENTHANDLER_H

#include "Event.h"

namespace Ripple {

  class EventHandler {
    template <typename T>
    using fHandled = T(*)(Event&);

  public:
    explicit EventHandler(Event& event) : mEvent(event) {}

    template <typename T>
    bool handle(fHandled<T> f);

  private:
    Event& mEvent;
  };

}

#endif // RIPPLE_EVENTHANDLER_H
