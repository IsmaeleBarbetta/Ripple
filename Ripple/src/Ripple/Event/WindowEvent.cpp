//
// Created by ismaele on 10/08/20.
//

#include "WindowEvent.h"

namespace Ripple {



// WindowResizeEvent
unsigned int WindowResizeEvent::getUWidth() const { return uWidth; }
void WindowResizeEvent::setUWidth(unsigned int width) {
  WindowResizeEvent::uWidth = width;
}
unsigned int WindowResizeEvent::getUHeight() const { return uHeight; }
void WindowResizeEvent::setUHeight(unsigned int height) {
  WindowResizeEvent::uHeight = height;
}

}