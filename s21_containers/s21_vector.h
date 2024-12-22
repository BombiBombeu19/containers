#ifndef S21_VECTOR_H
#define S21_VECTOR_H

#include <iostream>
#include <limits>
#include <utility>

using namespace std;

namespace s21 {
template <typename T>
class vector {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = std::size_t;

 private:
  size_type size_;
  size_type capacity_;
  const size_type DEFAULT_CAPACITY_ = 20;
  T *vector_ = nullptr;

 public:
  class VectorIterator {
    friend class vector<T>;

   protected:
    T *current_;

   public:
    VectorIterator();
    VectorIterator(T *current_);

    VectorIterator &operator++();
    VectorIterator operator++(int n);
    VectorIterator &operator--();
    VectorIterator operator--(int n);

    bool operator==(const VectorIterator &other) const;
    bool operator!=(const VectorIterator &other) const;

    size_type operator-(const VectorIterator &other) const;

    VectorIterator operator+(size_type n) const;
    VectorIterator operator-(size_type n) const;

    reference operator*() const;
    value_type *operator->() const;

  };  // CLASS VECTOR_ITERATOR
  using iterator = VectorIterator;

  class VectorConstIterator : public VectorIterator {
   public:
    VectorConstIterator();
    VectorConstIterator(T *current_);

    bool operator==(const VectorConstIterator &other) const;
    bool operator!=(const VectorConstIterator &other) const;

    const_reference operator*() const;
    const value_type *operator->() const;

    VectorConstIterator operator+(size_type n) const;
  };  // CLASS VECTOR_CONST_ITERATOR
  using const_iterator = VectorConstIterator;

  vector();
  vector(size_type n);
  vector(std::initializer_list<value_type> const &items);
  vector(const vector &v);
  vector(vector &&v);
  ~vector();

  vector &operator=(const vector &v);
  vector &operator=(vector &&v);

  reference at(size_type pos);
  reference operator[](size_type pos);
  const_reference operator[](size_type pos) const;
  const_reference front() const;
  const_reference back() const;
  T *data();

  iterator begin();
  iterator end();

  const_iterator cbegin() const;
  const_iterator cend() const;

  void reserve(size_type size);
  void shrink_to_fit();
  void clear();
  void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back();
  void swap(vector &other);
  bool empty();
  size_type size();
  size_type max_size() const;
  size_type capacity();
  iterator insert(iterator pos, const_reference value);

  // BONUS PART
  template <typename... Args>
  VectorIterator insert_many(VectorConstIterator pos, Args &&...args);

  template <std::size_t... Is, typename... Args>
  VectorIterator insert_many_impl(VectorConstIterator pos,
                                  std::index_sequence<Is...>, Args &&...args);

  template <typename... Args>
  void insert_many_back(Args &&...args);

};  // CLASS VECTOR

}  // namespace s21

#include "s21_vector.tpp"

#endif  // S21_VECTOR_H