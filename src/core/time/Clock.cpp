#include "Clock.hpp"

namespace core::time {
  Clock::Clock()
  {
    m_start_time = std::chrono::steady_clock::now();
    m_last_tick = m_start_time;
    m_last_delta = 0.0;
  }

  std::chrono::steady_clock::time_point Clock::Now()
  {
    return std::chrono::steady_clock::now();
  }

  double Clock::SinceStart() const
  {
    auto now = std::chrono::steady_clock::now();
    return std::chrono::duration<double, std::milli>(now - m_start_time).count();
  }

  double Clock::Tick()
  {
    auto now = std::chrono::steady_clock::now();
    auto delta = now - m_last_tick;
    m_last_tick = now;
    m_last_delta = std::chrono::duration<double>(delta).count();

    return m_last_delta;
  }

  double Clock::LastDelta() const
  {
    return m_last_delta;
  }
  double Clock::Fps() const
  {
    return 1 / m_last_delta;
  }
}
