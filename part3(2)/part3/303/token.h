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
  Tok tok;
  long double value;
  string s;
  Tok getTok(istream& in);
};//-----------------------------------
#endif  // TOKEN_HEADER

 