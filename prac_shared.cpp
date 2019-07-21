/***********************************************************************
#   > File Name   : prac_shared.cpp
#   > Author      : ronaldo
#   > Description : 
#   > Create Time : 2019-07-20 18:32:23
***********************************************************************/

#include <memory>
#include <iostream>

class Foo : public std::enable_shared_from_this<Foo> {
 public:
  Foo(int n) : n_(n) {

  }

  ~Foo() {
    std::cout << "destructor" << std::endl;
  }

  
  std::shared_ptr<Foo> func() {
    return shared_from_this();
  }

  int n() {
    return n_;
  }

 private:
  int n_ = 5;
};

int main(int argc, char **argv) {
  static std::shared_ptr<Foo> st_p;

  {
    std::shared_ptr<Foo> p = std::make_shared<Foo>(5);
    st_p = p->func();
  }

  std::cout << st_p->n() << std::endl; 

  return 0;
}
