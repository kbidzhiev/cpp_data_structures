#include "ring_buffer.hpp"
#include <gtest/gtest.h>

TEST(RingBuffer, constructor) {
  const size_t sz = 3;
  Containers::ring_buffer<int> rb{sz};
  EXPECT_EQ(rb.size(), 0);
  EXPECT_EQ(rb.capacity(), sz);
}

TEST(RingBuffer, push) {
  const size_t sz = 2;
  Containers::ring_buffer<int> rb{sz};

  EXPECT_TRUE(rb.push(10));
  EXPECT_EQ(rb.size(), 1);

  EXPECT_TRUE(rb.push(20));
  EXPECT_EQ(rb.size(), 2);

  EXPECT_FALSE(rb.push(30));
  EXPECT_EQ(rb.size(), 2);
}

TEST(RingBuffer, pop) {
  const size_t sz = 2;
  Containers::ring_buffer<int> rb{sz};

  EXPECT_TRUE(rb.push(10));
  EXPECT_TRUE(rb.push(20));
  EXPECT_EQ(rb.size(), 2);

  EXPECT_TRUE(rb.pop());
  EXPECT_EQ(rb.size(), 1);

  EXPECT_TRUE(rb.pop());
  EXPECT_EQ(rb.size(), 0);

  EXPECT_FALSE(rb.pop());
}
