#pragma once

#include <future>

struct F final {
  std::future<int> foo();
};
