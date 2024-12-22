#include <array>

#include "test_main.h"

TEST(member_functions, def) {
  s21::array<double, 0> arr;

  EXPECT_EQ(arr.empty(), 1);
}

TEST(member_functions, not_def) {
  s21::array<double, 3> arr;

  EXPECT_EQ(arr.empty(), 0);
}

TEST(member_functions, initializer_list_) {
  s21::array<double, 3> arr = {1, 19, 1.9};

  EXPECT_EQ(arr.size(), 3UL);
}

TEST(member_functions, copy) {
  s21::array<double, 3> arr = {1, 19, 1.9};
  s21::array<double, 3> copy(arr);

  EXPECT_EQ(copy.size(), 3UL);
}

TEST(member_functions, move) {
  s21::array<double, 3> arr = {1, 19, 1.9};
  s21::array<double, 3> move(std::move(arr));

  EXPECT_EQ(move.size(), 3UL);
}

TEST(member_functions, eq) {
  s21::array<double, 3> arr = {1, 19, 1.9};
  s21::array<double, 3> move;
  move = std::move(arr);

  EXPECT_EQ(move.size(), 3UL);
}

// element access

TEST(element_access, at) {
  s21::array<double, 3> arr = {1, 19, 1.9};

  EXPECT_EQ(arr.at(1), 19);
}

TEST(element_access, at_throw) {
  s21::array<double, 3> arr = {1, 19, 1.9};

  EXPECT_THROW(arr.at(19), std::out_of_range);
}

TEST(element_access, operator_at) {
  s21::array<double, 3> arr = {1, 19, 1.9};

  EXPECT_EQ(arr[1], 19);
}

TEST(element_access, front) {
  s21::array<double, 3> arr = {1, 19, 1.9};

  EXPECT_EQ(arr.front(), 1UL);
}

TEST(element_access, back) {
  s21::array<double, 3> arr = {1, 19, 1.9};

  EXPECT_EQ(arr.back(), 1.9);
}

TEST(element_access, data) {
  s21::array<double, 3> arr = {1, 19, 1.9};
  double* value = arr.data();

  EXPECT_EQ(value[0], 1UL);
}

TEST(iterators, begin) {
  s21::array<double, 3> arr = {1, 19, 1.9};

  EXPECT_EQ(*(arr.begin()), 1UL);
}

TEST(iterators, end) {
  s21::array<double, 3> arr = {1, 19, 1.9};

  EXPECT_EQ(arr.end(), arr.begin() + 3);
}

TEST(capacity, empty) {
  s21::array<double, 3> arr = {1, 19, 1.9};

  EXPECT_EQ(arr.empty(), 0UL);
}

TEST(capacity, size) {
  s21::array<double, 3> arr = {1, 19, 1.9};

  EXPECT_EQ(arr.size(), 3UL);
}

TEST(capacity, max_size) {
  s21::array<double, 3> arr = {1, 19, 1.9};

  EXPECT_EQ(arr.max_size(), 3UL);
}

TEST(modifiers, swap) {
  s21::array<double, 3> arr = {1, 19, 1.9};
  s21::array<double, 3> arr2 = {9, 1, 19.19};
  arr.swap(arr2);

  EXPECT_EQ(arr.front(), 9UL);
  EXPECT_EQ(arr2.front(), 1UL);
  EXPECT_EQ(arr.back(), 19.19);
  EXPECT_EQ(arr2.back(), 1.9);
}

TEST(modifiers, fill) {
  s21::array<double, 3> arr = {1, 19, 1.9};
  arr.fill(5);

  EXPECT_EQ(arr.front(), 5);
  EXPECT_EQ(arr.back(), 5);
}