//
// Created by shawnunili on 2020/7/27.
//
#pragma once

#include "test_base.h"
#include "common.h"

namespace xct {
// question 3
class SearchIn2DimArray : public TestBase {
 public:
  virtual void Test() override;
  // 注意多维数组的表示方式 cpp primer page101
  bool Find(int *matrix, int rows, int cols, int target);
};

// question 4
class ReplaceBlank : public TestBase {
 public:
  virtual void Test() override;
  //  在原数组替换, length 是原数组长度
  void Replace(char string[], int length);
};

// question 5
class PrintListFromHead : public TestBase {
 public:
  virtual void Test() override;

  void PrintList(ListNode *head);

  void PrintListRecursive(ListNode *head);
};

}