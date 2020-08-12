//
// Created by ismaele on 12/08/20.
//

#ifndef RIPPLE_KEYBOARDEVENT_H
#define RIPPLE_KEYBOARDEVENT_H

#include "Event.h"

namespace Ripple {

class KeyEvent : public Event {
public:
  explicit KeyEvent(int keyCode) : mKeyCode(keyCode) {}

  int getKeyCode() const { return mKeyCode; }

  SET_CATEGORY(EC_KEYBOARD | EC_INPUT)

protected:
  int mKeyCode;
};

class KeyPressedEvent : public KeyEvent {
public:
  KeyPressedEvent(int keyCode, int repeat) : KeyEvent(keyCode), mRepeatCount(repeat) {}

  int getRepeatCount() const { return mRepeatCount; }

  SET_TYPE(KeyPressed)

  std::string toString() const override;

private:
  int mRepeatCount;
};

class KeyReleasedEvent : public KeyEvent {
public:
  explicit KeyReleasedEvent(int keyCode) : KeyEvent(keyCode) {}

  std::string toString() const override;

  SET_TYPE(KeyReleased)
};

} // namespace Ripple

#endif // RIPPLE_KEYBOARDEVENT_H
