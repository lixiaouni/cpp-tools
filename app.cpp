//
// Created by shawnunili on 2019/3/2.
//
#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <map>
#include <sstream>
#include "utils/CountDownLatch.h"
#include "utils/ThreadPool.h"
#include "third-party/rapidjson/document.h"
#include <thread>
// #include <sys/stat.h>
#include "utils/vector_cal.h"
// #include <priority_queue>
#include <queue>
#include "utils/MinHeap.h"
#include "utils/MultiWaysMergeTopK.h"
#include <ctime>

using namespace std;
using namespace xct;

void getBigestk(pair<float, string> value, map<float, string> &result, int k) {
  if (result.size() < k) {
	result.insert(value);
  } else {
	auto itSmall = result.begin();
	if (itSmall->first < value.first) {
	  result.erase(itSmall);
	  result.insert(value);
	}
  }
}

void test() {
  vector<pair<float, string>> data;
  map<float, string> result;
  for (int i = 0; i < 100; i++) {
	ostringstream os;
	os << i;
	data.push_back(make_pair(i, os.str()));
  }
  for (const auto &ele : data) {
	cout << ele.first << ": " << ele.second << endl;
	getBigestk(ele, result, 3);
  }
  cout << "------------" << endl;
  for (const auto &ele : result) {
	cout << ele.first << ": " << ele.second << endl;
  }
}

void fun(shared_ptr<CountDownLatch> countPtr, int cnt) {
  countPtr->countDown();
}

void countDownTest() {
  shared_ptr<CountDownLatch> countPtr = make_shared<CountDownLatch>(17);
  ThreadPool threadPool(10, 1000);
  for (int i = 0; i < 17; ++i) {
	threadPool.AddTask(std::bind(&fun, countPtr, i));
  }
  countPtr->wait();
  cout << "wait end!" << endl;
}

class Parent {
 public:
  void work() {
	response();
  }

 protected:
  virtual void response() {
	cout << "paretn response!" << endl;
  }
};

class BB : public Parent {
  void response() override {
	cout << "BB response!" << endl;
  }
};

class CC : public BB {
//    void response() override {
//        cout << "CC response!" << endl;
//    }
};

struct CONST_Test {
  const int AGE = 9;
};

void Split(const std::string &str, const std::string &sep, bool flag, std::vector<std::string> &result) {
  int pos1, pos2;
  int len = sep.length();
  pos1 = 0;
  pos2 = str.find(sep);
  while (pos2 != std::string::npos) {
	const auto &ele = str.substr(pos1, pos2 - pos1);
	if (!ele.empty()) {
	  result.emplace_back(ele);
	} else if (flag) {
	  result.emplace_back(ele);
	}
	pos1 = pos2 + len;
	pos2 = str.find(sep, pos1);
  }
  std::string ele;
  if(pos1 < str.length()) {
	ele = str.substr(pos1);
  }
  if (!ele.empty()) {
	result.emplace_back(ele);
  } else if (flag) {
	result.emplace_back(ele);
  }
}
// 此特殊版本是对于\sep这种格式的不算分隔符
void SplitWithEscape(const std::string &str, const std::string &sep, bool flag, std::vector<std::string> &result) {
  int pos1, pos2;
  int len = sep.length();
  pos1 = 0;
  pos2 = str.find(sep);
  while (pos2 != std::string::npos) {
    if (pos2 == 0 || (pos2 > 0 && str[pos2-1] != '\\')) {
	  const auto &ele = str.substr(pos1, pos2 - pos1);
	  if (!ele.empty()) {
		result.emplace_back(ele);
	  } else if (flag) {
		result.emplace_back(ele);
	  }
	  pos1 = pos2 + len;
	  pos2 = str.find(sep, pos1);
    } else {
      // 找到的是转义的
	  pos2 += len;
	  pos2 = str.find(sep, pos2);
    }
  }
  std::string ele;
  if(pos1 < str.length()) {
	ele = str.substr(pos1);
  }
  if (!ele.empty()) {
	result.emplace_back(ele);
  } else if (flag) {
	result.emplace_back(ele);
  }
}


int main(int argc, char *argv[]) {
  std::string test("|f|5|\\|\\|a\\|b|\\|\\|5|6|");
  cout << test << endl;
  std::vector<std::string> result;
  SplitWithEscape(test, "|", true, result);
  for (const auto ele : result) {
	std::cout << "ele:" << ele << std::endl;
  }
  return 0;
}