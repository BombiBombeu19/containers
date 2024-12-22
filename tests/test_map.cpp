#include <type_traits>

#include "test_main.h"
TEST(map_constructor, no_arg) {
  s21::map<int, int> _map(1, 1);
  EXPECT_EQ(_map.empty(), 0);
}

TEST(map_constructor, initializer_list) {
  s21::map<double, double> tree(1, 1);

  s21::map<double, double>::value_type value1 = std::make_pair(5.0, -5.0);
  s21::map<double, double>::value_type value2 = std::make_pair(2.0, -2.0);
  s21::map<double, double>::value_type value3 = std::make_pair(8.0, -8.0);

  s21::map<double, double>::iterator it_insert;
  bool b;

  std::tie(it_insert, b) = tree.insert(value1);
  std::tie(it_insert, b) = tree.insert(value2);
  std::tie(it_insert, b) = tree.insert(value3);

  EXPECT_EQ(tree.empty(), 0);
  EXPECT_EQ(tree.size(), 4UL);
}

TEST(map_constructor, copy) {
  s21::map<double, double> *_map = new s21::map<double, double>(1, -1);
  _map->insert_or_assign(5, -5);
  _map->insert_or_assign(2, -2);
  _map->insert_or_assign(8, -8);
  _map->insert_or_assign(3, -3);
  _map->insert_or_assign(9, -9);
  _map->insert_or_assign(1.5, -1.5);
  _map->insert_or_assign(2.5, -2.5);

  s21::map<double, double> map_copy(*_map);
  auto j = map_copy.begin();
  EXPECT_EQ(_map->empty(), 0);
  EXPECT_EQ(map_copy.size(), 8UL);

  EXPECT_EQ(j.ptr->key, 1);
  EXPECT_EQ(j.ptr->value, -1);
  ++j;

  EXPECT_EQ(j.ptr->key, 1.5);
  EXPECT_EQ(j.ptr->value, -1.5);
  ++j;

  EXPECT_EQ(j.ptr->key, 2);
  EXPECT_EQ(j.ptr->value, -2);
  ++j;

  EXPECT_EQ(j.ptr->key, 2.5);
  EXPECT_EQ(j.ptr->value, -2.5);
  ++j;

  EXPECT_EQ(j.ptr->key, 3);
  EXPECT_EQ(j.ptr->value, -3);
  ++j;

  EXPECT_EQ(j.ptr->key, 5);
  EXPECT_EQ(j.ptr->value, -5);
  ++j;

  EXPECT_EQ(j.ptr->key, 8);
  EXPECT_EQ(j.ptr->value, -8);
  ++j;

  EXPECT_EQ(j.ptr->key, 9);
  EXPECT_EQ(j.ptr->value, -9);

  delete _map;
}

TEST(map_constructor, move) {
  s21::map<double, double> *_map = new s21::map<double, double>(1, -1);
  _map->insert_or_assign(5, -5);
  _map->insert_or_assign(2, -2);

  s21::map<double, double> map_copy(std::move(*_map));
  auto j = map_copy.begin();
  EXPECT_EQ(_map->empty(), 0);
  EXPECT_EQ(map_copy.size(), 3UL);

  EXPECT_EQ(j.ptr->key, 1);
  EXPECT_EQ(j.ptr->value, -1);
  ++j;

  EXPECT_EQ(j.ptr->key, 2);
  EXPECT_EQ(j.ptr->value, -2);
  ++j;

  EXPECT_EQ(j.ptr->key, 5);
  EXPECT_EQ(j.ptr->value, -5);
  ++j;

  delete _map;
}

TEST(map_operator, move_assignment) {
  s21::map<double, double> _map(1, -1);
  _map.insert_or_assign(5, -5);
  _map.insert_or_assign(2, -2);

  s21::map<double, double> map_copy = std::move(_map);
  auto j = map_copy.begin();
  EXPECT_EQ(_map.empty(), 0);
  EXPECT_EQ(map_copy.size(), 3UL);

  EXPECT_EQ(j.ptr->key, 1);
  EXPECT_EQ(j.ptr->value, -1);
  ++j;

  EXPECT_EQ(j.ptr->key, 2);
  EXPECT_EQ(j.ptr->value, -2);
  ++j;

  EXPECT_EQ(j.ptr->key, 5);
  EXPECT_EQ(j.ptr->value, -5);
  ++j;
}

TEST(map_operator, braces) {
  s21::map<int, int> _map(1, 1);
  _map.insert_or_assign(5, 5);
  _map.insert_or_assign(2, 2);

  EXPECT_EQ(_map[1], 1);
  EXPECT_EQ(_map[2], 2);
  EXPECT_EQ(_map[5], 5);
}

TEST(map_at, at) {
  s21::map<int, int> _map('c', 'c');
  _map.insert_or_assign('h', 'h');
  _map.insert_or_assign('e', 'e');
  _map.insert_or_assign('l', 'l');

  EXPECT_EQ(_map.at('c'), 'c');
  EXPECT_EQ(_map.at('h'), 'h');
  EXPECT_EQ(_map.at('e'), 'e');
  EXPECT_EQ(_map.at('l'), 'l');
}

TEST(map_iterator, begin) {
  s21::map<std::string, char> _map("char", 'c');
  auto i = _map.begin();
  EXPECT_EQ(i.ptr->key, "char");
  EXPECT_EQ(i.ptr->value, 'c');
}

TEST(map_iterator, end) {
  s21::map<std::string, char> _map("char", 'c');
  auto i = _map.end();
  EXPECT_EQ(i.ptr->key, "char");
  EXPECT_EQ(i.ptr->value, 'c');
}

TEST(map_iterator_operator, increment) {
  s21::map<int, int> _map(1, -1);
  _map.insert_or_assign(5, -5);
  _map.insert_or_assign(2, -2);
  auto i = _map.begin();
  ++i;
  EXPECT_EQ(i.ptr->key, 2);
  EXPECT_EQ(i.ptr->value, -2);
  ++i;
  EXPECT_EQ(i.ptr->key, 5);
  EXPECT_EQ(i.ptr->value, -5);
}

TEST(map_iterator_operator, decrement_test_0) {
  s21::map<int, int> _map(1, -1);
  _map.insert_or_assign(5, -5);
  _map.insert_or_assign(2, -2);
  auto i = _map.end();
  --i;
  EXPECT_EQ(i.ptr->key, 2);
  EXPECT_EQ(i.ptr->value, -2);
  --i;
  EXPECT_EQ(i.ptr->key, 1);
  EXPECT_EQ(i.ptr->value, -1);
  --i;
  EXPECT_EQ(i.ptr->key, 1);
}

TEST(map_size, size_check) {
  s21::map<int, int> _map(1, 1);
  _map.insert_or_assign(5, 5);
  _map.insert_or_assign(2, 2);
  EXPECT_EQ(_map.size(), 3UL);
}

TEST(map_insert, insert_test_0) {
  s21::map<int, int> _map(1, 1);
  _map.insert(0, 9);
  auto i = _map.begin();
  EXPECT_EQ(i.ptr->key, 0);
  EXPECT_EQ(i.ptr->value, 9);
  ++i;
  EXPECT_EQ(i.ptr->key, 1);
  EXPECT_EQ(i.ptr->value, 1);
}

TEST(map_insert, insert_test_1) {
  s21::map<int, int> _map(1, 1);
  _map.insert(0, 9);
  _map.insert(0, 10);
  auto i = _map.end();
  EXPECT_EQ(i.ptr->key, 1);
  EXPECT_EQ(i.ptr->value, 1);
  --i;
  EXPECT_EQ(i.ptr->key, 0);
  EXPECT_EQ(i.ptr->value, 9);

  EXPECT_EQ(_map.size(), 2UL);
}

TEST(map_insert, insert_or_assign_test_0) {
  s21::map<int, int> _map(1, 1);
  _map.insert_or_assign(0, 9);
  _map.insert_or_assign(0, 10);

  EXPECT_EQ(_map.size(), 2UL);

  auto i = _map.begin();
  EXPECT_EQ(i.ptr->key, 0);
  EXPECT_EQ(i.ptr->value, 10);
}

TEST(map_erase, erase_test_0) {
  s21::map<int, int> _map(1, 1);
  _map.insert_or_assign(5, 9);
  s21::map<int, int>::iterator i = _map.begin();
  ++i;
  _map.erase(i);
  EXPECT_EQ(_map.size(), 1UL);
}

TEST(map_erase, erase_test_1) {
  s21::map<int, int> _map(1, 1);
  s21::map<int, int>::iterator i = _map.begin();
  _map.erase(i);
  EXPECT_EQ(_map.size(), 1UL);
}

TEST(map_erase, erase_test_3) {
  s21::map<int, int> _map(1, 1);
  s21::map<int, int>::iterator i = _map.begin();
  ++i;
  _map.erase(i);
  EXPECT_EQ(_map.size(), 1UL);
}

TEST(map_swap, swap_test_0) {
  s21::map<int, int> _map(1, 1);
  _map.insert_or_assign(5, 9);
  s21::map<int, int> _map2(2, 2);
  _map.swap(_map2);
  EXPECT_EQ(_map.size(), 1UL);
  EXPECT_EQ(_map2.size(), 2UL);
}

TEST(map_merge, merge_test_0) {
  s21::map<int, int> _map(1, 1);
  _map.insert_or_assign(5, 9);
  _map.insert_or_assign(2, 2);
  _map.insert_or_assign(3, 3);
  _map.insert_or_assign(4, 4);
  _map.insert_or_assign(2, 2);
  s21::map<int, int> _map2(2, 2);
  _map2.merge(_map);
  EXPECT_EQ(_map.size(), 1UL);
  EXPECT_EQ(_map2.size(), 5UL);

  auto i = _map2.begin();
  EXPECT_EQ(i.ptr->key, 1);
  EXPECT_EQ(i.ptr->value, 1);

  ++i;
  EXPECT_EQ(i.ptr->key, 2);
  EXPECT_EQ(i.ptr->value, 2);

  ++i;
  EXPECT_EQ(i.ptr->key, 3);
  EXPECT_EQ(i.ptr->value, 3);

  ++i;
  EXPECT_EQ(i.ptr->key, 4);
  EXPECT_EQ(i.ptr->value, 4);

  ++i;
  EXPECT_EQ(i.ptr->key, 5);
  EXPECT_EQ(i.ptr->value, 9);
}

TEST(map_contains, contains_test_0) {
  s21::map<int, int> _map(1, 1);
  _map.insert_or_assign(5, 9);
  EXPECT_EQ(_map.contains(5), 1);
  EXPECT_EQ(_map.contains(6), 0);
}
