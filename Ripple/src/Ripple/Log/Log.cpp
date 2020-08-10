//
// Created by ismaele on 10/08/20.
//

#include "Log.h"

namespace Ripple {

  log_ptr Log::sCoreLogger;
  log_ptr Log::sClientLogger;

  void Log::Init() {
    spdlog::set_pattern("%^[%T] %n: %v %$");

    sCoreLogger = spdlog::stdout_color_mt("Ripple");
    sCoreLogger->set_level(spdlog::level::trace);

    sClientLogger = spdlog::stdout_color_mt("Client");
    sClientLogger->set_level(spdlog::level::trace);
  }

}