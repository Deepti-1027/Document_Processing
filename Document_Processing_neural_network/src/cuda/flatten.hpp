#pragma once

#include <layer.hpp>
#include <storage.hpp>

class Flatten : public Layer {
 public:
  Flatten(bool inplace) : inplace(inplace) {}

  void forward();
  void backward();

  Storage *get_grad() {
    return this->inplace ? this->next->get_grad() : this->grad.get();
  }
  Storage *get_output() {
    return this->inplace ? this->pre->get_output() : this->output.get();
  }

 private:
  std::vector<int> in_shape;
  bool inplace;
};