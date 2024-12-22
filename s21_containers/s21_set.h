#ifndef S21_SET_H_
#define S21_SET_H_

#include <iostream>

#include "../s21_binary_tree/s21_binary_tree.h"

using namespace std;

namespace s21 {

template <typename Key>
class set : public BinaryTree<Key, Key> {
 public:
  using key_type = Key;
  using value_type = Key;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = typename BinaryTree<Key, Key>::BinaryTreeIterator;
  using const_iterator = typename BinaryTree<Key, Key>::BinaryTreeConstIterator;
  using size_type = size_t;

  set(key_type key_);
  set(std::initializer_list<value_type> const &items);
  set(const set &s);
  set(set &&s);
  ~set();
  set &operator=(set &&s);

  iterator begin();
  iterator end();

  bool empty();
  size_type size();
  size_type max_size();

  void clear();
  std::pair<iterator, bool> insert(const value_type &value);
  void erase(iterator pos);
  void swap(set &other);
  void merge(set &other);

  iterator find(const key_type &key);
  bool contains(const key_type &key);
};
};  // namespace s21

#include "s21_set.tpp"

#endif  // S21_SET_H_