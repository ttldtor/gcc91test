#pragma once

#include <thread>
#include <mutex>

#include <B.hpp>
#include <A.hpp>

class BImpl final : public B {
  std::recursive_mutex mutex_;

  std::weak_ptr<A> a_;

public:

  BImpl() : mutex_{} {}

  void setA(std::shared_ptr<Shareable> a) override {
    std::lock_guard lock(mutex_);

    auto newA = a->getSharedFromThisAs<A>();

    if (!newA) {
      return;
    }

    a_ = newA;
  }

  static std::shared_ptr<B> create() {
    return std::make_shared<BImpl>();
  }
};
