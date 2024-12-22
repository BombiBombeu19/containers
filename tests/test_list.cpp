#include <list>

#include "test_main.h"

TEST(List, Constructor_Default_Int) {
  s21::list<int> our_list;
  std::list<int> std_list;
  EXPECT_EQ(our_list.empty(), std_list.empty());
}

TEST(List, Constructor_Default_Double) {
  s21::list<double> our_list;
  std::list<double> std_list;
  EXPECT_EQ(our_list.empty(), std_list.empty());
}

TEST(List, Constructor_Default_String) {
  s21::list<std::string> our_list;
  std::list<std::string> std_list;
  EXPECT_EQ(our_list.empty(), std_list.empty());
}

TEST(List, Constructor_Size_Int) {
  s21::list<int> our_list(5);
  std::list<int> std_list(5);
  EXPECT_EQ(our_list.size(), std_list.size());
}

TEST(List, Constructor_Size_Double) {
  s21::list<double> our_list(5);
  std::list<double> std_list(5);
  EXPECT_EQ(our_list.size(), std_list.size());
}

TEST(List, Constructor_Size_String) {
  s21::list<std::string> our_list(5);
  std::list<std::string> std_list(5);
  EXPECT_EQ(our_list.size(), std_list.size());
}

TEST(List, Constructor_List_Int) {
  s21::list<int> our_list = {1, 2, 3};
  std::list<int> std_list = {1, 2, 3};
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
}

TEST(List, Constructor_List_Empty) {
  s21::list<int> our_list = {};
  std::list<int> std_list = {};
  EXPECT_EQ(our_list.empty(), std_list.empty());
}

TEST(List, Constructor_List_Double) {
  s21::list<double> our_list = {1.1, 2.2, 3.3};
  std::list<double> std_list = {1.1, 2.2, 3.3};
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
}

TEST(List, Constructor_List_String) {
  s21::list<std::string> our_list = {"1", "2", "3"};
  std::list<std::string> std_list = {"1", "2", "3"};
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
}

TEST(List, Constructor_Copy_Int) {
  s21::list<int> our_list = {1, 2, 3};
  std::list<int> std_list = {1, 2, 3};
  s21::list<int> our_copy(our_list);
  std::list<int> std_copy(std_list);
  EXPECT_EQ(our_copy.front(), std_copy.front());
  EXPECT_EQ(our_copy.back(), std_copy.back());
}

TEST(List, Constructor_Copy_Double) {
  s21::list<double> our_list = {1.1, 2.2, 3.3};
  std::list<double> std_list = {1.1, 2.2, 3.3};
  s21::list<double> our_copy(our_list);
  std::list<double> std_copy(std_list);
  EXPECT_EQ(our_copy.front(), std_copy.front());
  EXPECT_EQ(our_copy.back(), std_copy.back());
}

TEST(List, Constructor_Copy_String) {
  s21::list<std::string> our_list = {"1", "2", "3"};
  std::list<std::string> std_list = {"1", "2", "3"};
  s21::list<std::string> our_copy(our_list);
  std::list<std::string> std_copy(std_list);
  EXPECT_EQ(our_copy.front(), std_copy.front());
  EXPECT_EQ(our_copy.back(), std_copy.back());
}

TEST(List, Max_Size_Int) {
  s21::list<int> our_list = {1, 2, 3};
  std::list<int> std_list = {1, 2, 3};
  EXPECT_EQ(our_list.max_size(), std_list.max_size());
}

TEST(List, Max_Size_Double) {
  s21::list<double> our_list = {1.1, 2.2, 3.3};
  std::list<double> std_list = {1.1, 2.2, 3.3};
  EXPECT_EQ(our_list.max_size(), std_list.max_size());
}

TEST(List, Max_Size_String) {
  s21::list<std::string> our_list = {"1", "2", "3"};
  std::list<std::string> std_list = {"1", "2", "3"};
  EXPECT_EQ(our_list.max_size(), std_list.max_size());
}

TEST(List, Operator_Copy) {
  s21::list<int> our_list = {1, 2, 3};
  std::list<int> std_list = {1, 2, 3};
  s21::list<int> our_copy;
  our_copy = our_list;
  std::list<int> std_copy;
  std_copy = std_list;
  EXPECT_EQ(our_copy.front(), std_copy.front());
  EXPECT_EQ(our_copy.back(), std_copy.back());
}

TEST(List, Constructor_Move_Int) {
  s21::list<int> our_list = {1, 2, 3};
  std::list<int> std_list = {1, 2, 3};
  s21::list<int> our_copy(std::move(our_list));
  std::list<int> std_copy(std::move(std_list));
  EXPECT_EQ(our_copy.front(), std_copy.front());
  EXPECT_EQ(our_copy.back(), std_copy.back());
  EXPECT_EQ(our_list.empty(), std_list.empty());
}

TEST(List, Constructor_Move_Double) {
  s21::list<double> our_list = {1.1, 2.2, 3.3};
  std::list<double> std_list = {1.1, 2.2, 3.3};
  s21::list<double> our_copy(std::move(our_list));
  std::list<double> std_copy(std::move(std_list));
  EXPECT_EQ(our_copy.front(), std_copy.front());
  EXPECT_EQ(our_copy.back(), std_copy.back());
  EXPECT_EQ(our_list.empty(), std_list.empty());
}

TEST(List, Constructor_Move_String) {
  s21::list<std::string> our_list = {"1", "2", "3"};
  std::list<std::string> std_list = {"1", "2", "3"};
  s21::list<std::string> our_copy(std::move(our_list));
  std::list<std::string> std_copy(std::move(std_list));
  EXPECT_EQ(our_copy.front(), std_copy.front());
  EXPECT_EQ(our_copy.back(), std_copy.back());
  EXPECT_EQ(our_list.empty(), std_list.empty());
}

TEST(List, Operator_Move) {
  s21::list<int> our_list = {1, 2, 3};
  std::list<int> std_list = {1, 2, 3};
  s21::list<int> our_copy;
  our_copy = std::move(our_list);
  std::list<int> std_copy;
  std_copy = std::move(std_list);
  EXPECT_EQ(our_copy.front(), std_copy.front());
  EXPECT_EQ(our_copy.back(), std_copy.back());
  EXPECT_EQ(our_list.empty(), std_list.empty());
}

TEST(List, Size_Int) {
  s21::list<int> our_list = {1, 2, 3, 4};
  std::list<int> std_list = {1, 2, 3, 4};
  EXPECT_EQ(our_list.size(), std_list.size());
}

TEST(List, Size_Double) {
  s21::list<double> our_list = {1.1, 2.2, 3.3, 4.4};
  std::list<double> std_list = {1.1, 2.2, 3.3, 4.4};
  EXPECT_EQ(our_list.size(), std_list.size());
}

TEST(List, Size_String) {
  s21::list<std::string> our_list = {"1", "2", "3", "4"};
  std::list<std::string> std_list = {"1", "2", "3", "4"};
  EXPECT_EQ(our_list.size(), std_list.size());
}

TEST(List, Clear) {
  s21::list<int> our_list = {1, 2, 3, 4};
  std::list<int> std_list = {1, 2, 3, 4};
  our_list.clear();
  std_list.clear();
  EXPECT_EQ(our_list.empty(), std_list.empty());
}

TEST(List, Sort_Empty) {
  s21::list<int> our_list;
  std::list<int> std_list;
  our_list.sort();
  std_list.sort();
  EXPECT_EQ(our_list.empty(), std_list.empty());
}

TEST(List, Sort_1_Int) {
  s21::list<int> our_list = {4, 2, 1, 5};
  std::list<int> std_list = {4, 2, 1, 5};
  our_list.sort();
  std_list.sort();
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
}

TEST(List, Sort_2_Int) {
  s21::list<int> our_list = {9, 7, 0, 4, 6, 3, 1, 8, 2, 5};
  std::list<int> std_list = {9, 7, 0, 4, 6, 3, 1, 8, 2, 5};
  our_list.sort();
  std_list.sort();
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
}

TEST(List, Sort_3_Double) {
  s21::list<double> our_list = {9.9, 7.7, 0.0, 4.4, 6.6,
                                3.3, 1.1, 8.8, 2.2, 5.5};
  std::list<double> std_list = {9.9, 7.7, 0.0, 4.4, 6.6,
                                3.3, 1.1, 8.8, 2.2, 5.5};
  our_list.sort();
  std_list.sort();
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
}

TEST(List, Sort_4_String) {
  s21::list<std::string> our_list = {"9", "7", "0", "4", "6",
                                     "3", "1", "8", "2", "5"};
  std::list<std::string> std_list = {"9", "7", "0", "4", "6",
                                     "3", "1", "8", "2", "5"};
  our_list.sort();
  std_list.sort();
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
}

TEST(List, Reverse_1_Int) {
  s21::list<int> our_list = {1, 2, 3, 4, 5};
  std::list<int> std_list = {1, 2, 3, 4, 5};
  our_list.reverse();
  std_list.reverse();
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
}

TEST(List, Reverse_2_Int) {
  s21::list<int> our_list = {5, 4, 3, 2, 1};
  std::list<int> std_list = {5, 4, 3, 2, 1};
  our_list.reverse();
  std_list.reverse();
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
}

TEST(List, Reverse_3_Double) {
  s21::list<double> our_list = {5.5, 4.4, 3.3, 2.2, 1.1};
  std::list<double> std_list = {5.5, 4.4, 3.3, 2.2, 1.1};
  our_list.reverse();
  std_list.reverse();
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
}

TEST(List, Reverse_4_String) {
  s21::list<std::string> our_list = {"5", "4", "3", "2", "1"};
  std::list<std::string> std_list = {"5", "4", "3", "2", "1"};
  our_list.reverse();
  std_list.reverse();
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
}

TEST(List, Merge) {
  s21::list<int> our_list_first = {5, 9, 1, 3, 3};
  s21::list<int> our_list_second = {8, 7, 2, 3, 4, 4};
  std::list<int> std_list_first = {5, 9, 1, 3, 3};
  std::list<int> std_list_second = {8, 7, 2, 3, 4, 4};
  our_list_first.merge(our_list_second);
  std_list_first.merge(std_list_second);
  EXPECT_EQ(our_list_first.front(), std_list_first.front());
  EXPECT_EQ(our_list_first.back(), std_list_first.back());
  EXPECT_EQ(our_list_second.empty(), std_list_second.empty());
}

TEST(List, Merge_Empty) {
  s21::list<int> our_list_first = {5, 9, 1, 3, 3};
  s21::list<int> our_list_second = {};
  std::list<int> std_list_first = {5, 9, 1, 3, 3};
  std::list<int> std_list_second = {};
  our_list_first.merge(our_list_second);
  std_list_first.merge(std_list_second);
  EXPECT_EQ(our_list_first.front(), std_list_first.front());
  EXPECT_EQ(our_list_first.back(), std_list_first.back());
  EXPECT_EQ(our_list_second.empty(), std_list_second.empty());
}

TEST(List, Unique) {
  s21::list<int> our_list = {1, 2, 2, 3, 3, 3, 4, 4, 6, 4, 5, 5, 5, 5, 5, 1};
  std::list<int> std_list = {1, 2, 2, 3, 3, 3, 4, 4, 6, 4, 5, 5, 5, 5, 5, 1};
  our_list.unique();
  std_list.unique();
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
}

TEST(List, Unique_Empty) {
  s21::list<int> our_list = {};
  our_list.unique();
  EXPECT_EQ(our_list.empty(), true);
}

TEST(List, Push_Back) {
  s21::list<int> our_list = {999, 999, 999};
  std::list<int> std_list = {999, 999, 999};
  our_list.push_back(1);
  std_list.push_back(1);
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
  our_list.push_back(2);
  std_list.push_back(2);
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
  our_list.push_back(3);
  std_list.push_back(3);
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
}

TEST(List, Push_Front) {
  s21::list<int> our_list;
  std::list<int> std_list;
  our_list.push_front(1);
  std_list.push_front(1);
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
  our_list.push_front(2);
  std_list.push_front(2);
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
  our_list.push_front(3);
  std_list.push_front(3);
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
}

TEST(List, Pop_Front) {
  s21::list<int> our_list;
  std::list<int> std_list;
  our_list.push_back(1);
  std_list.push_back(1);
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
  our_list.push_back(2);
  std_list.push_back(2);
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
  our_list.push_back(3);
  std_list.push_back(3);
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
  our_list.pop_front();
  std_list.pop_front();
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
  our_list.pop_front();
  std_list.pop_front();
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
  our_list.pop_front();
  std_list.pop_front();
  EXPECT_TRUE(our_list.empty());
  EXPECT_TRUE(std_list.empty());
}

TEST(List, Pop_Back) {
  s21::list<int> our_list;
  std::list<int> std_list;
  our_list.push_back(1);
  std_list.push_back(1);
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
  our_list.push_back(2);
  std_list.push_back(2);
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
  our_list.push_back(3);
  std_list.push_back(3);
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
  our_list.pop_back();
  std_list.pop_back();
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
  our_list.pop_back();
  std_list.pop_back();
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
  our_list.pop_back();
  std_list.pop_back();
  EXPECT_TRUE(our_list.empty());
  EXPECT_TRUE(std_list.empty());
}

TEST(List, Pop_Back_Empty) {
  s21::list<int> our_list = {};
  our_list.pop_back();
  EXPECT_TRUE(our_list.empty());
}

TEST(List, Pop_Front_Empty) {
  s21::list<int> our_list = {};
  our_list.pop_front();
  EXPECT_TRUE(our_list.empty());
}

TEST(List, Iterator_Begin) {
  s21::list<int> our_list = {1, 2, 3};
  std::list<int> std_list = {1, 2, 3};
  s21::list<int>::iterator our_it;
  our_it = our_list.begin();
  std::list<int>::iterator std_it;
  std_it = std_list.begin();
  EXPECT_EQ(*our_it, *std_it);
}

TEST(List, Iterator_BeginPlusAndMinus) {
  s21::list<int> our_list = {1, 2, 3};
  std::list<int> std_list = {1, 2, 3};
  s21::list<int>::iterator our_it;
  our_it = our_list.begin();
  ++our_it;
  std::list<int>::iterator std_it;
  std_it = std_list.begin();
  ++std_it;
  EXPECT_EQ(*our_it, *std_it);
  --our_it;
  --std_it;
  EXPECT_EQ(*our_it, *std_it);
}

TEST(List, Iterator_End_Last) {
  s21::list<int> our_list = {1, 2, 3};
  std::list<int> std_list = {1, 2, 3};
  s21::list<int>::iterator our_it;
  our_it = our_list.end();
  --our_it;
  std::list<int>::iterator std_it;
  std_it = std_list.end();
  --std_it;
  EXPECT_EQ(*our_it, *std_it);
}

TEST(List, Swap) {
  s21::list<int> our_list = {4, 3, 2, 1};
  s21::list<int> std_list = {1, 2, 3, 4};
  our_list.swap(std_list);
  EXPECT_EQ(our_list.back(), std_list.front());
  EXPECT_EQ(our_list.front(), std_list.back());
}

TEST(List, Erase) {
  s21::list<int> our_list = {1, 2, 3, 4, 5};
  std::list<int> std_list = {1, 2, 3, 4, 5};
  our_list.erase(our_list.begin());
  std_list.erase(std_list.begin());
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
  s21::list<int>::iterator our_it;
  our_it = our_list.begin();
  ++our_it;
  ++our_it;
  our_list.erase(our_it);
  std::list<int>::iterator std_it;
  std_it = std_list.begin();
  ++std_it;
  ++std_it;
  std_list.erase(std_it);
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
}

TEST(List, Erase_Empty) {
  s21::list<int> our_list = {};
  our_list.erase(our_list.begin());
  EXPECT_TRUE(our_list.empty());
}

TEST(List, Insert_Bit_Test) {
  s21::list<int> our_list;
  std::list<int> std_list;
  s21::list<int>::iterator our_it = our_list.begin();
  std::list<int>::iterator std_it = std_list.begin();
  our_list.insert(our_it, 5);
  std_list.insert(std_it, 5);
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());

  our_list.insert(our_it, 99);
  std_list.insert(std_it, 99);
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());

  our_list.insert(our_it, 5);
  std_list.insert(std_it, 5);
  our_list.insert(our_it, 5);
  std_list.insert(std_it, 5);
  our_list.insert(our_it, 5);
  std_list.insert(std_it, 5);
  our_list.insert(our_it, 10);
  std_list.insert(std_it, 10);
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());

  --our_it;
  --our_it;
  --our_it;
  --our_it;

  --std_it;
  --std_it;
  --std_it;
  --std_it;

  our_list.insert(our_it, 1);
  std_list.insert(std_it, 1);

  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());

  our_list.insert(our_list.end(), 999);
  std_list.insert(std_list.end(), 999);
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());

  our_list.insert(our_list.end(), 999);
  std_list.insert(std_list.end(), 999);
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());

  --our_it;
  --our_it;
  --std_it;
  --std_it;

  our_list.insert(our_it, 1);
  std_list.insert(std_it, 1);
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());

  our_list.insert(our_list.begin(), 1);
  std_list.insert(std_list.begin(), 1);
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
}

TEST(List, Insert_Front) {
  s21::list<int> list_int = {1, 3, 5};
  std::list<int> std_list_int = {1, 3, 5};

  list_int.insert(list_int.begin(), 7);
  std_list_int.insert(std_list_int.begin(), 7);

  EXPECT_EQ(list_int.front(), std_list_int.front());
  EXPECT_EQ(list_int.size(), std_list_int.size());
}

TEST(List, Insert_Back) {
  s21::list<int> list_int = {1, 3, 5};
  std::list<int> std_list_int = {1, 3, 5};

  std_list_int.insert(std_list_int.end(), 7);
  list_int.insert(list_int.end(), 7);

  EXPECT_EQ(list_int.back(), std_list_int.back());
  EXPECT_EQ(list_int.size(), std_list_int.size());
}

TEST(List, Insert_Bit_Test_1_1) {
  s21::list<int> list_int = {1, 2, 3, 4};
  s21::list<int> list_int_2 = {5, 6, 7};
  s21::list<int> list_int_ref = {5, 6, 7, 1, 2, 3, 4};

  std::list<int> std_list_int = {1, 2, 3, 4};
  std::list<int> std_list_int_2 = {5, 6, 7};
  std::list<int> std_list_int_ref = {5, 6, 7, 1, 2, 3, 4};

  auto std_pos = std_list_int.begin();
  auto pos = list_int.begin();
  list_int.splice(pos, list_int_2);
  std_list_int.splice(std_pos, std_list_int_2);

  EXPECT_EQ(list_int.front(), list_int_ref.front());
  EXPECT_EQ(std_list_int.back(), std_list_int_ref.back());
  EXPECT_EQ(list_int.empty(), std_list_int.empty());
  EXPECT_EQ(list_int_2.empty(), std_list_int_2.empty());
}

TEST(List, Splice_Bit_Test_2) {
  s21::list<int> list_to_splice_into = {1};
  std::list<int> std_list_to_splice_into = {1};
  s21::list<int> list_to_splice_from = {};
  std::list<int> std_list_to_splice_from = {};

  list_to_splice_into.splice(list_to_splice_into.cend(), list_to_splice_from);
  std_list_to_splice_into.splice(std_list_to_splice_into.cend(),
                                 std_list_to_splice_from);

  EXPECT_EQ(list_to_splice_into.front(), std_list_to_splice_into.front());
  EXPECT_EQ(list_to_splice_into.back(), std_list_to_splice_into.back());
}

TEST(List, Splice_Bit_Test_3) {
  s21::list<int> list_to_splice_into = {999};
  std::list<int> std_list_to_splice_into = {999};
  s21::list<int> list_to_splice_from = {2, 3, 4, 5};
  std::list<int> std_list_to_splice_from = {2, 3, 4, 5};

  list_to_splice_into.splice(list_to_splice_into.cbegin(), list_to_splice_from);
  std_list_to_splice_into.splice(std_list_to_splice_into.cbegin(),
                                 std_list_to_splice_from);

  EXPECT_EQ(list_to_splice_into.front(), std_list_to_splice_into.front());
  EXPECT_EQ(list_to_splice_into.back(), std_list_to_splice_into.back());
}

TEST(List_Insert_Many, Insert_Many) {
  s21::list<int> list_int = {1, 2, 6, 7, 8};
  list_int.insert_many(list_int.cbegin(), 3, 4, 5);

  auto it = list_int.begin();
  EXPECT_EQ(*it, 3);
  ++it;
  EXPECT_EQ(*it, 4);
}

TEST(List_Insert_Many, Insert_Many_Back) {
  s21::list<int> list_int = {1, 2, 6, 7, 8};
  list_int.insert_many_back(3, 4, 5);
  auto it = list_int.begin();

  for (int i = 0; i < 5; ++i) {
    ++it;
  }
  EXPECT_EQ(*it, 3);
  ++it;
  EXPECT_EQ(*it, 4);
  ++it;
}

TEST(List, Insert_Many_Back) {
  s21::list<int> our_list = {1, 2, 3, 4, 5};
  s21::list<int>::iterator our_it;
  our_list.insert_many_back(7, 8, 9);
  our_it = our_list.end();
  --our_it;
  EXPECT_EQ(*our_it, 9);
  --our_it;
  EXPECT_EQ(*our_it, 8);
  --our_it;
  EXPECT_EQ(*our_it, 7);
  --our_it;
  EXPECT_EQ(*our_it, 5);
  --our_it;
  EXPECT_EQ(*our_it, 4);
}

TEST(List, Insert_Many_Front) {
  s21::list<int> our_list = {1, 2, 3, 4, 5};
  s21::list<int>::iterator our_it;
  our_list.insert_many_front(7, 8, 9);
  our_it = our_list.begin();
  EXPECT_EQ(*our_it, 7);
  ++our_it;
  EXPECT_EQ(*our_it, 8);
  ++our_it;
  EXPECT_EQ(*our_it, 9);
  ++our_it;
  EXPECT_EQ(*our_it, 1);
  ++our_it;
  EXPECT_EQ(*our_it, 2);
}