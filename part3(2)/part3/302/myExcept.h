//=====================================
// myExcept.h
//=====================================
#ifndef MYEXCEPT_HEADER
#define MYEXCEPT_HEADER
#include<iostream>
using namespace std;
//-------------------------------------
class MyExcept{
public:
  virtual string getWhat() = 0;
};//-----------------------------------
class MyFormatError : public MyExcept{
public:
  string getWhat(){ return "Format Error."; }
};//-----------------------------------
class MyIllegal : public MyExcept{
public:
  string getWhat(){ return "Illegal."; }
};//-----------------------------------
#endif  //MYEXCEPT_HEADER
 