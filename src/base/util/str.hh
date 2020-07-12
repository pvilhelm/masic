#include <string>
#include <memory>

namespace util {

  class text : public std::enable_shared_from_this<text>, public std::string {
  public:
    text()
    {
      /* Make a shared pointer with no deleter action to itself to use in 
       * text ranges. */
      sp_this = std::shared_ptr<text>(this, [](const text *) {});
    }

    text(const std::string &ss) : text(), s(ss) {}
    
  private:
    std::shared_ptr<text> sp_this;
    std::string s;
  };

  class text_range {
  public:
    
  private:
    std::weak_ptr<text> wp_text;    
  };
}
