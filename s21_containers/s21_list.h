#ifndef S21_LIST_H_
#define S21_LIST_H_

#include <iostream>
#include <limits>

namespace s21 {
template <typename T>
class node {
 public:
  T data;
  node *prev;
  node *next;

  node();
  node(T _data);
};

template <typename T>
class list {
 private:
  node<T> *first_;
  node<T> *last_;

 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = std::size_t;

  class ListIterator {
    friend class list<T>;

   protected:
    node<T> *current_;
    list<T> *list_;

   public:
    ListIterator();
    ListIterator(node<T> *current_, list<T> *list_);

    ListIterator &operator++();
    ListIterator operator++(int n);
    ListIterator &operator--();
    ListIterator operator--(int);

    bool operator==(const ListIterator &other) const;
    bool operator!=(const ListIterator &other) const;

    reference operator*() const;
    value_type *operator->() const;

  };  // class ListIterator
  using iterator = ListIterator;

  class ListConstIterator : public ListIterator {
   public:
    ListConstIterator();
    ListConstIterator(node<T> *node, const list<T> *list_);
    ListConstIterator(const ListIterator &other);

    bool operator==(const ListConstIterator &other) const;
    bool operator!=(const ListConstIterator &other) const;

    const_reference operator*() const;
    const value_type *operator->() const;

  };  // class ListConstIterator

  using const_iterator = ListConstIterator;

  list();
  list(size_type n);
  list(std::initializer_list<value_type> const &items);
  list(const list &l);
  list(list &&l);
  ~list();

  list &operator=(const list &l);
  list &operator=(list &&l);

  bool operator==(const list &other) const;
  bool operator!=(const list &other) const;

  const_reference front();
  const_reference back();

  iterator begin();
  iterator end();

  const_iterator cbegin() const;
  const_iterator cend() const;

  bool empty();
  size_type size();
  size_type max_size();

  void clear();
  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back();
  void push_front(const_reference value);
  void pop_front();
  void swap(list &other);
  void merge(list &other);
  void splice(const_iterator pos, list &other);
  void reverse();
  void unique();
  void sort();

  template <typename... Args>
  typename list<T>::iterator insert_many(const_iterator pos, Args &&...args);

  template <typename First, typename... Rest>
  typename list<T>::iterator insert_many_impl(const_iterator pos, First &&first,
                                              Rest &&...rest);
  typename list<T>::iterator insert_many_impl(const_iterator pos);

  template <typename... Args>
  void insert_many_back(Args &&...args);

  template <typename... Args>
  void insert_many_front(Args &&...args);

};  // class list

}  // namespace s21

#include "s21_list.tpp"

#endif  // S21_LIST_H_