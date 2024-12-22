#include "s21_array.h"

namespace s21 {

template <typename T, std::size_t N>
array<T, N>::array() : size_(N) {}

template <typename T, std::size_t N>
array<T, N>::array(std::initializer_list<value_type> const &items) {
  size_type i = 0;
  for (auto it = items.begin(); it != items.end(); ++it, ++i) {
    elems_[i] = *it;
  }
}

template <typename T, std::size_t N>
array<T, N>::array(const array &a) {
  for (size_type i = 0; i < N; ++i) {
    elems_[i] = a.elems_[i];
  }
}

template <typename T, std::size_t N>
array<T, N>::array(array &&a) {
  for (size_type i = 0; i < N; ++i) {
    elems_[i] = std::move(a.elems_[i]);
  }
}

template <typename T, std::size_t N>
array<T, N>::~array() {}

template <typename T, std::size_t N>
array<T, N> &array<T, N>::operator=(array &&a) {
  if (this != &a) {
    for (size_type i = 0; i < N; ++i) {
      elems_[i] = std::move(a.elems_[i]);
    }
  }
  return *this;
}

template <typename T, std::size_t N>
typename array<T, N>::reference array<T, N>::at(size_type pos) {
  if (pos < size_) {
    return elems_[pos];
  } else
    throw std::out_of_range(
        "ERROR! Pos is not within the range of the container!");
}

template <typename T, std::size_t N>
typename array<T, N>::reference array<T, N>::operator[](size_type pos) {
  return elems_[pos];
}

template <typename T, std::size_t N>
typename array<T, N>::const_reference array<T, N>::front() {
  return elems_[0];
}

template <typename T, std::size_t N>
typename array<T, N>::const_reference array<T, N>::back() {
  return elems_[size_ - 1];
}

template <typename T, std::size_t N>
typename array<T, N>::iterator array<T, N>::data() {
  return elems_;
}

template <typename T, std::size_t N>
typename array<T, N>::iterator array<T, N>::begin() noexcept {
  return &elems_[0];
}

template <typename T, std::size_t N>
typename array<T, N>::iterator array<T, N>::end() noexcept {
  return &elems_[size_];
}

template <typename T, std::size_t N>
bool array<T, N>::empty() {
  return size_ == 0;
}

template <typename T, std::size_t N>
typename array<T, N>::size_type array<T, N>::size() {
  return size_;
}

template <typename T, std::size_t N>
typename array<T, N>::size_type array<T, N>::max_size() {
  return N;
}

template <typename T, std::size_t N>
void array<T, N>::swap(array &other) {
  std::swap(elems_, other.elems_);
}

template <typename T, std::size_t N>
void array<T, N>::fill(const_reference value) {
  for (size_type i = 0; i < N; ++i) {
    elems_[i] = value;
  }
}

};  // namespace s21
