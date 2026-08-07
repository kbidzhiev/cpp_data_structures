#include "hello_world.hpp"
#include <gtest/gtest.h>


TEST(Hello_world, returns) {
  auto hw = hello_world_namespace::hello();
  EXPECT_EQ(hw, "Hello, World");
}

