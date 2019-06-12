//=====================================
// token.h
//=====================================
#ifndef TOKEN_HEADER
#define TOKEN_HEADER
#include<iostream>
using namespace std;
//-------------------------------------
enum Tok{NAME,NUMBER,END,PLUS='+',MINUS='-',MUL='*',DIV='/',ASSIGN='=',LP='(',RP=')'};
//-------------------------------------
class Token{
public:
  Token():_tok(END){}
  Tok _tok;
  long double _value;
  string _s;
};//-----------------------------------
#endif  // TOKEN_HEADER

 