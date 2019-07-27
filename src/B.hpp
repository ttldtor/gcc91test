#pragma once

#include <memory>
#include "Shareable.hpp"

struct B : Shareable {
  virtual void setA(std::shared_ptr<Shareable> a) = 0;
};
