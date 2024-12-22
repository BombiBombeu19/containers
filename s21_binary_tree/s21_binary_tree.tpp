#include "s21_binary_tree.h"

namespace s21 {
// BINARY_TREE

template <typename Key, typename T>
BinaryTree<Key, T>::BinaryTree(Key key_) {
  key = key_;
  value = key_;
  left = nullptr;
  right = nullptr;
  parent = nullptr;
}

template <typename Key, typename T>
BinaryTree<Key, T>::BinaryTree(Key key_, mapped_type value_) {
  key = key_;
  value = value_;
  left = nullptr;
  right = nullptr;
  parent = nullptr;
}

// template <typename Key, typename T> // Инициализация через список значений
// BinaryTree<Key, T>::BinaryTree(std::initializer_list<value_type> const
// &items) {
//   for(auto i = items.begin(); i != items.end(); ++i){
//     if (i == items.begin())  {
//       key = *i;
//     } else {
//       insert(this, *i);
//     }
//   }
// }

template <typename Key, typename T>
BinaryTree<Key, T>::BinaryTree(const BinaryTree &s) {
  key = s.key;
  value = s.value;
  left = s.left ? new BinaryTree(*s.left) : nullptr;
  right = s.right ? new BinaryTree(*s.right) : nullptr;
  parent = nullptr;
  if (left) left->parent = this;
  if (right) right->parent = this;
}

template <typename Key, typename T>
BinaryTree<Key, T>::BinaryTree(BinaryTree &&s) {
  key = s.key;
  value = s.value;
  left = s.left;
  right = s.right;
  parent = nullptr;
  if (left) left->parent = this;
  if (right) right->parent = this;
  s.key = key_type();
  s.value = mapped_type();
  s.left = nullptr;
  s.right = nullptr;
}

template <typename Key, typename T>
BinaryTree<Key, T>::BinaryTree::~BinaryTree() {
  clear();
}

template <typename Key, typename T>
BinaryTree<Key, T> &BinaryTree<Key, T>::operator=(BinaryTree &&s) {
  key = s.key;
  left = s.left;
  right = s.right;
  parent = nullptr;
  if (left) left->parent = this;
  if (right) right->parent = this;

  s.key = key_type();
  s.left = nullptr;
  s.right = nullptr;
  return *this;
}

template <typename Key, typename T>
BinaryTree<Key, T> &BinaryTree<Key, T>::operator=(BinaryTree &s) {
  if (this != &s) {
    clear();
    key = s.key;
    value = s.value;
    left = s.left ? new BinaryTree(*s.left) : nullptr;
    right = s.right ? new BinaryTree(*s.right) : nullptr;
    parent = nullptr;
    if (left) left->parent = this;
    if (right) right->parent = this;
  }
  return *this;
}

template <typename Key, typename T>
BinaryTree<Key, T> *BinaryTree<Key, T>::insert(BinaryTree *node, Key key_) {
  if (node == nullptr) return new BinaryTree(key);

  if (key_ < node->key) {
    if (node->left == nullptr) {
      node->left = new BinaryTree(key_);
      node->left->parent = node;
    } else {
      node->left = insert(node->left, key_);
      node->left->parent = node;
    }
  } else if (key_ > node->key) {
    if (node->right == nullptr) {
      node->right = new BinaryTree(key_);
      node->right->parent = node;
    } else {
      node->right = insert(node->right, key_);
      node->right->parent = node;
    }
  }

  return node;
}

template <typename Key, typename T>
BinaryTree<Key, T> *BinaryTree<Key, T>::get_left_max_node(BinaryTree *node) {
  if (node == nullptr || node->right == nullptr) return node;

  return get_left_max_node(node->right);
}

template <typename Key, typename T>
BinaryTree<Key, T> *BinaryTree<Key, T>::remove(BinaryTree *node,
                                               const Key key_) {
  if (node == nullptr) return nullptr;

  if (key_ < node->key) {
    node->left = remove(node->left, key_);
  } else if (key_ > node->key) {
    node->right = remove(node->right, key_);
  } else {
    if (node->left == nullptr && node->right == nullptr) {
      delete node;
      return nullptr;
    } else if (node->left == nullptr) {
      BinaryTree *tmp = node->right;
      node->right = nullptr;
      tmp->parent = node->parent;
      delete node;
      return tmp;
    } else if (node->right == nullptr) {
      BinaryTree *tmp = node->left;
      node->left = nullptr;
      tmp->parent = node->parent;
      delete node;
      return tmp;
    } else {
      BinaryTree *tmp = get_left_max_node(node->left);
      node->key = tmp->key;
      node->left = remove(node->left, tmp->key);
    }
  }
  return node;
}

template <typename Key, typename T>
BinaryTree<Key, T> *BinaryTree<Key, T>::search(BinaryTree *node,
                                               const Key key_) {
  if (!node) return nullptr;

  if (key_ == node->key) return node;

  return (key_ < node->key) ? search(node->left, key_)
                            : search(node->right, key_);
}

template <typename Key, typename T>
bool BinaryTree<Key, T>::BinaryTree::empty() {
  return size() == 0;
}

template <typename Key, typename T>
typename BinaryTree<Key, T>::size_type BinaryTree<Key, T>::BinaryTree::size() {
  vector<Key> v;
  BinaryTree *curr = this;
  BinaryTree<Key, T>::BinaryTree::order_tree(curr, v);

  return v.size();
}

template <typename Key, typename T>
typename BinaryTree<Key, T>::size_type BinaryTree<Key, T>::max_size() {
  return std::numeric_limits<size_type>::max() / (sizeof(BinaryTree));
}

template <typename Key, typename T>
typename BinaryTree<Key, T>::iterator BinaryTree<Key, T>::begin() {
  BinaryTree *result = this;
  if (result == nullptr && result->left == nullptr) return iterator(result);

  while (result->left != nullptr) result = result->left;

  return iterator(result);
}

template <typename Key, typename T>
typename BinaryTree<Key, T>::iterator BinaryTree<Key, T>::end() {
  BinaryTree *result = this;
  if (result == nullptr && result->right == nullptr)
    return BinaryTreeIterator(result);

  while (result->right != nullptr) result = result->right;

  return BinaryTreeIterator(result);
}

template <typename Key, typename T>
void BinaryTree<Key, T>::clear() {
  if (left != nullptr) {
    left->clear();
    delete left;
    left = nullptr;
  }
  if (right != nullptr) {
    right->clear();
    delete right;
    right = nullptr;
  }

  key = key_type();
}

template <typename Key, typename T>
void BinaryTree<Key, T>::erase(BinaryTreeIterator pos) {
  if (pos.ptr->parent == nullptr) {
    BinaryTree *node = pos.ptr;
    if (!node) return;

    if (node->left == nullptr && node->right == nullptr) {
      this->key = key_type();
      this->value = value_type();
      this->left = nullptr;
      this->right = nullptr;
      this->parent = nullptr;
    } else {
      BinaryTree *child = node->left != nullptr ? node->left : node->right;
      if (node->parent) {
        if (node->parent->left == node) {
          node->parent->left = child;
        } else {
          node->parent->right = child;
        }
        child->parent = node->parent;
      } else {
        this->key = child->key;
        this->value = child->value;
        this->left = child->left;
        this->right = child->right;
        if (this->left) this->left->parent = this;
        if (this->right) this->right->parent = this;
      }
      node->parent = nullptr;
    }
  } else {
    BinaryTree *node = pos.ptr;
    if (!node) return;
    BinaryTree *parent = node->parent;

    if (parent->left == node)
      parent->left = remove(node, node->key);
    else
      parent->right = remove(node, node->key);

    pos.ptr = nullptr;
  }
}

template <typename Key, typename T>
bool BinaryTree<Key, T>::contains(const Key &key) {
  BinaryTree *finder = search(this, key);
  return finder != nullptr;
}

template <typename Key, typename T>
typename BinaryTree<Key, T>::iterator BinaryTree<Key, T>::find(const Key &key) {
  iterator it;
  it.ptr = search(this, key);

  return it.ptr != nullptr
             ? it
             : throw std::out_of_range("\nElement not found in the BinaryTree");
}

template <typename Key, typename T>
std::pair<typename BinaryTree<Key, T>::iterator, bool>
BinaryTree<Key, T>::insert(const Key &key, const T &obj) {
  iterator it;
  if (contains(key)) return {it, false};
  BinaryTree *new_node = insert(this, key, obj);

  if (new_node == nullptr) return {it, false};

  it.ptr = new_node;

  return {it, true};
}

template <typename Key, typename T>
BinaryTree<Key, T> *BinaryTree<Key, T>::insert(BinaryTree *node, Key key_,
                                               mapped_type value_) {
  if (node == nullptr) return new BinaryTree(key, value);

  if (key_ < node->key) {
    if (node->left == nullptr) {
      node->left = new BinaryTree(key_, value_);
      node->left->parent = node;
    } else {
      node->left = insert(node->left, key_, value_);
      node->left->parent = node;
    }
  } else if (key_ > node->key) {
    if (node->right == nullptr) {
      node->right = new BinaryTree(key_, value_);
      node->right->parent = node;
    } else {
      node->right = insert(node->right, key_, value_);
      node->right->parent = node;
    }
  }

  return node;
}

template <typename Key, typename T>
void BinaryTree<Key, T>::merge(BinaryTree &other) {
  if (other.parent == nullptr && other.right == nullptr &&
      other.left == nullptr)
    return;
  if (!contains(other.key)) {
    insert(other.key, other.value);
  }
  if (other.left != nullptr) merge(*other.left);
  if (other.right != nullptr) merge(*other.right);

  insert(other.key, other.value);

  other.clear();
}

template <typename Key, typename T>
void BinaryTree<Key, T>::swap(BinaryTree &other) {
  BinaryTree *tmp = new BinaryTree(other.key);
  tmp->merge(other);  // tmp = other
  other.clear();      // clear other

  other.key = key;  // other.key = this.key
  other.value = value;
  other.merge(*this);  // other = this;

  clear();
  key = tmp->key;
  value = tmp->value;

  merge(*tmp);  // this = tmp;

  delete tmp;
}

// BinaryTree ITERATOR

template <typename Key, typename T>
BinaryTree<Key, T>::BinaryTreeIterator::BinaryTreeIterator() : ptr(nullptr) {}

template <typename Key, typename T>
BinaryTree<Key, T>::BinaryTreeIterator::BinaryTreeIterator(BinaryTree *_ptr)
    : ptr(_ptr) {}

template <typename Key, typename T>
typename BinaryTree<Key, T>::value_type *
BinaryTree<Key, T>::BinaryTreeIterator::operator->() const {
  return &ptr->key;
}

template <typename Key, typename T>
typename BinaryTree<Key, T>::reference
BinaryTree<Key, T>::BinaryTreeIterator::operator*() const {
  return ptr->key;
}

template <typename Key, typename T>
typename BinaryTree<Key, T>::iterator &
BinaryTree<Key, T>::BinaryTreeIterator::operator++() {
  if (ptr != nullptr) {
    if (ptr->right != nullptr) {
      ptr = ptr->right;
      if (ptr->left != nullptr)
        while (ptr->left != nullptr) ptr = ptr->left;
    } else if (ptr->parent != nullptr) {
      iterator tmp(ptr->parent);
      while (tmp.ptr->parent != nullptr && ptr->key >= tmp.ptr->key)
        tmp.ptr = tmp.ptr->parent;
      ptr = tmp.ptr;
    }
  }
  return *this;
}

template <typename Key, typename T>
typename BinaryTree<Key, T>::iterator &
BinaryTree<Key, T>::BinaryTreeIterator::operator--() {
  if (ptr != nullptr) {
    if (ptr->left != nullptr) {
      ptr = ptr->left;
      if (ptr->right != nullptr)
        while (ptr->right != nullptr) ptr = ptr->right;
    } else if (ptr->parent != nullptr) {
      iterator tmp(ptr->parent);
      while (tmp.ptr->parent != nullptr && ptr->key < tmp.ptr->key)
        tmp.ptr = tmp.ptr->parent;
      ptr = tmp.ptr;
    }
  }
  return *this;
}

template <typename Key, typename T>
bool BinaryTree<Key, T>::BinaryTreeIterator::operator==(
    BinaryTreeIterator other) const {
  return ptr == other.ptr;
}

template <typename Key, typename T>
bool BinaryTree<Key, T>::BinaryTreeIterator::operator!=(
    BinaryTreeIterator other) const {
  return ptr != other.ptr;
}

template <typename Key, typename T>
void BinaryTree<Key, T>::BinaryTree::order_tree(BinaryTree *node,
                                                vector<Key> &v) {
  if (node == nullptr) return;

  order_tree(node->left, v);
  v.push_back(node->key);
  order_tree(node->right, v);
}
};  // namespace s21

// Фирменный рецепт шаурмы от Жени ЛОХА:
//
// Лаваш тонкий - 2 листа
// Куриное филе (крупное) - 1 шт.
// Сыр твердый - 200-250 г
// Капуста белокочанная - 150 г
// Морковь по-корейски - 150 г
// Огурцы маринованные - 2 небольших
// Помидор свежий - 1 шт.
// Майонез - 5-6 ст. ложек
// Сметана - 2 ст. ложки
// Зелень свежая (петрушка, укроп) - 0,5 небольшого пучка
// Чеснок - 2-4 зубчика (по вкусу)
// Масло растительное для жарки - 2 ст. ложки
// Паприка молотая - 2 ч. л.
// Перец кайенский - 1 щепотка (по вкусу)
// Чеснок сушеный гранулированный - 1 ч. л.
// Приправа для курицы - 2 ч. л.
// Перец чёрный молотый - по вкусу
// Соль - по вкусу
// Приготовить и съесть!)))