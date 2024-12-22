#include "test_main.h"

TEST(set_constructor, default) {
  s21::set<int> _set(1);
  s21::set<int>::iterator j = _set.begin();
  EXPECT_EQ(*j, 1);
  EXPECT_EQ(_set.empty(), 0);
  EXPECT_EQ(_set.size(), 1UL);
}

TEST(set_constructor, initializer_list) {
  s21::set<int> _set({11, 2, 99, 0});
  s21::set<int>::iterator j = _set.begin();
  EXPECT_EQ(*j, 0);
  ++j;
  EXPECT_EQ(*j, 2);
  ++j;
  EXPECT_EQ(*j, 11);
  ++j;
  EXPECT_EQ(*j, 99);
  ++j;
  EXPECT_EQ(_set.empty(), 0);
  EXPECT_EQ(_set.size(), 4UL);
}

TEST(set_constructor, copy) {
  s21::set<int> _set(11);
  _set.insert(2);
  _set.insert(99);
  _set.insert(0);
  s21::set<int> set_copy(_set);
  auto j = set_copy.begin();
  EXPECT_EQ(*j, 0);
  ++j;
  EXPECT_EQ(*j, 2);
  ++j;
  EXPECT_EQ(*j, 11);
  ++j;
  EXPECT_EQ(*j, 99);
  ++j;
  EXPECT_EQ(_set.empty(), 0);
  EXPECT_EQ(_set.size(), 4UL);
}

TEST(set_constructor, move) {
  s21::set<int> _set(11);
  _set.insert(2);
  _set.insert(99);
  _set.insert(0);
  s21::set<int> set_move(std::move(_set));
  auto j = set_move.begin();
  EXPECT_EQ(*j, 0);
  ++j;
  EXPECT_EQ(*j, 2);
  ++j;
  EXPECT_EQ(*j, 11);
  ++j;
  EXPECT_EQ(*j, 99);
  ++j;
  EXPECT_EQ(_set.size(), 1UL);
}

TEST(set_operator, move_assignment) {
  s21::set<int> _set(11);
  _set.insert(2);
  _set.insert(99);
  _set.insert(0);
  s21::set<int> set_move = std::move(_set);
  auto j = set_move.begin();
  EXPECT_EQ(*j, 0);
  ++j;
  EXPECT_EQ(*j, 2);
  ++j;
  EXPECT_EQ(*j, 11);
  ++j;
  EXPECT_EQ(*j, 99);
  ++j;
  EXPECT_EQ(_set.size(), 1UL);
}

TEST(set_iterator, begin) {
  s21::set<std::string> _set("this");
  _set.insert("world");
  _set.insert("is mine");
  auto i = _set.begin();
  EXPECT_EQ(i.ptr->key, "is mine");
}

TEST(set_iterator, end) {
  s21::set<std::string> _set("this");
  _set.insert("world");
  _set.insert("is mine");
  auto i = _set.end();
  EXPECT_EQ(i.ptr->key, "world");
}

TEST(set_iterator_operator, increment) {
  s21::set<char> _set('a');
  _set.insert('b');
  _set.insert('c');
  _set.insert('d');
  _set.insert('e');
  auto i = _set.begin();
  EXPECT_EQ(i.ptr->key, 'a');
  ++i;
  EXPECT_EQ(i.ptr->key, 'b');
  ++i;
  EXPECT_EQ(i.ptr->key, 'c');
  ++i;
  EXPECT_EQ(i.ptr->key, 'd');
  ++i;
  EXPECT_EQ(i.ptr->key, 'e');
}

TEST(set_iterator_operator, decrement_test_0) {
  s21::set<int> _set(1);
  _set.insert(5);
  _set.insert(4);
  auto i = _set.end();
  EXPECT_EQ(i.ptr->key, 5);
  --i;
  EXPECT_EQ(i.ptr->key, 4);
  --i;
  EXPECT_EQ(i.ptr->key, 1);
}

TEST(set_size, size_check) {
  s21::set<int> _set(1);
  _set.insert(5);
  _set.insert(4);
  EXPECT_EQ(_set.size(), 3UL);
}

TEST(set_insert, insert_test_0) {
  s21::set<int> _set(1);
  _set.insert(9);
  auto i = _set.begin();
  EXPECT_EQ(i.ptr->key, 1);
  ++i;
  EXPECT_EQ(i.ptr->key, 9);
}

TEST(set_insert, insert_test_1) {
  s21::set<int> _set(1);
  _set.insert(5);
  _set.insert(4);
  auto i = _set.begin();
  EXPECT_EQ(i.ptr->key, 1);
  ++i;
  EXPECT_EQ(i.ptr->key, 4);
  ++i;
  EXPECT_EQ(i.ptr->key, 5);
}

TEST(set_erase, erase_test_0) {
  s21::set<int> _set(1);
  _set.insert(5);
  _set.insert(4);
  auto i = _set.begin();
  ++i;
  _set.erase(i);
  EXPECT_EQ(_set.size(), 2UL);
}

TEST(set_swap, swap_test_0) {
  s21::set<int> _set(1);
  _set.insert(2);
  _set.insert(3);
  s21::set<int> _s(4);
  _s.insert(5);
  _s.insert(6);
  _s.insert(7);
  _set.swap(_s);

  EXPECT_EQ(_set.size(), 4UL);
  EXPECT_EQ(_s.size(), 3UL);

  auto i = _set.begin();
  EXPECT_EQ(i.ptr->key, 4);
  ++i;
  EXPECT_EQ(i.ptr->key, 5);
  ++i;
  EXPECT_EQ(i.ptr->key, 6);
  ++i;
  EXPECT_EQ(i.ptr->key, 7);

  auto j = _s.begin();
  EXPECT_EQ(j.ptr->key, 1);
  ++j;
  EXPECT_EQ(j.ptr->key, 2);
  ++j;
  EXPECT_EQ(j.ptr->key, 3);
}

TEST(set_merge, merge_test_0) {
  s21::set<int> _set(1);
  _set.insert(2);
  _set.insert(3);
  s21::set<int> _s(4);
  _s.insert(5);
  _s.insert(6);
  _s.insert(7);
  _set.merge(_s);
  EXPECT_EQ(_set.size(), 7UL);
  auto i = _set.begin();
  EXPECT_EQ(i.ptr->key, 1);
  ++i;
  EXPECT_EQ(i.ptr->key, 2);
  ++i;
  EXPECT_EQ(i.ptr->key, 3);
  ++i;
  EXPECT_EQ(i.ptr->key, 4);
  ++i;
  EXPECT_EQ(i.ptr->key, 5);
  ++i;
  EXPECT_EQ(i.ptr->key, 6);
  ++i;
  EXPECT_EQ(i.ptr->key, 7);
}

TEST(set_contains, contains_test_0) {
  s21::set<int> _set(1);
  _set.insert(5);
  _set.insert(4);
  EXPECT_TRUE(_set.contains(5));
  EXPECT_FALSE(_set.contains(6));
}

TEST(set_find, find_test_0) {
  s21::set<int> _set(1);
  _set.insert(5);
  _set.insert(4);
  auto i = _set.find(5);
  EXPECT_EQ(i.ptr->key, 5);
}
