#include "core/Log.hpp"
#include <cstdio>

int main() {
  core::Log::Init();
  core::Log::GetCoreLogger()->warn("Init log");
  core::Log::GetClientLogger()->warn("Init log");

  return 0;
}
