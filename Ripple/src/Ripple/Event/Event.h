//
// Created by ismaele on 10/08/20.
//

#ifndef RIPPLE_EVENT_H
#define RIPPLE_EVENT_H

#include "Core/Base.h"
#include "rpph.h"

#define SET_TYPE(type) static E_TYPE getStaticType() { return E_TYPE::type; } \
                     virtual E_TYPE getType() const override { return getStaticType(); } \
                     virtual const char* getName() const { return #type; }         \

#define SET_CATEGORY(category) int getCategory() const override { return category; }

namespace Ripple {
enum class E_TYPE {
  None = 0,
  WindowMove,
  WindowResize,
  WindowClose,
  WindowFocus,
  WindowLostFocus,
  KeyPressed,
  KeyReleased,
  MouseButtonPressed,
  MouseButtonReleased,
  MouseMoved,
  MouseScrolled
};

enum E_CATEGORY {
  None = 0,
  EC_APPLICATION = BIT(0u),
  EC_INPUT       = BIT(1u),
  EC_KEYBOARD    = BIT(2u),
  EC_MOUSE       = BIT(3u),
};

inline bool operator&(E_CATEGORY a, E_CATEGORY b) {
  return static_cast<bool>(static_cast<unsigned int>(a) & static_cast<unsigned int>(b));
}

class Event {
  friend class EventHandler;

public:
  virtual E_TYPE getType() const = 0;
  virtual int getCategory() const = 0;

  bool isInCategory(E_CATEGORY category) const {
    return getCategory() & category;
  }

  // DEBUG
  virtual std::string toString() const { return "Event"; }

protected:
  bool bHandled = false;
};

inline std::ostream &operator<<(std::ostream &os, const Event &e) {
  return os << e.toString();
}

} // namespace Ripple

#endif // RIPPLE_EVENT_H
