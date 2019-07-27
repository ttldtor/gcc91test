#include "BImpl.hpp"
#include "AImpl.hpp"
#include "Holder.hpp"

Holder::Holder(std::shared_ptr<A> a, std::shared_ptr<B> b)
    : a{std::move(a)}, b{std::move(b)} {}

std::shared_ptr<Holder> Holder::create() {
  auto a = AImpl::create();
  auto b = BImpl::create();

  a->setB(b);
  b->setA(a);

  return std::make_shared<Holder>(a, b);
}