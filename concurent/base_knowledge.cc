//
// Created by shawnunili on 2020/7/27.
#include "base_knowledge.h"
#include <iostream>
#include <stack>
namespace xct {
// question3
bool SearchIn2DimArray::Find(int *matrix, int rows, int cols, int target) {
  if (matrix == nullptr || rows <= 0 || cols <= 0) {
	return false;
  }
  int i = 0;
  int j = cols - 1;
  while (i < rows && j >= 0) {
	int number = matrix[i * cols + j];
	if (number == target) {
	  return true;
	} else if (number < target) {
	  ++i;
	} else {
	  --j;
	}
  }
  return false;
}

void SearchIn2DimArray::Test() {
  // 多维数组在内存上是连续的
  int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
  bool ret = Find((int *)matrix, 4, 4, 7);
  std::cout << "SearchIn2DimArray::Test(): ret:" << ret << std::endl;
}
// question4
void ReplaceBlank::Replace(char *str, int length) {
  if (str == nullptr || length <= 0) {
	return;
  }
  size_t blank_size = 0;
  size_t str_length = 0;

  for (size_t i = 0; str[i] != '\0'; ++i) {
	++str_length;
	if (str[i] == ' ') {
	  ++blank_size;
	}
  }
  if ((str_length + blank_size * 2 + 1) > length) {
	return;
  }

  size_t i = str_length;
  size_t j = str_length + blank_size * 2;
  while (i >= 0 && j > i) {
	if (str[i] != ' ') {
	  str[j--] = str[i--];
	} else {
	  str[j--] = '0';
	  str[j--] = '2';
	  str[j--] = '%';
	  --i;
	}
  }
}

void ReplaceBlank::Test() {

}

// question5
void PrintListFromHead::PrintList(ListNode *head) {
  if (head == nullptr) {
	return;
  }
  std::stack<int> stack;
  while (head != nullptr) {
    stack.push(head->value);
    head = head->next;
  }
  while (!stack.empty()) {
    std::cout << stack.top() << std::endl;
    stack.pop();
  }
}

void PrintListFromHead::PrintListRecursive(ListNode *head) {
  if (head == nullptr) {
	return;
  }
  PrintListRecursive(head->next);
  std::cout << head->value << std::endl;
}

void PrintListFromHead::Test() {

}

}
