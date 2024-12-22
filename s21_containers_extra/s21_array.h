#ifndef S21_ARRAY_H
#define S21_ARRAY_H

#include <iostream>

namespace s21 {

template <typename T, std::size_t N>
class array {
 public:
  // Member type
  using value_type = T;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = value_type *;
  using const_iterator = const value_type *;
  using size_type = size_t;

  size_type size_ = N;
  value_type elems_[N] = {};

  // Member functions
  array();
  array(std::initializer_list<value_type> const &items);
  array(const array &a);
  array(array &&a);
  ~array();
  array &operator=(array &&a);

  // Element access
  reference at(size_type pos);
  reference operator[](size_type pos);
  const_reference front();
  const_reference back();
  iterator data();

  // Iterators
  iterator begin() noexcept;
  iterator end() noexcept;

  // Capacity
  bool empty();
  size_type size();
  size_type max_size();

  // Modifiers
  void swap(array &other);
  void fill(const_reference value);
};
};  // namespace s21

#include "s21_array.tpp"

#endif  // S21_ARRAY_H