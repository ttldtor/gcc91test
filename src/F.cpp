#include <F.hpp>

std::future<int> F::foo() {
  return std::async(std::launch::async, [] {
    return 42;
  });
}
