#include "Log.hpp"
#include "spdlog/common.h"
#include "spdlog/logger.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/spdlog.h"

namespace core {

std::shared_ptr<spdlog::logger> Log::s_core_logger;
std::shared_ptr<spdlog::logger> Log::s_client_logger;

void core::Log::Init() {
  std::vector<spdlog::sink_ptr> logSinks;
  logSinks.emplace_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
  logSinks.emplace_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>("tEngine.log", true));


  logSinks[0]->set_pattern("%^[%T] %n: %v%$");
  logSinks[1]->set_pattern("[%T] [%l] %n: %v");

  s_core_logger = std::make_shared<spdlog::logger>("tEngine", begin(logSinks), end(logSinks));
  spdlog::register_logger(s_core_logger);
  s_core_logger->set_level(spdlog::level::trace);
  s_core_logger->flush_on(spdlog::level::trace);

  s_client_logger = std::make_shared<spdlog::logger>("APP", begin(logSinks), end(logSinks));
  spdlog::register_logger(s_client_logger);
  s_client_logger->set_level(spdlog::level::trace);
  s_client_logger->flush_on(spdlog::level::trace);}
} // namespace core
