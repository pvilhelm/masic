#include <map>
#include <memory>
#include <vector>
#include <string>

namespace interpreter {
  using sp = std::shared_ptr;
  
  class expression;
  class statement;
  class symbol;
  class value;
  class type;
  class scope;
  class stack;
  class heap;
  class code;
  class program;
  class userspace;

  class machine;
  
  class symbol {
  public:
    std::string name;

    value virtual &get_value() const = 0;
    void virtual set_value(value &v) = 0;
  private:
    /* TODO: Pekare till value */
    /* TODO: Pekare till scope. */
  };

  class scope {
  public:
    sp<symbol> find_symbol(std::string name);
    void push_symbol(sp<symbol> symbol);
    sp<symbol> find_symbol_top_scope(std::string name);
  private:
    /* TODO: Pekare till förälder */
    std::vector<sp<symbol>> v_sptr_symbols;
  };

  class stack {
  public:
    sp<symbol> find_symbol_highest(std::string name);
    void push_stack(sp<symbol> sptr_symbol);
    sp<symbol> pop_stack();
    void pop_stack(size_t n);
    
  private:
    std::vector<sp<symbol>> v_stack;
  };
    
  class userspace {
  public:
    machine machine;
    program &load_program(std::string code, std::string name);
    void execute_program(std::string name);
    void execute_code(std::string code);
  private:
  };
}
