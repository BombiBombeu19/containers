#include <vector>

#include "test_main.h"

TEST(VectorTest, DefaultConstructor_EmptyVector) {
  s21::vector<int> v;
  std::vector<int> std_v;
  EXPECT_TRUE(v.empty());
  EXPECT_EQ(v.size(), std_v.size());
}

TEST(VectorTest, DefaultConstructor_EmptyVector_Double) {
  s21::vector<double> v;
  std::vector<double> std_v;
  EXPECT_TRUE(v.empty());
  EXPECT_EQ(v.size(), std_v.size());
}

TEST(VectorTest, DefaultConstructor_EmptyVector_String) {
  s21::vector<std::string> v;
  std::vector<std::string> std_v;
  EXPECT_TRUE(v.empty());
  EXPECT_EQ(v.size(), std_v.size());
}

TEST(VectorTest, SizeConstructor_PositiveSize) {
  const size_t size = 5;
  s21::vector<int> v(size);
  EXPECT_FALSE(v.empty());
  EXPECT_EQ(v.size(), size);
  for (size_t i = 0; i < size; ++i) {
    EXPECT_EQ(v[i], 0);
  }
}

TEST(VectorTest, SizeConstructor_NegativeSize) {
  const size_t size = -5;
  EXPECT_ANY_THROW(s21::vector<int> v(size));
}

TEST(VectorTest, SizeConstructor_ZeroSize) {
  const size_t size = 0;
  s21::vector<int> v(size);
  EXPECT_TRUE(v.empty());
  EXPECT_EQ(v.size(), size);
}

TEST(VectorTest, InitializerListConstructor_EmptyList) {
  s21::vector<int> v = {};
  std::vector<int> std_v = {};
  EXPECT_TRUE(v.empty());
  EXPECT_EQ(v.size(), std_v.size());
}

TEST(VectorTest, InitializerListConstructor_NonEmptyList) {
  s21::vector<int> v = {1, 2, 3, 4, 5};
  std::vector<int> std_v = {1, 2, 3, 4, 5};
  EXPECT_FALSE(v.empty());
  EXPECT_EQ(v.size(), std_v.size());
  EXPECT_EQ(v[0], std_v[0]);
  EXPECT_EQ(v[1], std_v[1]);
  EXPECT_EQ(v[2], std_v[2]);
  EXPECT_EQ(v[3], std_v[3]);
  EXPECT_EQ(v[4], std_v[4]);
}

TEST(VectorTest, CopyConstructor_EmptyVector) {
  s21::vector<int> v1;
  s21::vector<int> v2(v1);

  std::vector<int> std_v1;
  std::vector<int> std_v2(std_v1);

  EXPECT_TRUE(v2.empty());
  EXPECT_EQ(v2.size(), std_v2.size());
}

TEST(VectorTest, CopyConstructor_NonEmptyVector) {
  s21::vector<int> v1 = {1, 2, 3};
  s21::vector<int> v2(v1);
  EXPECT_EQ(v2.size(), v1.size());
  for (size_t i = 0; i < v1.size(); ++i) {
    EXPECT_EQ(v2[i], v1[i]);
  }
}

TEST(VectorTest, MoveConstructor_EmptyVector) {
  s21::vector<int> v1;
  s21::vector<int> v2(std::move(v1));

  std::vector<int> std_v1;
  std::vector<int> std_v2(std::move(std_v1));

  EXPECT_TRUE(v2.empty());
  EXPECT_EQ(v2.size(), std_v2.size());
}

TEST(VectorTest, MoveConstructor_NonEmptyVector) {
  s21::vector<int> v1 = {1, 2, 3};
  s21::vector<int> v2(std::move(v1));

  size_t correct_size = 3;

  EXPECT_EQ(v2.size(), correct_size);
  EXPECT_TRUE(v1.empty());
}

TEST(VectorTest, Destructor_EmptyVector) {
  s21::vector<int>* v = new s21::vector<int>();
  delete v;
}

TEST(VectorTest, Destructor_NonEmptyVector) {
  s21::vector<int>* v = new s21::vector<int>{1, 2, 3};
  delete v;
}

TEST(VectorTest, MoveAssignmentOperator_EmptyToEmpty) {
  s21::vector<int> v1;
  s21::vector<int> v2;

  std::vector<int> std_v1;
  std::vector<int> std_v2;

  v2 = std::move(v1);
  std_v2 = std::move(std_v1);

  EXPECT_TRUE(v2.empty());
  EXPECT_EQ(v2.size(), std_v2.size());
}

TEST(VectorTest, MoveAssignmentOperator_NonEmptyToEmpty) {
  s21::vector<int> v1 = {1, 2, 3};
  s21::vector<int> v2;

  std::vector<int> std_v1 = {1, 2, 3};
  std::vector<int> std_v2;

  v2 = std::move(v1);
  std_v2 = std::move(std_v1);

  EXPECT_EQ(v2.size(), std_v2.size());
  EXPECT_TRUE(v1.empty());
}

TEST(VectorTest, MoveAssignmentOperator_EmptyToNonEmpty) {
  s21::vector<int> v1;
  s21::vector<int> v2 = {4, 5, 6};

  std::vector<int> std_v1;
  std::vector<int> std_v2 = {4, 5, 6};

  v2 = std::move(v1);
  std_v2 = std::move(std_v1);

  EXPECT_TRUE(v2.empty());
  EXPECT_EQ(v2.size(), std_v2.size());
}

TEST(VectorTest, MoveAssignmentOperator_NonEmptyToNonEmpty) {
  s21::vector<int> v1 = {1, 2, 3};
  s21::vector<int> v2 = {4, 5, 6};

  std::vector<int> std_v1 = {1, 2, 3};
  std::vector<int> std_v2 = {4, 5, 6};

  v2 = std::move(v1);
  std_v2 = std::move(std_v1);

  EXPECT_EQ(v2.size(), std_v2.size());
  EXPECT_TRUE(v1.empty());
}

TEST(VectorTest, At_ValidIndex) {
  s21::vector<int> v = {1, 2, 3, 4, 5};
  EXPECT_EQ(v.at(0), 1);
  EXPECT_EQ(v.at(2), 3);
  EXPECT_EQ(v.at(4), 5);
}

TEST(VectorTest, At_InvalidIndex_Double) {
  s21::vector<double> v = {1.1, 2.2, 3.3, 4.4, 5.5};
  EXPECT_THROW(v.at(5), std::out_of_range);
  EXPECT_THROW(v.at(10), std::out_of_range);
}

TEST(VectorTest, At_InvalidIndex_String) {
  s21::vector<std::string> v = {"1", "2", "3", "4", "5"};
  EXPECT_THROW(v.at(5), std::out_of_range);
  EXPECT_THROW(v.at(10), std::out_of_range);
}

TEST(VectorTest, At_InvalidIndex) {
  s21::vector<int> v = {1, 2, 3, 4, 5};
  EXPECT_THROW(v.at(5), std::out_of_range);
  EXPECT_THROW(v.at(10), std::out_of_range);
}

TEST(VectorTest, IndexOperator_ValidIndex) {
  s21::vector<int> v = {1, 2, 3, 4, 5};
  EXPECT_EQ(v[0], 1);
  EXPECT_EQ(v[2], 3);
  EXPECT_EQ(v[4], 5);
}

TEST(VectorTest, IndexOperator_InvalidIndex) {
  s21::vector<int> v = {1, 2, 3, 4, 5};
  EXPECT_ANY_THROW(v[5]);
  EXPECT_ANY_THROW(v[10]);
}

TEST(VectorTest, ConstIndexOperator_ValidIndex) {
  const s21::vector<int> v = {1, 2, 3, 4, 5};
  EXPECT_EQ(v[0], 1);
  EXPECT_EQ(v[2], 3);
  EXPECT_EQ(v[4], 5);
}

TEST(VectorTest, FrontConst_ValidVector) {
  const s21::vector<int> v = {1, 2, 3, 4, 5};
  EXPECT_EQ(v.front(), 1);
}

TEST(VectorTest, FrontConst_EmptyVector) {
  const s21::vector<int> v;
  EXPECT_THROW(v.front(), std::out_of_range);
}

TEST(VectorTest, BackConst_ValidVector) {
  const s21::vector<int> v = {1, 2, 3, 4, 5};
  EXPECT_EQ(v.back(), 5);
}

TEST(VectorTest, BackConst_EmptyVector) {
  const s21::vector<int> v;
  EXPECT_THROW(v.back(), std::out_of_range);
}

TEST(VectorTest, Data_ValidVector) {
  s21::vector<int> v = {1, 2, 3, 4, 5};
  int* dataPtr = v.data();
  EXPECT_EQ(*dataPtr, 1);
  *dataPtr = 10;
  EXPECT_EQ(v[0], 10);
}

TEST(VectorTest, Data_EmptyVector) {
  s21::vector<int> v;
  int* dataPtr = v.data();
  EXPECT_EQ(dataPtr, nullptr);
}

TEST(Vector_Iterators, Begin) {
  s21::vector<int> int_temp = {1, 2, 3};
  s21::vector<int>::iterator it = int_temp.begin();

  EXPECT_EQ(*it, 1);
}

TEST(Vector_Iterators, End) {
  s21::vector<int> int_temp = {1, 2, 3};
  s21::vector<int>::iterator it = int_temp.begin();
  ++it;
  ++it;
  ++it;

  EXPECT_EQ(*(int_temp.end()), *it);
}

TEST(Vector_Iterators, Middle) {
  s21::vector<int> int_temp = {1, 2, 3};
  s21::vector<int>::iterator it = int_temp.begin();
  ++it;
  ++it;
  ++it;
  --it;
  EXPECT_EQ(*it, 3);
}

TEST(ConstVector_Iterators, Empty) {
  s21::vector<int> int_temp = {1, 2, 3};
  s21::vector<int>::const_iterator it = int_temp.cbegin();

  EXPECT_EQ(*it, 1);
}

TEST(ConstVector_Iterators, Middle) {
  s21::vector<int> int_temp = {1, 2, 3};
  s21::vector<int>::const_iterator it = int_temp.cbegin();
  ++it;
  ++it;
  ++it;
  --it;
  EXPECT_EQ(*it, 3);
}

TEST(VectorTest, Begin_ValidVector) {
  s21::vector<int> v = {1, 2, 3, 4, 5};
  auto it = v.begin();
  EXPECT_EQ(*it, 1);
  *it = 10;
  EXPECT_EQ(v[0], 10);
}

TEST(VectorTest, Begin_EmptyVector) {
  s21::vector<int> v;
  auto it = v.begin();
  EXPECT_EQ(it, v.end());
}

TEST(VectorTest, End_ValidVector) {
  s21::vector<int> v = {1, 2, 3, 4, 5};
  auto it = v.end();
  auto beginIt = v.begin();
  EXPECT_NE(it, beginIt);
}

TEST(VectorTest, End_EmptyVector) {
  s21::vector<int> v;
  auto it = v.end();
  EXPECT_EQ(it, v.begin());
}

TEST(VectorTest, CBegin_ValidVector) {
  const s21::vector<int> v = {1, 2, 3, 4, 5};
  auto it = v.cbegin();
  EXPECT_EQ(*it, 1);
}

TEST(VectorTest, CBegin_EmptyVector) {
  const s21::vector<int> v;
  auto it = v.cbegin();
  EXPECT_EQ(it, v.cend());
}

TEST(VectorTest, CEnd_ValidVector) {
  const s21::vector<int> v = {1, 2, 3, 4, 5};
  auto it = v.cend();
  auto beginIt = v.cbegin();
  ++beginIt;
  ++beginIt;
  ++beginIt;
  ++beginIt;
  ++beginIt;
  EXPECT_EQ(it, beginIt);
}

TEST(VectorTest, CEnd_EmptyVector) {
  const s21::vector<int> v;
  auto it = v.cend();
  EXPECT_EQ(it, v.cbegin());
}

TEST(VectorTest, Empty_EmptyVector) {
  s21::vector<int> v;
  EXPECT_TRUE(v.empty());
}

TEST(VectorTest, Empty_NonEmptyVector) {
  s21::vector<int> v = {1, 2, 3};
  EXPECT_FALSE(v.empty());
}

TEST(VectorTest, Size_EmptyVector) {
  s21::vector<int> v;
  std::vector<int> std_v;
  EXPECT_EQ(v.size(), std_v.size());
}

TEST(VectorTest, Size_NonEmptyVector) {
  s21::vector<int> v = {1, 2, 3};
  std::vector<int> std_v = {1, 2, 3};

  EXPECT_EQ(v.size(), std_v.size());
}

TEST(VectorTest, MaxSize_Int) {
  const s21::vector<int> v;
  const std::vector<int> std_v;
  EXPECT_EQ(v.max_size(), std_v.max_size());
}

TEST(VectorTest, MaxSize_String) {
  const s21::vector<std::string> v;
  const std::vector<std::string> std_v;
  EXPECT_EQ(v.max_size(), std_v.max_size());
}

TEST(VectorTest, Max_Size_Double) {
  const s21::vector<double> v;
  const std::vector<double> std_v;
  EXPECT_EQ(v.max_size(), std_v.max_size());
}

TEST(VectorTest, Reserve_IncreaseCapacity) {
  s21::vector<int> v = {1, 2, 3};
  std::vector<int> std_v = {1, 2, 3};

  v.reserve(1000);
  std_v.reserve(1000);

  EXPECT_EQ(v.size(), std_v.size());
  EXPECT_EQ(v.capacity(), std_v.capacity());
}

TEST(VectorTest, Reserve_ZeroCapacity) {
  s21::vector<int> v = {1, 2, 3};
  std::vector<int> std_v = {1, 2, 3};
  v.reserve(0);
  std_v.reserve(0);
  EXPECT_EQ(v.size(), std_v.size());
  EXPECT_EQ(v.capacity(), std_v.capacity());
}

TEST(VectorTest, Reserve_NegativeCapacity) {
  s21::vector<int> v = {1, 2, 3};
  EXPECT_ANY_THROW(v.reserve(-1));
}

TEST(VectorTest, Reserve_DecreaseCapacity) {
  s21::vector<int> v = {1, 2, 3, 4, 5};
  size_t initialCapacity = v.capacity();
  size_t newCapacity = initialCapacity - 2;
  v.reserve(newCapacity);
  EXPECT_LE(v.capacity(), initialCapacity);
  EXPECT_GE(v.capacity(), newCapacity);
}

TEST(VectorTest, Capacity_EmptyVector) {
  s21::vector<int> v;
  std::vector<int> std_v;
  EXPECT_EQ(v.capacity(), std_v.capacity());
}

TEST(VectorTest, Capacity_NonEmptyVector) {
  s21::vector<int> v = {1, 2, 3};
  EXPECT_EQ(v.capacity(), v.size());
}

TEST(VectorTest, ShrinkToFit_EmptyVector) {
  s21::vector<int> v;
  v.shrink_to_fit();

  std::vector<int> std_v;
  std_v.shrink_to_fit();
  EXPECT_GE(v.capacity(), std_v.capacity());
}

TEST(VectorTest, ShrinkToFit_NonEmptyVector) {
  s21::vector<int> v = {1, 2, 3, 4, 5};
  size_t initialCapacity = v.capacity();
  v.pop_back();
  v.shrink_to_fit();
  EXPECT_LE(v.capacity(), v.size());
  EXPECT_LE(v.capacity(), initialCapacity);
}

TEST(VectorTest, Clear_EmptyVector) {
  s21::vector<int> v;
  v.clear();

  std::vector<int> std_v;
  std_v.clear();

  EXPECT_TRUE(v.empty());
  EXPECT_EQ(v.size(), std_v.size());
  EXPECT_GE(v.capacity(), std_v.capacity());
}

TEST(VectorTest, Clear_NonEmptyVector) {
  s21::vector<int> v = {1, 2, 3, 4, 5};
  v.clear();
  std::vector<int> std_v = {1, 2, 3, 4, 5};
  std_v.clear();

  EXPECT_TRUE(v.empty());
  EXPECT_EQ(v.size(), std_v.size());
  EXPECT_GE(v.capacity(), std_v.capacity());
}

TEST(VectorTest, PushBack_EmptyVector) {
  s21::vector<int> v;
  v.push_back(1);

  std::vector<int> std_v;
  std_v.push_back(1);

  EXPECT_EQ(v.size(), std_v.size());
  EXPECT_EQ(v[0], std_v[0]);
}

TEST(VectorTest, PushBack_NonEmptyVector) {
  s21::vector<int> v = {1, 2, 3};
  v.push_back(4);
  std::vector<int> std_v = {1, 2, 3};
  std_v.push_back(4);
  EXPECT_EQ(v.size(), std_v.size());
  EXPECT_EQ(v[3], std_v[3]);
}

TEST(VectorTest, PopBack_NonEmptyVector) {
  s21::vector<int> v = {1, 2, 3};
  v.pop_back();
  std::vector<int> std_v = {1, 2, 3};
  std_v.pop_back();
  EXPECT_EQ(v.size(), std_v.size());
  EXPECT_EQ(v.back(), std_v.back());
}

TEST(VectorTest, PopBack_EmptyVector) {
  s21::vector<int> v;
  v.pop_back();
  EXPECT_TRUE(v.empty());
}

TEST(VectorTest, Swap_NonEmptyVectors) {
  s21::vector<int> v1 = {1, 2, 3};
  s21::vector<int> v2 = {4, 5, 6};

  std::vector<int> std_v1 = {1, 2, 3};
  std::vector<int> std_v2 = {4, 5, 6};

  v1.swap(v2);
  std_v1.swap(std_v2);

  EXPECT_EQ(v1.size(), std_v1.size());
  EXPECT_EQ(v2.size(), std_v2.size());

  EXPECT_EQ(v1[0], std_v1[0]);
  EXPECT_EQ(v1[2], std_v1[2]);

  EXPECT_EQ(v2[0], std_v2[0]);
  EXPECT_EQ(v2[2], std_v2[2]);
}

TEST(VectorTest, Swap_EmptyAndNonEmptyVectors) {
  s21::vector<int> v1;
  s21::vector<int> v2 = {1, 2, 3};
  std::vector<int> std_v1;
  std::vector<int> std_v2 = {1, 2, 3};

  v1.swap(v2);
  std_v1.swap(std_v2);

  EXPECT_EQ(v1.size(), std_v1.size());
  EXPECT_FALSE(v1.empty());
  EXPECT_EQ(v2.size(), std_v2.size());
  EXPECT_TRUE(v2.empty());
}

TEST(VectorTest, Insert_Empty) {
  s21::vector<int> v = {};
  std::vector<int> std_v = {};

  auto it = v.insert(v.begin(), 1);
  auto std_it = std_v.insert(std_v.begin(), 1);

  EXPECT_EQ(v.size(), std_v.size());
  EXPECT_EQ(v[0], std_v[0]);
  EXPECT_EQ(*it, *std_it);
}

TEST(VectorTest, Insert_Beginning) {
  s21::vector<int> v = {2, 3, 4};
  std::vector<int> std_v = {2, 3, 4};

  auto it = v.insert(v.begin(), 1);
  auto std_it = std_v.insert(std_v.begin(), 1);

  EXPECT_EQ(v.size(), std_v.size());
  EXPECT_EQ(v[0], std_v[0]);
  EXPECT_EQ(*it, *std_it);
}

TEST(VectorTest, Insert_Middle) {
  s21::vector<int> v = {1, 3, 4};
  std::vector<int> std_v = {1, 3, 4};

  auto it = v.insert(v.begin() + 1, 2);
  auto std_it = std_v.insert(std_v.begin() + 1, 2);

  EXPECT_EQ(v.size(), std_v.size());
  EXPECT_EQ(v[1], std_v[1]);
  EXPECT_EQ(*(it + 1), *(std_it + 1));
}

TEST(VectorTest, Insert_End) {
  s21::vector<int> v = {1, 2, 3};
  std::vector<int> std_v = {1, 2, 3};

  auto it = v.insert(v.end(), 4);
  auto std_it = std_v.insert(std_v.end(), 4);

  EXPECT_EQ(v.size(), std_v.size());
  EXPECT_EQ(v[3], std_v[3]);
  EXPECT_EQ(*(it + 2), *(std_it + 2));
}

TEST(VectorTest, Erase_Beginning) {
  s21::vector<int> v = {1, 2, 3, 4};
  std::vector<int> std_v = {1, 2, 3, 4};

  v.erase(v.begin());
  std_v.erase(std_v.begin());

  EXPECT_EQ(v.size(), std_v.size());
  EXPECT_EQ(v[0], std_v[0]);
}

TEST(VectorTest, Erase_Middle) {
  s21::vector<int> v = {1, 2, 3, 4};
  std::vector<int> std_v = {1, 2, 3, 4};

  v.erase(v.begin() + 1);
  std_v.erase(std_v.begin() + 1);

  EXPECT_EQ(v.size(), std_v.size());
  EXPECT_EQ(v[1], std_v[1]);
}

TEST(VectorTest, Erase_End) {
  s21::vector<int> v = {1, 2, 3, 4};
  std::vector<int> std_v = {1, 2, 3, 4};

  v.erase(v.end() - 1);
  std_v.erase(std_v.end() - 1);

  EXPECT_EQ(v.size(), std_v.size());
  EXPECT_EQ(v[2], std_v[2]);
}

TEST(VectorTest, InsertMany) {
  s21::vector<int> vec = {1, 2, 3, 7, 8};
  s21::vector<int> correct_vec = {1, 2, 3, 4, 5, 6, 7, 8};
  s21::vector<int>::const_iterator pos = vec.cbegin() + 3;

  vec.insert_many(pos, 4, 5, 6);

  EXPECT_EQ(vec.size(), correct_vec.size());

  EXPECT_EQ(vec[0], correct_vec[0]);
  EXPECT_EQ(vec[1], correct_vec[1]);
  EXPECT_EQ(vec[2], correct_vec[2]);
  EXPECT_EQ(vec[3], correct_vec[3]);
  EXPECT_EQ(vec[4], correct_vec[4]);
  EXPECT_EQ(vec[5], correct_vec[5]);
  EXPECT_EQ(vec[6], correct_vec[6]);
  EXPECT_EQ(vec[7], correct_vec[7]);
}

TEST(VectorTest, InsertManyFront) {
  s21::vector<int> vec = {1, 2, 3};
  s21::vector<int> correct_vec = {4, 5, 6, 1, 2, 3};
  s21::vector<int>::const_iterator pos = vec.cbegin();

  vec.insert_many(pos, 4, 5, 6);

  EXPECT_EQ(vec.size(), correct_vec.size());

  EXPECT_EQ(vec[0], correct_vec[0]);
  EXPECT_EQ(vec[1], correct_vec[1]);
  EXPECT_EQ(vec[2], correct_vec[2]);
  EXPECT_EQ(vec[3], correct_vec[3]);
  EXPECT_EQ(vec[4], correct_vec[4]);
  EXPECT_EQ(vec[5], correct_vec[5]);
}

TEST(VectorTest, InsertManyBack) {
  s21::vector<int> vec = {1, 2, 3};
  s21::vector<int> correct_vec = {1, 2, 3, 4, 5, 6};

  vec.insert_many_back(4, 5, 6);

  EXPECT_EQ(vec.size(), correct_vec.size());

  EXPECT_EQ(vec[0], correct_vec[0]);
  EXPECT_EQ(vec[1], correct_vec[1]);
  EXPECT_EQ(vec[2], correct_vec[2]);
  EXPECT_EQ(vec[3], correct_vec[3]);
  EXPECT_EQ(vec[4], correct_vec[4]);
  EXPECT_EQ(vec[5], correct_vec[5]);
}
