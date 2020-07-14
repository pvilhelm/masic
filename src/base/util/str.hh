#include <string>
#include <memory>

#include "common.hh"

namespace util {


  
  class text : public std::enable_shared_from_this<text> {
  public:
    freind text_range;
    
    text() : text("") {}

    text(const str &ss) : s(ss)
    {
      /* Make a shared pointer with no deleter action to itself to use in 
       * text ranges. */
      sp_this = sp<text>(this, [](const text *) {});
    }
    
  PRIVATE_SCOPE:
    /* Pointer for text_ranges to make sure they are not dangeling. */
    sp<text> sp_this;
    str s;
  };

  class text_range {
  public:
    text_range(text &t) : wp_text(t.weak_from_this()) {}

    bool starts_with(const str s) const;
    bool ends_with(const str s) const;
    bool contains(const str s) const;
    bool contains_any_char_of(const str s) const;
    bool contains_any_word_of(const vec<str> v) const;
    str /* first word */ starts_with_which_of(const vec<str> v) const;
    bool starts_with_any_of(const vec<str> v) const;
    str to_string() const;

    /* Numbers of chars in the text. */
    size_t size() const;
    /* Number of rows from the start of underlying text to the start of the range. */
    size_t rows_into_text() const;
    /* Number of columns from the prior nl to the start of the range. */
    size_t cols_into_text() const;
    /* Number of character from the start of underlying text to the range. */
    size_t chars_into_text() const;
    /* Number of rows in the range. */
    size_t n_rows() const;
    /* Number of columns in the range. Doesnt count nl. */
    size_t n_cols() const;
    /* Number of space separated words in the range. */
    size_t n_words() const;

    /* Range modifying functions. */
    void skip_ws();
    void skip_n(size_t);
    
    str::iterator end();
    str::iterator begin();
    str::const_iterator cend();
    str::const_iterator cbegin();
    
  PRIVATE_SCOPE:
    wp<text> wp_text;
    
  };
}
