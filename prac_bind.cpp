/***********************************************************************
#   > File Name   : prac_bind.cpp
#   > Author      : ronaldo
#   > Description : 
#   > Create Time : 2019-07-06 16:49:43
***********************************************************************/

#include <iostream>
#include <functional>

class Foo {
 public:
  Foo(int n) : n_(n) {

  }

  // 必须是public的
  void sum(int a, int b) {
    std::cout << "sum is: " << a+b+n_ << std::endl;
  }

 private:
  int n_;
};

std::function<void(int)> f2;

void set_func(const std::function<void(int)> &func) {
  f2 = func;  
}

int main(int argc, char **argv) {
  //Foo foo(5);
  {
    Foo foo(5); 
    auto f1 = std::bind(&Foo::sum, &foo, std::placeholders::_1, 10);
    f1(3);  // 18

    set_func(f1);
  }

  f2(6);  // 21

  std::function<void(int)> f3(std::move(f2));  // 使用移动构造
  f3(15);  // 30
  //f2(6);  // f2中存储的可调用对象已被f3接管，f2不能再被调用，只能安全析构

  return 0;
}
