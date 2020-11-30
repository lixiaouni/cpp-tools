// Created by shawnunili on 2020/7/30.
#ifndef CPP_TOOLS_TEST_EMPLACE_TEST_H_
#define CPP_TOOLS_TEST_EMPLACE_TEST_H_

#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>

class A {
 public:
  A(int i) {
	str_ = to_string(i);
	std::cout << "restruct" << std::endl;
  }
  A(const A &rhs) : str_(rhs.str_) {
	std::cout << "copy restruct" << std::endl;
  }
  std::string GetContent() const {
	return str_;
  }
 private:
  std::string str_;
};

class EmplaceTest {
  static void Test() {
	std::vector<A> list_a;
	A a(9);
	std::cout << "------push_back--------" << std::endl;
	list_a.push_back(a);
	std::cout << "------emplace_back--------" << std::endl;
	list_a.emplace_back(a);
	std::cout << "--------emplace_back------" << std::endl;
	list_a.emplace_back(a);
	std::cout << "--------------" << std::endl;
	std::cout << "list_a.size:" << list_a.size() << std::endl;
	std::cout << "--------------" << std::endl;
	std::cout << a.GetContent() << std::endl;
	std::cout << "--------------" << std::endl;
	for (const auto &ele : list_a) {
	  std::cout << ele.GetContent() << std::endl;
	}

	printf("%#X\n", 0); // 0
	printf("%#X\n", -1); // 0XFFFFFFFF
	printf("%#X\n", -2147483647); // 0X80000001
	printf("%#X\n", INT32_MIN);  // 0X80000000
	printf("%#X\n", 2147483647); // 0X7FFFFFFF
	printf("%#X\n", INT32_MAX);  // 0X7FFFFFFF
  }
};

#endif //CPP_TOOLS_TEST_EMPLACE_TEST_H_
