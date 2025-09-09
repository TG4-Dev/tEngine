#pragma once 
#include <chrono>

namespace core::time {
  class Clock {
  public:
   Clock();

   std::chrono::steady_clock::time_point Now();
   double SinceStart() const;
   double Tick();
   double LastDelta() const;
   double Fps() const;
  private:
    std::chrono::steady_clock::time_point m_start_time;
    std::chrono::steady_clock::time_point m_last_tick;
    double m_last_delta;
  };
}