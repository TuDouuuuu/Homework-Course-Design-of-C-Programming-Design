//=====================================
// Expression.cpp
//=====================================
#include"expr.h"
#include"myexcept.h"
//-------------------------------------
map<string, long double> Expression::nameTable;
//-------------------------------------
long double Expression::expr(bool get){
  for(long double left = term(get); ; )
    switch(token._tok){
      case PLUS:  left += term(true); break;
      case MINUS: left -= term(true); break;
      default: return left;
    }
}//------------------------------------
long double Expression::term(bool get){
  for(long double left=prim(get), d; ; )
    switch(token._tok){
      case MUL:  left*=prim(true); break;
      case DIV:
           d = prim(true);
           if(d==0) throw DivideByZero();
           left/=d; break;
      default:  return left;
    }
}//------------------------------------
long double Expression::prim(bool get){
  if(get) readTok();
  switch(token._tok){
    long double e;
    case NUMBER:
      readTok();
      if(token._tok==NUMBER||token._tok==NAME||token._tok==LP||token._tok==ASSIGN)
        throw UnexpectedToken();
      return token._value;
    case NAME:
      readTok();
      if(token._tok==NAME||token._tok==NUMBER||token._tok==LP)
        throw UnexpectedToken();
      if(token._tok==ASSIGN){
        e = expr(true);
        return nameTable[token._s] = e;
      }
      if(nameTable.find(token._s)==nameTable.end())
        throw UndefinedVariable();
      return nameTable[token._s];
    case MINUS:  return -prim(true);
    case LP:
      e = expr(true);
      if(token._tok!=RP)
        throw RightParenExpected();
      readTok();
      return e;
    default:  throw PrimaryExpected();
  }
}//------------------------------------
Tok Expression::readTok(){
  char ch;
  while(_in.get(ch) && ch==' ');
  if(!_in){ return token._tok=END; }
  switch(ch){
    case MUL: case DIV: case PLUS: case MINUS:
    case LP: case RP: case ASSIGN:
      return token._tok=Tok(ch);
    case '0': case '1': case '2': case '3': case '4': case '5':
    case '6': case '7': case '8': case '9': case '.':
      _in.putback(ch);
      _in>>token._value;
      return token._tok=NUMBER;
    default:
      if(!isalpha(ch)) throw BadToken();
      token._s = ch;
      for(int i=2; _in.get(ch) && isalnum(ch); token._s+=ch, i++)
        if(i>20) throw TooLongOfNameLength();
      _in.putback(ch);
      return token._tok=NAME;
  }
}//------------------------------------



 