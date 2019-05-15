/***********************************************************************
#   > File Name   : prac_atomic.cpp
#   > Author      : ronaldo
#   > Description : 
#   > Create Time : 2019-04-23 22:12:18
***********************************************************************/

#include <atomic>
#include <iostream>
#include <thread>
#include <vector>

using namespace std;

atomic_flag g_flag = ATOMIC_FLAG_INIT;
atomic<bool> g_ready(false);

void func(int id) {
  while (!g_ready) {
    this_thread::yield();
  }

  for (volatile int i = 0; i < 100000; i++) {
    // do nothing
  }

  if (!g_flag.test_and_set()) {
    cout << "thread " + to_string(id) + " win!!" << endl;
  }
}

int main(int argc, char** argv) {
  vector<thread> thrd_vec;
  for (int i = 0; i < 10; i++) {
    thrd_vec.push_back(thread(func, i));
  }
  g_ready = true;

  for (auto& thrd : thrd_vec) {
    thrd.join();
  }

  return 0;
}
