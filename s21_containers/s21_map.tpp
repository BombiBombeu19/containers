#include "s21_map.h"

namespace s21 {

template <typename Key, typename T>
map<Key, T>::map(typename map<Key, T>::key_type key_)
    : BinaryTree<Key, T>(key_) {}

template <typename Key, typename T>
map<Key, T>::map(typename map<Key, T>::key_type key_, mapped_type value_)
    : BinaryTree<Key, T>(key_, value_) {}

template <typename Key, typename T>
map<Key, T>::map(std::initializer_list<Key> const& keys)
    : BinaryTree<Key, T>(*keys.begin()) {
  auto it = keys.begin();
  insert(*it, T());
  for (++it; it != keys.end(); ++it) {
    insert(*it, T());
  }
}

template <typename Key, typename T>
map<Key, T>::map(const map& m) : BinaryTree<Key, T>(m) {}

template <typename Key, typename T>
map<Key, T>::map(map&& m) : BinaryTree<Key, T>(std::move(m)) {}

template <typename Key, typename T>
map<Key, T>::~map() {}

template <typename Key, typename T>
map<Key, T>& map<Key, T>::operator=(map&& m) {
  BinaryTree<Key, T>::operator=(std::move(m));
  return *this;
}

template <typename Key, typename T>
typename map<Key, T>::iterator map<Key, T>::begin() {
  return BinaryTree<Key, T>::begin();
}

template <typename Key, typename T>
typename map<Key, T>::iterator map<Key, T>::end() {
  return BinaryTree<Key, T>::end();
}

template <typename Key, typename T>
bool map<Key, T>::empty() {
  return BinaryTree<Key, T>::empty();
}

template <typename Key, typename T>
typename map<Key, T>::size_type map<Key, T>::size() {
  return BinaryTree<Key, T>::size();
}

template <typename Key, typename T>
typename map<Key, T>::size_type map<Key, T>::max_size() {
  return BinaryTree<Key, T>::max_size();
}

template <typename Key, typename T>
void map<Key, T>::clear() {
  BinaryTree<Key, T>::clear();
}

template <typename Key, typename T>
std::pair<typename map<Key, T>::iterator, bool> map<Key, T>::insert(
    const key_type& key, const mapped_type& obj) {
  return BinaryTree<Key, T>::insert(key, obj);
}

template <typename Key, typename T>
std::pair<typename map<Key, T>::iterator, bool> map<Key, T>::insert_or_assign(
    const key_type& key, const mapped_type& obj) {
  if (!contains(key)) {
    return BinaryTree<Key, T>::insert(key, obj);
  } else {
    iterator it = BinaryTree<Key, T>::find(key);
    it.ptr->value = obj;
    return {it, false};
  }
}

template <typename Key, typename T>
std::pair<typename map<Key, T>::iterator, bool> map<Key, T>::insert(
    const value_type& value) {
  return BinaryTree<Key, T>::insert(value.first, value.second);  // фаиль лох
}

template <typename Key, typename T>
void map<Key, T>::erase(iterator pos) {
  BinaryTree<Key, T>::erase(pos);
}

template <typename Key, typename T>
void map<Key, T>::swap(map& other) {
  BinaryTree<Key, T>::swap(other);
}

template <typename Key, typename T>
void map<Key, T>::merge(map& other) {
  BinaryTree<Key, T>::merge(other);
}

template <typename Key, typename T>
bool map<Key, T>::contains(const key_type& key) {
  return BinaryTree<Key, T>::contains(key);
}

template <typename Key, typename T>
typename map<Key, T>::mapped_type& map<Key, T>::at(const key_type& key) {
  try {
    iterator it = BinaryTree<Key, T>::find(key);
    return it.ptr->value;
  } catch (const std::exception& e) {
    insert(key, mapped_type());
    iterator it = BinaryTree<Key, T>::find(key);
    return it.ptr->value;
  }
}

template <typename Key, typename T>
typename map<Key, T>::mapped_type& map<Key, T>::operator[](
    const key_type& key) {
  iterator it = BinaryTree<Key, T>::find(key);
  return it.ptr->value;
}

};  // namespace s21

// int main() {
//   s21::map<double, double> *tree = new s21::map<double, double>(1, -1);

//   // INSERT
//   s21::map<double, double>::iterator it_insert;
//   bool b;
//   std::tie(it_insert, b) = tree->insert_or_assign(5, -5);
//   std::tie(it_insert, b) = tree->insert_or_assign(2, -2);
//   std::tie(it_insert, b) = tree->insert_or_assign(8, -8);
//   std::tie(it_insert, b) = tree->insert_or_assign(3, -3);
//   std::tie(it_insert, b) = tree->insert_or_assign(9, -9);
//   std::tie(it_insert, b) = tree->insert_or_assign(1.5, -1.5);
//   std::tie(it_insert, b) = tree->insert_or_assign(2.5, -2.5);
//   // std::tie(it_insert, b) = tree->insert_or_assign(2.5, 99999);

//   // INSERT PAIR

//   // s21::map<double, double> *tree = new s21::map<double, double>(1, 1);

//   // s21::map<double, double>::value_type value1 = std::make_pair(5.0, -5.0);
//   // s21::map<double, double>::value_type value2 = std::make_pair(2.0, -2.0);
//   // s21::map<double, double>::value_type value3 = std::make_pair(8.0, -8.0);

//   // s21::map<double, double>::iterator it_insert;
//   // bool b;

//   // std::tie(it_insert, b) = tree->insert(value1);
//   // std::tie(it_insert, b) = tree->insert(value2);
//   // std::tie(it_insert, b) = tree->insert(value3);

// // s21::map<double, double> tree({1,2, 3});

//   // double& value = (*tree)[10];
//   // cout << "value: " << value << endl;

//   // double& value = tree->at(9);
//   // cout << "value: " << value << endl;

//   // s21::map<double, double> *tree_2 = new s21::map<double, double>(11, 1);

//   // std::tie(it_insert, b) = tree_2->insert(55, 5);
//   // std::tie(it_insert, b) = tree_2->insert(22, 2);
//   // std::tie(it_insert, b) = tree_2->insert(88, 8);
//   // std::tie(it_insert, b) = tree_2->insert(33, 3);
//   // std::tie(it_insert, b) = tree_2->insert(99, 9);
//   // std::tie(it_insert, b) = tree_2->insert(1.55, 1.5);
//   // std::tie(it_insert, b) = tree_2->insert(2.55, 2.5);

//   // Создание нового объекта перемещением
//   // s21::map<double> *tree_2 = std::move(tree);

//   // cout << tree->contains(1) << endl;

//   // tree->clear();

//   s21::map<double, double>::iterator i = tree->begin();
//   tree->erase(i);

//   // tree->merge(*tree_2);
//   // tree->swap(*tree_2);

//   // Печать содержимого дерева
//   cout << "TREE_1: " << endl;
//   s21::map<double, double>::iterator it = tree->begin();
//   while (it != tree->end()) {
//     std::cout << it.ptr->key << ": " << it.ptr->value << std::endl;
//     ++it;
//   }
//   std::cout << it.ptr->key << ": " << it.ptr->value << std::endl;

//   // cout << "TREE_2: " << endl;
//   // s21::map<double, double>::iterator it_2 = tree_2->begin();
//   // while (it_2 != tree_2->end()) {
//   //   std::cout << it_2.ptr->key << ": " << it_2.ptr->value << std::endl;
//   //   ++it_2;
//   // }
//   // std::cout << it_2.ptr->key << ": " << it_2.ptr->value << std::endl;

//   cout << "size(tree): "<< tree->size() << endl;
//   // cout << "size(tree_2): " << tree_2->size() << endl;

//   // delete tree;

//   return 0;
// }