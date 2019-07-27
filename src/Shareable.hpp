#pragma once

#include <memory>

struct Shareable : std::enable_shared_from_this<Shareable> {
  template<typename Down>
  std::shared_ptr<Down> getSharedFromThisAs() {
    return std::dynamic_pointer_cast<Down>(shared_from_this());
  }

  virtual ~Shareable() = default;
};