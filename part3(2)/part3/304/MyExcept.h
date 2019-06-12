//=====================================
// MyExcept.h for calculator
//=====================================
#ifndef MYEXCEPT_HEADER
#define MYEXCEPT_HEADER
class MyExcept{
public:
  virtual char* getWhat()=0;
};//-----------------------------------
class DivideByZero : public MyExcept{
public:
  char* getWhat(){ return "Divide By Zero"; }
};//-----------------------------------
//class LeftParenExpected : public MyExcept{
//public:
//  char* getWhat(){ return "Left Parentheses Expected"; }
//};//-----------------------------------
class RightParenExpected : public MyExcept{
public:
  char* getWhat(){ return "Right Parentheses Expected"; }
};//-----------------------------------
class PrimaryExpected : public MyExcept{
public:
  char* getWhat(){ return "Primary Expected"; }
};//-----------------------------------
class BadToken : public MyExcept{
public:
  char* getWhat(){ return "Bad Token"; }
};//-----------------------------------
class UnexpectedToken : public MyExcept{
public:
  char* getWhat(){ return "Unexpected Token"; }
};//-----------------------------------
class TooLongOfNameLength : public MyExcept{
public:
  char* getWhat(){ return "Too Long of Name Length"; }
};//-----------------------------------
class UndefinedVariable : public MyExcept{
public:
  char* getWhat(){ return "Undefined Variable"; }
};//-----------------------------------
#endif  // MYEXCEPT_HEADER
