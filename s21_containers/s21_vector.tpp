#include "s21_vector.h"

namespace s21 {
template <typename T>
vector<T>::vector() : size_(0), capacity_(0), vector_(nullptr) {}

template <typename T>
vector<T>::vector(size_type n)
    : size_(n), capacity_(n), vector_(new value_type[capacity_]) {
  if (n < 0) throw std::invalid_argument("Size must be non-negative");
  std::fill_n(vector_, n, value_type());
}

template <typename T>
vector<T>::vector(std::initializer_list<value_type> const &items) {
  size_ = items.size();
  capacity_ = size_;
  vector_ = new value_type[capacity_];
  size_type i = 0;
  for (auto item : items) {
    vector_[i] = item;
    i++;
  }
}

template <typename T>
vector<T>::vector(const vector &v) {
  if (vector_ != nullptr) delete[] vector_;
  size_ = v.size_;
  capacity_ = v.capacity_;
  vector_ = new value_type[capacity_];
  size_type i = 0;
  while (i < size_) {
    vector_[i] = v.vector_[i];
    i++;
  }
}

template <typename T>
vector<T>::vector(vector &&v) {
  if (vector_ != nullptr) delete[] vector_;
  size_ = std::exchange(v.size_, 0);
  capacity_ = std::exchange(v.capacity_, 0);
  vector_ = std::exchange(v.vector_, nullptr);
}

template <typename T>
vector<T>::~vector() {
  delete[] vector_;
  capacity_ = 0;
  size_ = 0;
}

template <typename T>
bool vector<T>::empty() {
  return size_ == 0;
}

template <typename T>
void vector<T>::reserve(size_type new_capacity) {
  if (new_capacity <= capacity_) {
    return;
  }

  if (new_capacity > max_size()) {
    throw std::out_of_range("ReserveError: Too large size for a new capacity");
  }

  auto new_data = new value_type[new_capacity];
  std::copy(vector_, vector_ + size_, new_data);
  delete[] vector_;
  vector_ = new_data;
  capacity_ = new_capacity;
}

template <typename T>
typename vector<T>::size_type vector<T>::size() {
  return size_;
}

template <typename T>
typename vector<T>::size_type vector<T>::capacity() {
  return capacity_;
}

template <typename T>
typename vector<T>::size_type vector<T>::max_size() const {
  return std::numeric_limits<std::size_t>::max() / sizeof(value_type);
}

template <typename T>
typename vector<T>::reference vector<T>::at(size_type pos) {
  if (pos >= 0 && pos < size_) return *(vector_ + pos);
  throw std::out_of_range("Out of bounds element access");
}

template <typename T>
typename vector<T>::const_reference vector<T>::front() const {
  if (vector_ != nullptr && size_ > 0) return vector_[0];
  throw std::out_of_range("Out of bounds element access");
}

template <typename T>
typename vector<T>::const_reference vector<T>::back() const {
  if (vector_ != nullptr && size_ > 0) return vector_[size_ - 1];
  throw std::out_of_range("Out of bounds element access");
}

template <typename T>
void vector<T>::shrink_to_fit() {
  if (size_ < capacity_) {
    auto new_data = new value_type[size_];
    std::copy(vector_, vector_ + size_, new_data);
    delete[] vector_;
    vector_ = new_data;
    capacity_ = size_;
  }
}

template <typename T>
void vector<T>::clear() {
  if (vector_ != nullptr) {
    delete[] vector_;
    vector_ = nullptr;
    size_ = 0;
  }
}

template <typename T>
typename vector<T>::iterator vector<T>::begin() {
  return iterator(vector_);
}

template <typename T>
typename vector<T>::iterator vector<T>::end() {
  return iterator(vector_ + size_);
}

template <typename T>
void vector<T>::push_back(const_reference value) {
  if (size_ == capacity_) {
    reserve(capacity_ ? capacity_ * 2 : 1);
  }
  vector_[size_++] = value;
}

template <typename T>
void vector<T>::pop_back() {
  if (size_ > 0) size_--;
}

template <typename T>
void vector<T>::swap(vector<T> &other) {
  std::swap(vector_, other.vector_);
  std::swap(size_, other.size_);
  std::swap(capacity_, other.capacity_);
}

template <typename T>
typename vector<T>::iterator vector<T>::insert(iterator pos,
                                               const_reference value) {
  iterator new_pos;
  size_type idx = pos - begin();

  if (idx > size_) {
    throw std::out_of_range(
        "InsertError: The insertion position is out of range of the vector "
        "memory");
  }

  if (size_ == capacity_) {
    reserve(capacity_ ? capacity_ * 2 : 1);
  }

  new_pos = begin() + idx;
  for (iterator it = end(); it != new_pos; --it) *it = *(it - 1);

  *new_pos = value;
  ++size_;

  return new_pos;
}

template <typename T>
void vector<T>::erase(iterator pos) {
  size_type del_idx = pos - vector_;

  if (del_idx > size_)
    throw std::out_of_range("EraseError: Index out of range");

  for (iterator it = pos; it != end() - 1; ++it) *it = *(it + 1);
  --size_;
}

// OPERATORS
template <typename T>
typename vector<T>::reference vector<T>::operator[](size_type pos) {
  if (pos >= 0 && pos < size_) return *(vector_ + pos);
  throw std::out_of_range("Out of bounds element access");
}

template <typename T>
typename vector<T>::const_reference vector<T>::operator[](size_type pos) const {
  if (pos >= 0 && pos < size_) return *(vector_ + pos);
  throw std::out_of_range("Out of bounds element access");
}

template <typename T>
T *vector<T>::data() {
  return vector_;
}

template <typename T>
vector<T> &vector<T>::operator=(const vector &v) {
  if (vector_ != nullptr) delete[] vector_;
  size_ = v.size_;
  capacity_ = v.capacity_;
  vector_ = new T[capacity_];
  size_type i = 0;
  while (i < size_) {
    vector_[i] = v.vector_[i];
    i++;
  }
  return *this;
}

template <typename T>
vector<T> &vector<T>::operator=(vector &&v) {
  if (vector_ != nullptr) delete[] vector_;
  size_ = std::exchange(v.size_, 0);
  capacity_ = std::exchange(v.capacity_, 0);
  vector_ = std::exchange(v.vector_, nullptr);
  return *this;
}

// VECTOR ITERATOR
template <typename T>
vector<T>::VectorIterator::VectorIterator() : current_(nullptr) {}

template <typename T>
vector<T>::VectorIterator::VectorIterator(T *current_) : current_(current_) {}

template <typename T>
typename vector<T>::reference vector<T>::VectorIterator::operator*() const {
  return *current_;
}
template <typename T>
typename vector<T>::value_type *vector<T>::VectorIterator::operator->() const {
  return &current_;
}

template <typename T>
typename vector<T>::iterator &vector<T>::VectorIterator::operator++() {
  current_++;
  return *this;
}

template <typename T>
typename vector<T>::iterator vector<T>::VectorIterator::operator++(int n) {
  for (int i = 0; i < n; i++) {
    ++(*this);
  }
  return *this;
}

template <typename T>
bool vector<T>::VectorIterator::operator==(const VectorIterator &other) const {
  return current_ == other.current_;
}

template <typename T>
bool vector<T>::VectorIterator::operator!=(const VectorIterator &other) const {
  return current_ != other.current_;
}

template <typename T>
typename vector<T>::iterator &vector<T>::VectorIterator::operator--() {
  current_--;
  return *this;
}

template <typename T>
typename vector<T>::iterator vector<T>::VectorIterator::operator--(int n) {
  for (int i = 0; i < n; i++) {
    --(*this);
  }
  return *this;
}

template <typename T>
typename vector<T>::size_type vector<T>::VectorIterator::operator-(
    const iterator &other) const {
  return std::distance(other.current_, current_);
}

template <typename T>
typename vector<T>::iterator vector<T>::VectorIterator::operator+(
    size_type n) const {
  VectorIterator temp = *this;
  temp.current_ += n;
  return temp;
}

template <typename T>
typename vector<T>::iterator vector<T>::VectorIterator::operator-(
    size_type n) const {
  VectorIterator temp = *this;
  temp.current_ -= n;
  return temp;
}

// CONST VECTOR ITERATOR

template <typename T>
vector<T>::VectorConstIterator::VectorConstIterator() : VectorIterator() {}

template <typename T>
vector<T>::VectorConstIterator::VectorConstIterator(T *current_)
    : VectorIterator(current_) {}

template <typename T>
typename vector<T>::const_iterator vector<T>::cbegin() const {
  return const_iterator(vector_);
}
template <typename T>
typename vector<T>::const_iterator vector<T>::cend() const {
  return const_iterator(vector_ + size_);
}

template <typename T>
bool vector<T>::VectorConstIterator::operator==(
    const VectorConstIterator &other) const {
  return VectorIterator::operator==(other);
}

template <typename T>
bool vector<T>::VectorConstIterator::operator!=(
    const VectorConstIterator &other) const {
  return VectorIterator::operator!=(other);
}

template <typename T>
typename vector<T>::const_reference vector<T>::VectorConstIterator::operator*()
    const {
  return VectorIterator::operator*();
}

template <typename T>
const typename vector<T>::value_type *
vector<T>::VectorConstIterator::operator->() const {
  return VectorIterator::operator->();
}

template <typename T>
typename vector<T>::VectorConstIterator
vector<T>::VectorConstIterator::operator+(size_type n) const {
  VectorConstIterator temp = *this;
  temp.current_ += n;
  return temp;
}

// BONUS PART
template <typename T>
template <typename... Args>
typename vector<T>::iterator vector<T>::insert_many(const_iterator pos,
                                                    Args &&...args) {
  return insert_many_impl(pos, std::index_sequence_for<Args...>{},
                          std::forward<Args>(args)...);
}

template <typename T>
template <std::size_t... Is, typename... Args>
typename vector<T>::iterator vector<T>::insert_many_impl(
    const_iterator pos, std::index_sequence<Is...>, Args &&...args) {
  iterator it = pos;
  ((it = insert(it, std::forward<Args>(
                        std::get<sizeof...(Is) - 1 - Is>(std::tie(args...))))),
   ...);
  return it;
}

template <typename T>
template <typename... Args>
void vector<T>::insert_many_back(Args &&...args) {
  insert_many(cend(), args...);
}

}  // namespace s21
