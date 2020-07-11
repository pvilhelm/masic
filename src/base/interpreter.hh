#include <map>
#include <memory>
#include <vector>
#include <string>

namespace interpreter {

  template <typename T>
  using sp = std::shared_ptr<T>;
  
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
  class value {
  public:
    value() = 0;
    virtual ~value() = 0;
    /* object is not copyable. */
    value(const value&) = delete;
    value &operator=(const value&) = delete;
    
    bool virtual is_primitive() const = 0;
    bool virtual is_integer() const = 0;
    bool virtual is_float() const = 0;
    std::string to_string() const = 0;
  };
  
  class symbol {
  public:
    symbol() = default;
    /* object is not copyable. */
    symbol(const symbol&) = delete;
    symbol& operator=(const symbol&) = delete;
    
    std::string name;   

    value virtual &get_value() const = 0;
    void virtual set_value(value &v) = 0;
  private:
    sp<value> sp_value;
    /* TODO: Pekare till value */
    /* TODO: Pekare till scope. */
  };

  class scope {
  public:
    scope(sp<scope> parent_scope) : parent_scope(parent_scope) {};
    /* object is not copyable. */
    scope(const scope&) = delete;
    scope& operator=(const scope&) = delete;
    
    sp<symbol> find_symbol(std::string name);
    void push_symbol(sp<symbol> symbol);
    sp<symbol> find_symbol_inner_scope(std::string name);
  private:
    sp<scope> parent_scope;
    std::vector<sp<symbol>> v_sp_symbols;
  };

  class stack {
  public:
    sp<symbol> find_symbol_highest(std::string name);
    void push_stack(sp<symbol> sptr_symbol);
    sp<symbol> pop_stack();
    sp<symbol> pop_stack(size_t n);
    
  private:
    std::vector<sp<symbol>> v_stack;
  };

  class machine {

  };
  
  class userspace {
  public:
    machine machine;
    program &load_program(std::string code, std::string name);
    void execute_code(std::string code);
  private:
    sp<scope> sp_user_scope;
  };
}
