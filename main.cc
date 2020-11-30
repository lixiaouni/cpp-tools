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
  std::string str(1000, 'a');
  cout << sizeof(str) << endl;
  str = "lllllll";
  cout << sizeof(str) << endl;
  
  return 0;
}