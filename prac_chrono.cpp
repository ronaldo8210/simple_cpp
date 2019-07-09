/***********************************************************************
#   > File Name   : prac_chrono.cpp
#   > Author      : ronaldo
#   > Description : 
#   > Create Time : 2019-07-01 16:16:27
***********************************************************************/

#include <chrono>
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
  chrono::minutes t1(10);
  chrono::seconds t2(60);
  chrono::seconds t3 = t1 - t2;
  cout << t3.count() << " seconds" << endl;
  cout << chrono::duration_cast<chrono::minutes>(t3).count() << " minutes" << endl;

  cout << "---------" << endl;

  chrono::steady_clock::time_point t4 = chrono::steady_clock::now();
  cout << "hello world" << endl;
  chrono::steady_clock::time_point t5 = chrono::steady_clock::now();
  cout << (t5-t4).count() << " tick count" << endl;
  cout << chrono::duration_cast<chrono::microseconds>(t5-t4).count() << " microseconds" << endl;

  cout << "---------" << endl;

  typedef chrono::duration<int, ratio<24*60*60>> days_type;
  chrono::time_point<chrono::system_clock, days_type> today = 
      chrono::time_point_cast<days_type>(chrono::system_clock::now());
  cout << today.time_since_epoch().count() << " days since epoch" << endl;

  return 0;
}
