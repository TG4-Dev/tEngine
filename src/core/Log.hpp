#include "spdlog/logger.h"

namespace core {
class Log {
public:
  static void Init();

  inline static std::shared_ptr<spdlog::logger> &GetCoreLogger() {
    return s_core_logger;
  }

  inline static std::shared_ptr<spdlog::logger> &GetClientLogger() {
    return s_client_logger;
  }

private:
  static std::shared_ptr<spdlog::logger> s_core_logger;
  static std::shared_ptr<spdlog::logger> s_client_logger;
};



//core::log::getcorelogger()->warn("init log");


#define TE_CORE_TRACE(...)    ::core::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define TE_CORE_INFO(...)     ::core::Log::GetCoreLogger()->info(__VA_ARGS__)
#define TE_CORE_WARN(...)     ::core::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define TE_CORE_ERROR(...)    ::core::Log::GetCoreLogger()->error(__VA_ARGS__)
#define TE_CORE_CRITICAL(...) ::core::Log::GetCoreLogger()->critical(__VA_ARGS__)


#define TE_TRACE(...)         ::core::Log::GetClientLogger()->trace(__VA_ARGS__)
#define TE_INFO(...)          ::core::Log::GetClientLogger()->info(__VA_ARGS__)
#define TE_WARN(...)          ::core::Log::GetClientLogger()->warn(__VA_ARGS__)
#define TE_ERROR(...)         ::core::Log::GetClientLogger()->error(__VA_ARGS__)
#define TE_CRITICAL(...)      ::core::Log::GetClientLogger()->critical(__VA_ARGS__)
} // namespace core
