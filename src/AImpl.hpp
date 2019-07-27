#pragma once

#include <memory>
#include <shared_mutex>

#include "B.hpp"
#include "A.hpp"

class AImpl final : public A {
  std::shared_mutex mutex_;
  std::weak_ptr<B> b_;

public:

  AImpl() : mutex_{} {}

  void setB(std::shared_ptr<Shareable> b) override {
    std::unique_lock lock(mutex_);

    auto newB = b->getSharedFromThisAs<B>();

    if (!newB) {
      return;
    }

    b_ = newB;
  }

  static std::shared_ptr<A> create() {
    return std::make_shared<AImpl>();
  }
};