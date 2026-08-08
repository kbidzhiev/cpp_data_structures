#pragma once

#include <vector>

namespace CONTAINERS {

template <typename T> class ring_buffer {
  size_t size_;
  size_t begin_, end_;
  std::vector<T> data_;

public:
  ring_buffer(size_t sz) { data_.reserve(sz); }
  size_t size() const { return size_; }
  size_t capacity() const { return data_.capacity(); }

private:
  bool is_full() const { return size_ == capacity(); }
  bool is_empty() const {
    if (begin_ == end_ && !is_full())
      return true;
    return false;
  }

public:
  bool push(const T &elem) {
    if (is_full())
      return false;
    data_[end_++] = T;
    end_ %= capacity();
    ++size_;
    return true;
  }
  bool pop() {
    if (is_empty())
      return false;
    ++begin;
    begin %= capacity;
    --size_;
    return true;
  }
};

} // namespace CONTAINERS
