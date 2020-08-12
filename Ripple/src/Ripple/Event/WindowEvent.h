//
// Created by ismaele on 10/08/20.
//

#ifndef RIPPLE_WINDOWEVENT_H
#define RIPPLE_WINDOWEVENT_H

#include "Event.h"

namespace Ripple {

  class WindowMoveEvent : public Event {
  public:
    WindowMoveEvent(float x, float y) : fX(x), fY(y) {}
    ~WindowMoveEvent() = default;

    SET_TYPE(WindowMove);
    SET_CATEGORY(EC_APPLICATION);

    std::string toString() const override;

  private:
    float fX, fY;
  };

  class WindowResizeEvent : public Event{
  public:
    WindowResizeEvent(unsigned int width, unsigned int height) : uWidth(width), uHeight(height) {}
    ~WindowResizeEvent() = default;

    unsigned int getUWidth() const;
    void setUWidth(unsigned int uWidth);
    unsigned int getUHeight() const;
    void setUHeight(unsigned int uHeight);

    SET_TYPE(WindowResize)
    SET_CATEGORY(EC_APPLICATION)

    std::string toString() const override;

  private:
    unsigned int uWidth, uHeight;
  };

  class WindowFocusEvent : public Event {
  public:
    WindowFocusEvent() = default;
    ~WindowFocusEvent() = default;

    SET_TYPE(WindowFocus)
    SET_CATEGORY(EC_APPLICATION)

    std::string toString() const override;
  };

  class WindowLostFocusEvent : public Event {
  public:
    WindowLostFocusEvent() = default;
    ~WindowLostFocusEvent() = default;

    SET_TYPE(WindowLostFocus)
    SET_CATEGORY(EC_APPLICATION)

    std::string toString() const override;
  };

  class WindowCloseEvent : public Event {
  public:
    WindowCloseEvent() = default;
    ~WindowCloseEvent() = default;

    SET_TYPE(WindowClose)
    SET_CATEGORY(EC_APPLICATION)

    std::string toString() const override;

  };

}

#endif // RIPPLE_WINDOWEVENT_H
