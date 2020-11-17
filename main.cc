//
// Created by shawnunili on 2019/3/2.
//
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include "concurent/ability.h"

using namespace std;
using namespace xct;

int main(int argc, char *argv[]) {
  printf("%#X\n", 0); // 0
  printf("%#X\n", -1); // 0XFFFFFFFF
  printf("%#X\n", -2147483647); // 0X80000001
  printf("%#X\n", INT32_MIN);  // 0X80000000
  printf("%#X\n", 2147483647); // 0X7FFFFFFF
  printf("%#X\n", INT32_MAX);  // 0X7FFFFFFF
  return 0;
}