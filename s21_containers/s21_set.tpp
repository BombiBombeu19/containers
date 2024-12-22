#include "s21_set.h"

namespace s21 {  // set

template <typename Key>
set<Key>::set(typename set<Key>::key_type key_)
    : BinaryTree<Key, Key>(key_, key_) {}  // Используем список инициализации

template <typename Key>
set<Key>::set(std::initializer_list<value_type> const &items)
    : BinaryTree<Key, Key>(Key(), Key()) {
  for (auto i = items.begin(); i != items.end(); ++i) {
    BinaryTree<Key, Key>::insert(*i, Key());
  }
}

template <typename Key>
set<Key>::set(const set &s)
    : BinaryTree<Key, Key>(s) {}  // Копирующий конструктор

template <typename Key>
set<Key>::set(set &&s)
    : BinaryTree<Key, Key>(std::move(s)) {}  // Перемещающий конструктор

template <typename Key>
set<Key>::~set() {}

template <typename Key>
set<Key> &set<Key>::operator=(set &&s) {
  BinaryTree<Key, Key>::operator=(
      std::move(s));  // Используем std::move для перемещения
  return *this;
}

template <typename Key>
typename set<Key>::iterator set<Key>::begin() {
  return BinaryTree<Key, Key>::begin();
}

template <typename Key>
typename set<Key>::iterator set<Key>::end() {
  return BinaryTree<Key, Key>::end();
}

template <typename Key>
bool set<Key>::empty() {
  return BinaryTree<Key, Key>::empty();
}

template <typename Key>
typename set<Key>::size_type set<Key>::size() {
  return BinaryTree<Key, Key>::size();
}

template <typename Key>
typename set<Key>::size_type set<Key>::max_size() {
  return BinaryTree<Key, Key>::max_size();
}

template <typename Key>
void set<Key>::clear() {
  BinaryTree<Key, Key>::clear();
}

template <typename Key>
std::pair<typename set<Key>::iterator, bool> set<Key>::insert(
    const value_type &value) {
  return BinaryTree<Key, Key>::insert(value, value);
}

template <typename Key>
void set<Key>::erase(iterator pos) {
  BinaryTree<Key, Key>::erase(pos);
}

template <typename Key>
void set<Key>::swap(set &other) {
  BinaryTree<Key, Key>::swap(other);
}

template <typename Key>
void set<Key>::merge(set &other) {
  BinaryTree<Key, Key>::merge(other);
}

template <typename Key>
typename set<Key>::iterator set<Key>::find(const key_type &key) {
  return BinaryTree<Key, Key>::find(key);
}

template <typename Key>
bool set<Key>::contains(const key_type &key) {
  return BinaryTree<Key, Key>::contains(key);
}
};  // namespace s21

// int main() {
//   s21::set<double> tree({1, 2, 3});
//   // s21::set<double> *tree = new s21::set<double>(1);

//   // // INSERT
//   // s21::set<double>::iterator it_insert;
//   // bool b;
//   // std::tie(it_insert, b) = tree->insert(5);
//   // std::tie(it_insert, b) = tree->insert(2);
//   // std::tie(it_insert, b) = tree->insert(8);
//   // std::tie(it_insert, b) = tree->insert(3);
//   // std::tie(it_insert, b) = tree->insert(9);
//   // std::tie(it_insert, b) = tree->insert(1.5);
//   // std::tie(it_insert, b) = tree->insert(2.5);

//   // s21::set<double> *tree_2 = new s21::set<double>(-1);
//   // std::tie(it_insert, b) = tree_2->insert(-5);
//   // std::tie(it_insert, b) = tree_2->insert(-2);
//   // std::tie(it_insert, b) = tree_2->insert(-8);
//   // std::tie(it_insert, b) = tree_2->insert(-3);
//   // std::tie(it_insert, b) = tree_2->insert(-9);
//   // std::tie(it_insert, b) = tree_2->insert(-1.5);
//   // std::tie(it_insert, b) = tree_2->insert(-2.5);

//   // Создание нового объекта перемещением
//   // s21::set<double> tree_2(std::move(tree));

//   // cout << tree->contains(1) << endl;
//   // tree->erase(i);
//   // tree->clear();

//   // s21::set<double>::iterator i = tree->begin();
//   // tree->erase(i);

//   // tree->merge(*tree_2);
//   // tree->swap(*tree_2);

//   // Печать содержимого дерева
//   // s21::set<double>::iterator it_er = tree->begin();
//   // while(it_er != tree->end()){
//   //   std::cout << *it_er << std::endl;
//   //   ++it_er;
//   // }
//   // std::cout << *it_er << std::endl;

//   // s21::set<double>::iterator it_er_2 = tree_2->begin();
//   // while(it_er_2 != tree_2->end()){
//   //   std::cout << *it_er_2 << std::endl;
//   //   ++it_er_2;
//   // }
//   // std::cout << *it_er_2 << std::endl;

//   cout << "size(tree): "<< tree.size() << endl;
//   // cout << "size(tree_2): " << tree_2->size() << endl;

//   return 0;
// }