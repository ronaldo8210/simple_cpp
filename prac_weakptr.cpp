/***********************************************************************
#   > File Name   : prac_weakptr.cpp
#   > Author      : ronaldo
#   > Description : 
#   > Create Time : 2019-07-21 13:31:35
***********************************************************************/

#include <iostream>
#include <memory>

class Foo {
 public:
  Foo(int n) : n_(n) {

  }

  ~Foo() {
    std::cout << "destructor" << std::endl;
  }

 private:
  int n_;
};

int main(int argc, char **argv) {
  std::shared_ptr<Foo> sp(new Foo(5));
  std::weak_ptr<Foo> wp(sp);

  {
    std::shared_ptr<Foo> sp = wp.lock();
    std::cout << wp.use_count() << std::endl;
  }

  return 0;
}
