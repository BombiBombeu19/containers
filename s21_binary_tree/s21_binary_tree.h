#ifndef S21_BINARY_TREE_H_
#define S21_BINARY_TREE_H_

#include <iostream>

#include "../s21_containers/s21_vector.h"

using namespace std;

namespace s21 {

template <typename Key, typename T>
class BinaryTree {
 public:
  class BinaryTreeIterator;

  // Member type //
  using key_type = Key;
  using mapped_type = T;
  using value_type = Key;
  using reference = value_type &;
  using const_reference = const value_type &;
  using size_type = size_t;

  key_type key;
  mapped_type value;
  BinaryTree *left;
  BinaryTree *right;
  BinaryTree *parent;

  // Member functions //
  BinaryTree(Key key_);
  BinaryTree(key_type key_, mapped_type value_);
  BinaryTree(std::initializer_list<value_type> const &items);
  BinaryTree(const BinaryTree &s);
  BinaryTree(BinaryTree &&s);
  ~BinaryTree();
  BinaryTree &operator=(BinaryTree &&s);
  BinaryTree &operator=(BinaryTree &s);

  // Element access //
  // mapped_type& at(const key_type& key);
  // mapped_type& operator[](const key_type& key);

  // Our functions //
  BinaryTree *insert(BinaryTree *node, key_type key_);
  BinaryTree *insert(BinaryTree *node, key_type key_, mapped_type value_);
  BinaryTree *remove(BinaryTree *node, const key_type key_);
  BinaryTree *search(BinaryTree *node, const key_type key_);
  BinaryTree *get_left_max_node(BinaryTree *node);
  void order_tree(BinaryTree *node, vector<key_type> &v);

  // Iterators //
  BinaryTreeIterator begin();
  BinaryTreeIterator end();

  // Capacity //
  bool empty();
  size_type size();
  size_type max_size();

  // Modifiers  //
  void clear();
  std::pair<BinaryTreeIterator, bool> insert(const value_type &value);
  std::pair<BinaryTreeIterator, bool> insert(const Key &key, const T &obj);

  void erase(BinaryTreeIterator pos);
  void swap(BinaryTree &other);
  void merge(BinaryTree &other);

  // Lookup //
  BinaryTreeIterator find(const key_type &key);
  bool contains(const key_type &key);

  class BinaryTreeIterator {
   public:
    BinaryTree *ptr;
    BinaryTreeIterator();
    explicit BinaryTreeIterator(BinaryTree *_ptr);

    BinaryTreeIterator &operator++();
    BinaryTreeIterator &operator--();
    bool operator==(BinaryTreeIterator other) const;
    bool operator!=(BinaryTreeIterator other) const;
    value_type *operator->() const;
    reference operator*() const;
    BinaryTree<Key, T> &operator=(BinaryTree &other);

  };  // BINARY_TREE_ITERATOR

  using iterator = BinaryTreeIterator;
  class BinaryTreeConstIterator : public BinaryTreeIterator {
  };  // BINARY_TREE_CONST_ITERATOR
  using const_iterator = BinaryTreeConstIterator;
};
};  // namespace s21

#include "s21_binary_tree.tpp"

#endif  // S21_BINARY_TREE_H_