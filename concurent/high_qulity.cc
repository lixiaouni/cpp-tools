//
// Created by shawnunili on 2020/11/8.
//
#include "high_quality.h"
#include <cmath>
#include <exception>
#include <cstring>
#include <cstdio>

namespace xct {

double Power(double base, int exponent) {
  if (!std::isless(base, 0.0) && !std::isgreater(base, 0.0) && exponent < 0) {
	throw std::exception();
  }
  double result;
  int ex = exponent;
  if (exponent < 0) {
	ex = -exponent;
  }
  result = PowerWithUnsignedExponent(base, -exponent);
  if (exponent < 0) {
    result = 1 / result;
  }
  return result;
}

double PowerWithUnsignedExponent(double base, unsigned int exponent) {
//  double result = 1.0;
//  while (exponent > 0) {
//	result *= base;
//	--exponent;
//  }
//  return result;
  if (exponent == 0) {
    return 1;
  }
  if (exponent == 1) {
    return base;
  }
  double result;
  result = PowerWithUnsignedExponent(base, exponent >> 1);
  result *= result;
  if (exponent & 0x1 == 1) {
    result *= base;
  }
  return result;
}

void Print1ToMaxOfNDigits::Print(int n) {
  if (n < 1) {
	return;
  }
  char* num = new char[n+1];
  std::memset(num, '0', n);
  num[n] = '\0';
  while (Increment(num)) {
    PrintNum(num);
  }
  delete [] num;
}

bool Print1ToMaxOfNDigits::Increment(char* num) {
  auto len = std::strlen(num);
  int value = num[len-1] - '0';
  bool is_flow = false;
  int carry = 0;
  if (value < 9) {
    num[len-1] = value + 1 + '0';
    return true;
  } else {
    carry = 1;
	num[len-1] = '0';
	int i = len - 2;
	for (; i >= 0; --i) {
	  int value = num[i] - '0';
	  if (value + carry <= 9) {
		num[len-2] = value + carry + '0';
	    return true;
	  } else {
		num[len-2] = '0';
		carry = 1;
	  }
	}
	if (i == 0 && carry == 1) {
	  return false;
	}
  }
}

void Print1ToMaxOfNDigits::PrintNum(char* num) {
  bool is_first_0 = true;
  for (int i = 0; i < std::strlen(num); ++i) {
    if (is_first_0 && num[i] != '0') {
      is_first_0 = false;
    }
    if (!is_first_0) {
      std::printf("%c", num[i]);
    }
  }
  std::printf("\n");
}

void Print1ToMaxOfNDigits::Test() {
  Print(2);
}

}
