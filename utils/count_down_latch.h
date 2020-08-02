//
// Created by shawnunili on 2019/6/25.
//

#ifndef CPP_TOOLS_COUNTDOWNLATCH_H
#define CPP_TOOLS_COUNTDOWNLATCH_H

#include <mutex>
#include <condition_variable>
#include <iostream>

namespace xct {
class CountDownLatch {
 public:
  explicit CountDownLatch(int count) : m_count(count),
									   m_mutex() {}

  void wait() {
	std::unique_lock<std::mutex> locker(m_mutex);
	while (m_count > 0) {
	  m_cond.wait(locker);
	}
  }

  void countDown() {
	std::unique_lock<std::mutex> locker(m_mutex);
	--m_count;
	// std::cout << "CountDownLatch::m_count:" << m_count << std::endl;
	if (m_count == 0) {
	  m_cond.notify_all();
	}
  }

 private:
  CountDownLatch() = delete;

  CountDownLatch(const CountDownLatch &other) = delete;

  CountDownLatch &operator=(const CountDownLatch &opther) = delete;

 private:
  std::mutex m_mutex;
  std::condition_variable m_cond;
  int m_count;
};
}

#endif  // CPP_TOOLS_COUNTDOWNLATCH_H
