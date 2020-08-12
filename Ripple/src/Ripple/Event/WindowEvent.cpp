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
std::string WindowResizeEvent::toString() const {
  std::stringstream ss;
  ss << "WindowResizeEvent: " << uWidth << "x" << uHeight;
  return ss.str();
}

// WindowMoveEvent
std::string WindowMoveEvent::toString() const {
  std::stringstream ss;
  ss << "WindowMoveEvent: " << fX << "x" << fY;
  return ss.str();
}

// WindowFocusEvent
std::string WindowFocusEvent::toString() const {
  std::stringstream ss;
  ss << "WindowFocusEvent";
  return ss.str(); }

// WindowLostFocusEvent
std::string WindowLostFocusEvent::toString() const {
  std::stringstream ss;
  ss << "WindowLostFocusEvent:";
  return ss.str();
}

// WindowCloseEvent
std::string WindowCloseEvent::toString() const {
  std::stringstream ss;
  ss << "WindowCloseEvent";
  return ss.str();
}
}