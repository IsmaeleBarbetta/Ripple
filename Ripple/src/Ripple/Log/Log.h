//
// Created by ismaele on 10/08/20.
//

#ifndef RIPPLE_LOG_H
#define RIPPLE_LOG_H

#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/spdlog.h"

#define RP_CORE_FATAL(...) ::Ripple::Log::getCoreLogger()->fatal(__VA_ARGS__)
#define RP_CORE_ERROR(...) ::Ripple::Log::getCoreLogger()->error(__VA_ARGS__)
#define RP_CORE_WARN(...) ::Ripple::Log::getCoreLogger()->warn(__VA_ARGS__)
#define RP_CORE_INFO(...) ::Ripple::Log::getCoreLogger()->info(__VA_ARGS__)
#define RP_CORE_TRACE(...) ::Ripple::Log::getCoreLogger()->trace(__VA_ARGS__)

#define RP_FATAL(...) ::Ripple::Log::getClientLogger()->fatal(__VA_ARGS__)
#define RP_ERROR(...) ::Ripple::Log::getClientLogger()->error(__VA_ARGS__)
#define RP_WARN(...) ::Ripple::Log::getClientLogger()->warn(__VA_ARGS__)
#define RP_INFO(...) ::Ripple::Log::getClientLogger()->info(__VA_ARGS__)
#define RP_TRACE(...) ::Ripple::Log::getClientLogger()->trace(__VA_ARGS__)

namespace Ripple {

typedef std::shared_ptr<spdlog::logger> log_ptr;

class Log {
public:
  static void Init();

  static log_ptr& getCoreLogger() { return sCoreLogger; }
  static log_ptr& getClientLogger() { return sClientLogger; }

private:
  static log_ptr sCoreLogger;
  static log_ptr sClientLogger;
};

}

#endif // RIPPLE_LOG_H
