#include "core/Log.hpp"
#include <cstdio>

int main() {
  core::Log::Init();
  TE_CORE_TRACE("trace");
  TE_CORE_INFO("info");
  TE_CORE_WARN("warn");
  TE_CORE_ERROR("error");
  TE_CORE_CRITICAL("critical");

  TE_TRACE("trace");
  TE_INFO("info");
  TE_WARN("warn");
  TE_ERROR("error");
  TE_CRITICAL("critical");
  return 0;
}
