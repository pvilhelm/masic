#include "interpreter.hh"
#include <stdexcept>

namespace interpreter {
  void stack::pop_stack(size_t n)
  {
    if (n > v_stack.size())
      throw std::runtime_error("Popping empty stack");
    
    v_stack.erase(v_stack.end() - n, v_stack.end());

    return;
  }

  sp<symbol> stack::pop_stack()
  {
    if (v_stack.size()) {
      sp<symbol> ret = v_stack.back();
      v_stack.pop_back();
      return ret;
    }
    throw std::runtime_error("Popping empty stack");      
  }
 
}
