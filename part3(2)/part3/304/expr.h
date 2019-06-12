//=====================================
// Expr.h
//=====================================
#ifndef EXPRESSION_HEADER
#define EXPRESSION_HEADER
#include"program.h"
#include"token.h"
#include<map>
#include<iostream>
using namespace std;
//-------------------------------------
class Expression{
public:
  Expression(istream& in):_in(in){}
  istream& _in;
  Token token;
  static map<string, long double> nameTable;
  Tok readTok();
  long double expr(bool);
  long double term(bool);
  long double prim(bool);
};//-----------------------------------
#endif  // EXPRESSION_HEADER

 