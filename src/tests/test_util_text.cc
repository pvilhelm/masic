#include <catch.hpp>
#include "../base/util/str.hh"
#include <string>

using namespace std;
using namespace util;

TEST_CASE("General tests text")
{
  SECTION("Just ctor it")
  {
    text t1;
    text t2(string{"Hi"});
  }

  SECTION("Test shared pointer")
  {
    text t1;
    REQUIRE(t1.sp_this.use_count() == 1);
    auto sp = t1.shared_from_this();
    REQUIRE(sp.use_count() == 2);
      
  }
}
