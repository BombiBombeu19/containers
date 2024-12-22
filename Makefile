CC = g++
CFLAGS = -Wall -Werror -Wextra -std=c++17 
TEST_FLAGS = -lgtest -pthread
TEST_TARGET = tests

all: clean test

clean:
	@echo "Deleting unnecessary files...🤖"
	@rm -rf *.o *.a *.out *.log test

test: clean
	@echo "Testing...🤖"
	@$(CC) $(CFLAGS) $(TEST_TARGET)/*.cpp $(TEST_FLAGS) -o test
	@./test

leaks: test
	@echo "Checking for memory leaks...🤖"
	@leaks -atExit -- ./test

clang:
	@echo "Setting Google style...🤖"
	@clang-format -i $(TEST_TARGET)/*.cpp $(TEST_TARGET)/*.cpp $(TEST_TARGET)/*.h s21_containers/*.tpp s21_containers/*.h s21_containers_extra/*.tpp s21_containers_extra/*.h s21_binary_tree/*.h -style=Google

clang_check:
	@echo "Cheking code style...🤖"
	@clang-format -n $(TEST_TARGET)/*.cpp $(TEST_TARGET)/*.cpp $(TEST_TARGET)/*.h s21_containers/*.tpp s21_containers/*.h s21_containers_extra/*.tpp s21_containers_extra/*.h s21_binary_tree/*.h -style=Google

.PHONY: all test clean clang clang_check leaks