#pragma once

#include <utility>

template <typename Handle, typename Deleter> class unique_handle {
  Handle h_{};
  Deleter d_{};

public:
  unique_handle() = default;
  unique_handle(Handle h, Deleter d) : h_(h), d_(d) {}
  ~unique_handle() { reset(); }

  unique_handle(const unique_handle &) = delete;
  unique_handle &operator=(const unique_handle &) = delete;

  unique_handle(unique_handle &&other) noexcept
      : h_(other.h_), d_(std::move(other.d_)) {
    other.h = {};
  }
  unique_handle &operator=(unique_handle &&other) noexcept {
    if (this != &other) {
      reset();
      h_ = other.h_;
      d_ = std::move(other.d_);
      other.h_ = {};
    }
    return *this;
  }

  void reset() {
    if (h_) {
      d_(h_);
      h_ = {};
    }
  }

  Handle get() const { return h_; }
  explicit operator bool() const { return h_ != Handle{}; }
};
