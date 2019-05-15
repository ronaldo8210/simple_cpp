/***********************************************************************
#   > File Name   : prac_move.cpp
#   > Author      : ronaldo
#   > Description : 
#   > Create Time : 2019-05-09 08:40:20
***********************************************************************/

#include <iostream>
#include <string>
#include <vector>

int main(int argc, char** argv) {
  std::string str("hello");
  std::string str_move("hello_move");
  std::vector<std::string> vec;
  vec.push_back(str);
  vec.push_back(std::move(str_move));
  std::cout << vec[0] << ", " << vec[1] << std::endl;
  std::cout << str << std::endl;
  std::cout << str_move << std::endl;

  return 0;
}
