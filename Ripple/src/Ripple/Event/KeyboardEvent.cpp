//
// Created by ismaele on 12/08/20.
//

#include "KeyboardEvent.h"

namespace Ripple {
// KeyPressedEvent
std::string KeyPressedEvent::toString() const {
  std::stringstream ss;
  ss << "KeyPressedEvent: " << mKeyCode << "(" << mRepeatCount << ")";
  return ss.str();
}

// KeyReleasedEvent
std::string KeyReleasedEvent::toString() const {
  std::stringstream ss;
  ss << "KeyReleasedEvent: " << mKeyCode;
  return ss.str();
}
}