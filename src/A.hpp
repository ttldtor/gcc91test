#pragma once

#include <memory>
#include "Shareable.hpp"

struct A : Shareable {
  virtual void setB(std::shared_ptr<Shareable> b) = 0;
};