//=====================================
// token.cpp
//=====================================
#include"token.h"
#include"myexcept.h"
//-------------------------------------
Tok Token::getTok(istream& in){
  char ch;
  while(in.get(ch) && ch==' ');
  if(!in){ return tok=END; }
  switch(ch){
    case MUL: case DIV: case PLUS: case MINUS:
    case LP: case RP: case ASSIGN:
      return tok=Tok(ch);
    case '0': case '1': case '2': case '3': case '4': case '5':
    case '6': case '7': case '8': case '9': case '.':
      in.putback(ch);
      in>>value;
      return tok=NUMBER;
    default:
      if(!isalpha(ch)) throw BadToken();
      s = ch;
      for(int i=2; in.get(ch) && isalnum(ch); s+=ch, i++)
        if(i>20) throw TooLongOfNameLength();
      in.putback(ch);
      return tok=NAME;
  }
}//------------------------------------
 