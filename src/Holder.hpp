#pragma once

#include "B.hpp"
#include "A.hpp"
#include "Shareable.hpp"

struct Holder : Shareable {
  std::shared_ptr<A> a;
  std::shared_ptr<B> b;

  Holder(std::shared_ptr<A> a, std::shared_ptr<B> b);

  static std::shared_ptr<Holder> create();
};
