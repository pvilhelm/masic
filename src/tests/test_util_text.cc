#include <catch.hpp>
#include "../base/util/str.hh"
#include <string>

using namespace std;
using namespace util;

TEST_CASE("General test")
{
  SECTION("Just ctor it")
  {
    text t1;
    text t2(string{"Hi"});
  }
}
