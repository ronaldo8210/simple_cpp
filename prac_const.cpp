/***********************************************************************
#   > File Name   : prac_const.cpp
#   > Author      : ronaldo
#   > Description : 
#   > Create Time : 2019-04-13 16:25:45
***********************************************************************/

#include <iostream>

using namespace std;

class A {
 public:
  A() : a(1) {}

  const int get() {
    a = 2;
    return a;
  }

  const int& get_2() {  // ?
    a = 3;
    return a;
  }

  int get_3() const {
    // a = 4;  // compile error!! 
    return a;
  }
 private:
  int a;
};

int main(int argc, char** argv) {
    A a;

    int b = a.get();
    b = 5;
    cout << b << endl;

    int c = a.get_2();
    c = 6;  // ?
    cout << c << endl;

    cout << a.get_3() << endl;

    return 0;
}
