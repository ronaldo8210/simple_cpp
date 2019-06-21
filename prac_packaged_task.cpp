/***********************************************************************
#   > File Name   : prac_packaged_task.cpp
#   > Author      : ronaldo
#   > Description : 
#   > Create Time : 2019-06-19 21:36:09
***********************************************************************/

#include <chrono>
#include <future>
#include <iostream>
#include <thread>

using namespace std;

int func(int from, int to) {
  int ret = 0;
  for (int i = from; i <= to; ++i) {
    cout << i << endl;
    ret += i;
    this_thread::sleep_for(chrono::seconds(1));
  }

  cout << "func complete!!" << endl;

  return ret;
}

int main(int argc, char **argv) {
  // task实例中包含可调用对象的一份副本
  // 创建task实例时调用普通构造函数，要求可调用对象是可拷贝的
  packaged_task<int(int, int)> task(func);

  future<int> ret = task.get_future();

  // packaged_task实例不可拷贝，只可移动，worker线程中的task实例接管主线程中的task实例的资源
  // 主线程中的移后源task实例不可再被调用，但可保证被安全析构
  thread thrd(std::move(task), 1, 10);

  cout << "task result: " << ret.get() << endl;

  // 释放线程拥有的资源
  thrd.join();

  // 移后源对象task在这里被正常析构

  return 0;
}
