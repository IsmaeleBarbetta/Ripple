//
// Created by ismaele on 12/08/20.
//

#ifndef RIPPLE_MOUSEEVENT_H
#define RIPPLE_MOUSEEVENT_H

#include "Event.h"

namespace Ripple {

class MouseButton : public Event {
public:
  MouseButton(int mouseCode) : mMouseCode(mouseCode) {}

  int getMouseButton() const { return mMouseCode; }

  SET_CATEGORY(EC_MOUSE | EC_INPUT)

protected:
  int mMouseCode;
};

class MouseButtonPressed : public MouseButton {
public:
  MouseButtonPressed(int mouseCode) : MouseButton(mouseCode) {}

  SET_TYPE(MouseButtonPressed)

  std::string toString() const override;
};

class MouseButtonReleased : public MouseButton {
public:
  MouseButtonReleased(int mouseCode) : MouseButton(mouseCode) {}

  SET_TYPE(MouseButtonReleased)

  std::string toString() const override;
};

class MouseMovedEvent : public Event {
public:
  MouseMovedEvent(float x, float y) : mMouseX(x), mMouseY(y) {}

  float getX() const { return mMouseX; }
  float getY() const { return mMouseY; }

  SET_TYPE(MouseMoved)
  SET_CATEGORY(EC_MOUSE | EC_INPUT)

  std::string toString() const override;

private:
  float mMouseX, mMouseY;
};

class MouseScrolledEvent : public Event {
public:
  MouseScrolledEvent(float xOff, float yOff) : mOffsetX(xOff), mOffsetY(yOff) {}

  float getOffsetX() const { return mOffsetX; }
  float getOffsetY() const { return mOffsetY; }

  SET_TYPE(MouseScrolled)
  SET_CATEGORY(EC_MOUSE | EC_INPUT)

private:
  float mOffsetX, mOffsetY;
};

} // namespace Ripple

#endif // RIPPLE_MOUSEEVENT_H
