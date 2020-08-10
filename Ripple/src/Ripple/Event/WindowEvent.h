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

    SET_TYPE(WindowMove);
    SET_CATEGORY(EC_APPLICATION);

  private:
    float fX, fY;
  };

  class WindowResizeEvent : public Event{
  public:
    WindowResizeEvent(unsigned int width, unsigned int height) : uWidth(width), uHeight(height) {}
    unsigned int getUWidth() const;
    void setUWidth(unsigned int uWidth);
    unsigned int getUHeight() const;
    void setUHeight(unsigned int uHeight);

  private:
    unsigned int uWidth, uHeight;
  };



}

#endif // RIPPLE_WINDOWEVENT_H
