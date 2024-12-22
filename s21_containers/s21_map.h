#ifndef S21_MAP_H_
#define S21_MAP_H_

#include <functional>
#include <iostream>
#include <string>

#include "../s21_binary_tree/s21_binary_tree.h"

namespace s21 {

template <typename Key, typename T>
class map : public BinaryTree<Key, T> {
 public:
  // Member type
  using key_type = Key;
  using mapped_type = T;
  using value_type = std::pair<const key_type, mapped_type>;
  using reference = value_type&;
  using iterator = typename BinaryTree<Key, T>::BinaryTreeIterator;
  using const_iterator = typename BinaryTree<Key, T>::BinaryTreeConstIterator;
  using const_reference = const value_type&;
  using size_type = size_t;

  // Member functions
  map(key_type key_);
  map(key_type key, mapped_type value);
  map(std::initializer_list<Key> const& keys);
  map(const map& m);
  map(map&& m);
  ~map();
  map& operator=(map&& m);

  // Element access
  mapped_type& at(const key_type& key);
  mapped_type& operator[](const key_type& key);

  void print_tree();  // Нужно удалить

  // Iterators
  iterator begin();
  iterator end();

  // Capacity
  bool empty();
  size_type size();
  size_type max_size();

  // Modifiers
  void clear();

  std::pair<iterator, bool> insert(const value_type& value);
  std::pair<iterator, bool> insert(const key_type& key, const mapped_type& obj);
  std::pair<iterator, bool> insert_or_assign(const key_type& key,
                                             const mapped_type& obj);
  void erase(iterator pos);
  void swap(map& other);
  void merge(map& other);

  // Lookup
  bool contains(const key_type& key);
};
};  // namespace s21

#include "s21_map.tpp"

#endif  // S21_MAP_H_