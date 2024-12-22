namespace s21 {

template <typename T>
node<T>::node() : data(T()), prev(nullptr), next(nullptr) {}

template <typename T>
node<T>::node(T _data) : data(_data), prev(nullptr), next(nullptr) {}

template <typename T>
list<T>::list() : first_(nullptr), last_(nullptr) {}

template <typename T>
list<T>::list(size_type n) : first_(nullptr), last_(nullptr) {
  if (n > 0) {
    first_ = new node<T>;
    last_ = first_;

    for (size_t i = 1; i < n; ++i) last_ = last_->next = new node<T>;
  }
}

template <typename T>
list<T>::list(std::initializer_list<T> const& items) {
  if (items.size() == 0) return;

  first_ = new node<T>(items.begin()[0]);
  last_ = first_;
  for (size_t i = 1; i < items.size(); ++i) {
    last_ = last_->next = new node<T>(items.begin()[i]);
  }
}

template <typename T>
list<T>::list(const list& l) : first_(nullptr), last_(nullptr) {
  for (auto item = l.first_; item != nullptr; item = item->next) {
    node<T>* new_node = new node<T>(item->data);
    if (first_ == nullptr)
      first_ = new_node;
    else
      last_->next = new_node;
    last_ = new_node;
  }
}

template <typename T>
list<T>::list(list&& l) : first_(l.first_), last_(l.last_) {
  l.first_ = nullptr;
  l.last_ = nullptr;
}

template <typename T>
list<T>::~list() {
  node<T>* current = first_;
  while (current != nullptr) {
    node<T>* next = current->next;
    delete current;
    current = next;
  }
  first_ = last_ = nullptr;
}

template <typename T>
typename list<T>::const_reference list<T>::front() {
  return first_->data;
}

template <typename T>
typename list<T>::const_reference list<T>::back() {
  return last_->data;
}

template <typename T>
typename list<T>::iterator list<T>::begin() {
  return ListIterator(first_, this);
}

template <typename T>
typename list<T>::iterator list<T>::end() {
  return ListIterator(nullptr, this);
}

template <typename T>
typename list<T>::const_iterator list<T>::cbegin() const {
  return ListConstIterator(first_, this);
}

template <typename T>
typename list<T>::const_iterator list<T>::cend() const {
  return ListConstIterator(nullptr, this);
}

template <typename T>
bool list<T>::empty() {
  return first_ == nullptr && last_ == nullptr;
}

template <typename T>
typename list<T>::size_type list<T>::size() {
  if (first_ == nullptr) return 0;
  size_type size = 0;
  for (auto current = first_; current != nullptr; current = current->next)
    size++;
  return size;
}

template <typename T>
typename list<T>::size_type list<T>::max_size() {
  return std::numeric_limits<size_type>::max() / (sizeof(node<T>));
}

template <typename T>
void list<T>::clear() {
  if (this->empty()) return;

  while (first_ != nullptr) {
    node<T>* next = first_->next;
    delete first_;
    first_ = next;
  }

  last_ = nullptr;
}

template <typename T>
void list<T>::sort() {
  for (auto current = first_; current != nullptr; current = current->next) {
    for (auto next = current->next; next != nullptr; next = next->next) {
      if (current->data > next->data) {
        auto tmp = next->data;
        next->data = current->data;
        current->data = tmp;
      }
    }
  }
}

template <typename T>
void list<T>::reverse() {
  if (first_ == nullptr || first_ == last_) return;

  iterator it = begin();
  while (it != end()) {
    push_front(*it);
    ++it;
  }

  it = begin();
  while (it != end()) {
    pop_back();
    ++it;
  }
}

template <typename T>
void list<T>::merge(list& other) {
  auto current_other = other.first_;
  auto current = last_;
  while (current_other != nullptr) {
    current->next = new node<T>(current_other->data);
    current = current->next;
    current_other = current_other->next;
  }

  while (other.first_ != nullptr) {
    auto next = other.first_->next;
    delete other.first_;
    other.first_ = next;
  }

  other.last_ = nullptr;
}

template <typename T>
void list<T>::unique() {
  if (first_ == nullptr || last_ == nullptr) return;
  auto current = first_;
  while (current != nullptr && current->next != nullptr) {
    if (current->data == current->next->data) {
      auto next = current->next;
      current->next = next->next;
      delete next;
    } else {
      current = current->next;
    }
  }
}

template <typename T>
void list<T>::push_back(const_reference value) {
  node<T>* new_node = new node<T>(value);
  new_node->next = nullptr;

  if (first_ == nullptr) {
    first_ = new_node;
    last_ = new_node;
  } else {
    last_->next = new_node;
    last_ = new_node;
  }
}

template <typename T>
void list<T>::push_front(const_reference value) {
  node<T>* new_node = new node<T>(value);
  new_node->next = nullptr;

  if (first_ == nullptr) {
    first_ = last_ = new_node;
    new_node->next = nullptr;
  } else {
    new_node->next = first_;
    first_ = new_node;
  }
}

template <typename T>
void list<T>::pop_back() {
  if (first_ == nullptr) return;

  if (first_ == last_) {
    delete first_;
    first_ = last_ = nullptr;
  } else {
    auto current = first_;
    while (current->next != last_) current = current->next;
    delete last_;
    last_ = current;
    last_->next = nullptr;
  }
}

template <typename T>
void list<T>::pop_front() {
  if (first_ == nullptr) return;

  if (first_ == last_) {
    delete first_;
    first_ = last_ = nullptr;
  } else {
    auto deletor = first_->next;

    delete first_;
    first_ = deletor;
    first_->next = deletor->next;
  }
}

template <typename T>
void list<T>::erase(iterator pos) {
  if (pos.current_ == first_) {
    pop_front();
  } else if (pos.current_ == last_) {
    pop_back();
  } else {
    auto current = first_;
    while (current->next != pos.current_) current = current->next;
    current->next = pos.current_->next;
    delete pos.current_;
  }
}

template <typename T>
typename list<T>::iterator list<T>::insert(iterator pos,
                                           const_reference value) {
  node<T>* n_node = new node<T>(value);
  if (pos == begin()) {
    n_node->next = first_;
    if (first_ != nullptr) {
      first_->prev = n_node;
    }
    first_ = n_node;
    if (last_ == nullptr) {
      last_ = n_node;
    }
  } else if (pos == end()) {
    n_node->prev = last_;
    last_->next = n_node;
    last_ = n_node;
  } else {
    node<T>* current = pos.current_;
    n_node->next = current;
    n_node->prev = current->prev;
    current->prev->next = n_node;
    current->prev = n_node;
  }
  return iterator(n_node, this);
}

template <typename T>
void list<T>::splice(const_iterator pos, list& other) {
  if (this != &other) {
    for (auto it = other.begin(); it != other.end(); ++it) {
      insert(pos, *it);
    }
    other.clear();
  }
}

template <typename T>
void list<T>::swap(list& other) {
  if (this == &other) return;

  auto tmp = other.first_;
  other.first_ = first_;
  first_ = tmp;

  tmp = other.last_;
  other.last_ = last_;
  last_ = tmp;
}

template <typename T>
list<T>& list<T>::operator=(const list& l) {
  if (this == &l) return *this;

  while (first_ != nullptr) {
    node<T>* next = first_->next;
    delete first_;
    first_ = next;
  }
  last_ = nullptr;

  for (auto item = l.first_; item != nullptr; item = item->next) {
    node<T>* new_node = new node<T>(item->data);
    if (first_ == nullptr)
      first_ = new_node;
    else
      last_->next = new_node;
    last_ = new_node;
  }

  return *this;
}

template <typename T>
list<T>& list<T>::operator=(list&& l) {
  if (this == &l) return *this;

  first_ = l.first_;
  last_ = l.last_;

  l.first_ = nullptr;
  l.last_ = nullptr;

  return *this;
}

template <typename T>
bool list<T>::operator==(const list& other) const {
  return first_ == other.first_ && last_ == other.last_;
}

template <typename T>
bool list<T>::operator!=(const list& other) const {
  return !(operator==(other));
}

// LIST_ITERATOR

template <typename T>
list<T>::ListIterator::ListIterator() : current_(nullptr), list_(nullptr) {}

template <typename T>
list<T>::ListIterator::ListIterator(node<T>* current_, list<T>* list_)
    : current_(current_), list_(list_) {}

template <typename T>
typename list<T>::iterator& list<T>::ListIterator::operator++() {
  current_ = current_->next;
  return *this;
}

template <typename T>
typename list<T>::iterator list<T>::ListIterator::operator++(int n) {
  for (int i = 0; i < n; i++) {
    ++(*this);
  }
  return *this;
}

template <typename T>
typename list<T>::reference list<T>::ListIterator::operator*() const {
  return current_->data;
}

template <typename T>
typename list<T>::iterator& list<T>::ListIterator::operator--() {
  if (list_->empty()) throw std::out_of_range("List is empty");

  if (current_ == nullptr) {
    current_ = list_->last_;
  } else if (current_ == list_->first_) {
    current_ = nullptr;
  } else {
    node<T>* prev = list_->first_;
    while (prev->next != current_) {
      prev = prev->next;
    }
    current_ = prev;
  }
  return *this;
}

template <typename T>
typename list<T>::iterator list<T>::ListIterator::operator--(int) {
  ListIterator temp = *this;
  --(*this);
  return temp;
}

template <typename T>
typename list<T>::value_type* list<T>::ListIterator::operator->() const {
  return &current_->data;
}

template <typename T>
bool list<T>::ListIterator::operator==(const ListIterator& other) const {
  if (list_ == other.list_) {
    if (current_ == nullptr && other.current_ == nullptr) {
      return true;
    } else if (current_ != nullptr && other.current_ != nullptr) {
      return current_ == other.current_;
    }
  }
  return false;
}

template <typename T>
bool list<T>::ListIterator::operator!=(const ListIterator& other) const {
  return !(*this == other);
}

// LIST_CONST_ITERATOR

template <typename T>
list<T>::ListConstIterator::ListConstIterator() : ListIterator() {}

template <typename T>
list<T>::ListConstIterator::ListConstIterator(node<T>* node,
                                              const list<T>* list_)
    : ListIterator(node, const_cast<list<T>*>(list_)) {}

template <typename T>
list<T>::ListConstIterator::ListConstIterator(const ListIterator& other)
    : ListIterator(other) {}

template <typename T>
typename list<T>::const_reference list<T>::ListConstIterator::operator*()
    const {
  return ListIterator::operator*();
}

template <typename T>
const typename list<T>::value_type* list<T>::ListConstIterator::operator->()
    const {
  return &(operator*());
}

template <typename T>
bool list<T>::ListConstIterator::operator==(
    const ListConstIterator& other) const {
  return ListIterator::operator==(other);
}

template <class T>
bool list<T>::ListConstIterator::operator!=(
    const ListConstIterator& other) const {
  return !(*this == other);
}

// BONUS

// insert_many

template <typename T>
template <typename... Args>
typename list<T>::iterator list<T>::insert_many(const_iterator pos,
                                                Args&&... args) {
  return insert_many_impl(pos, std::forward<Args>(args)...);
}

template <typename T>
template <typename First, typename... Rest>
typename list<T>::iterator list<T>::insert_many_impl(const_iterator pos,
                                                     First&& first,
                                                     Rest&&... rest) {
  if constexpr (sizeof...(rest) > 0) {
    auto it = insert_many_impl(pos, std::forward<Rest>(rest)...);
    return insert(it, std::forward<First>(first));
  } else {
    return insert(pos, std::forward<First>(first));
  }
}

template <typename T>
typename list<T>::iterator list<T>::insert_many_impl(const_iterator pos) {
  return iterator(const_cast<node<T>*>(pos.current_));
}

template <typename T>
template <typename... Args>
void list<T>::insert_many_back(Args&&... args) {
  insert_many(cend(), args...);
}

template <typename T>
template <typename... Args>
void list<T>::insert_many_front(Args&&... args) {
  insert_many(cbegin(), args...);
}

}  // NAMESPACE s21
