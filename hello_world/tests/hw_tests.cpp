#include "hw.hpp"
#include <gtest/gtest.h>


TEST(Hello_world, returns) {
  auto hw = HW::hello();
  EXPECT_EQ(hw, "Hello, world");
}

