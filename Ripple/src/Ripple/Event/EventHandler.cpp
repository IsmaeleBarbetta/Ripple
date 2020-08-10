//
// Created by ismaele on 10/08/20.
//

#include "EventHandler.h"

namespace Ripple {
  template <typename T>
  bool EventHandler::handle(EventHandler::fHandled<T> f) {

    if(mEvent.getType() == T::getStaticType()) {
      mEvent.bHandled = fHandled(*(T*)&mEvent);
      return true;
    }

    return false;
  }
}