#include<string>
using std::string;
//-------------------------------------
class MyExcept{
public:
  virtual string getWhat() = 0;
};//-----------------------------------
class MyDivideZero : public MyExcept{
public:
  string getWhat(){ return "Divide By Zero."; }
};//-----------------------------------
class MyTooLarge : public MyExcept{
public:
  string getWhat(){ return "Too Large Number."; }
};//-----------------------------------
class MyIllegal : public MyExcept{
public:
  string getWhat(){ return "Illegal Number."; }
};//-----------------------------------
