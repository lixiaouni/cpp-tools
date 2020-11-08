//
// Created by shawnunili on 2020/11/8.
//
#pragma once

#include "test_base.h"

namespace xct {

// question 11
double Power(double base, int exponent);

double PowerWithUnsignedExponent(double base, unsigned int exponent);

// question 12
class Print1ToMaxOfNDigits : public TestBase {
 public:
  virtual void Test() override;

  void Print(int n);

  bool Increment(char* num);

  void PrintNum(char* num);
};


}