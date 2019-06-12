//=====================================
// calculator ¹ý³Ì°æ
//=====================================
#include"myexcept.h"
#include"token.h"
#include<iostream>
#include<sstream>
#include<fstream>
#include<map>
using namespace std;
//-------------------------------------
map<string, long double> table;
long double prim(bool get,istream&);
long double term(bool get,istream&);
long double expr(bool get,istream&);
Token token;
//-------------------------------------
int main(){
  table["pi"]=3.1415926535897932385;
  table["e"]=2.7182818284590452354;
  ifstream cin("calc.txt");
  //ofstream cout("calc.out");
  cout<<fixed;
  for(string str; getline(cin, str); ){
    if( str=="") continue;
    try{
      for(istringstream sin(str); sin; ){
        long double e = expr(true,sin);
        if(token.tok!=END) throw UnexpectedToken();
        cout<<e<<"\n";
      }
    }catch(MyExcept& e){
      cout<<e.getWhat()<<"\n";
    }
  }
}//------------------------------------
long double prim(bool get,istream& in){
  if(get) token.getTok(in);
  switch(token.tok){
    long double e;
    case NUMBER:
      token.getTok(in);
      if(token.tok==NUMBER||token.tok==NAME||token.tok==LP||token.tok==ASSIGN)
        throw UnexpectedToken();
      return token.value;
    case NAME:
      token.getTok(in);
      if(token.tok==NAME||token.tok==NUMBER||token.tok==LP)
        throw UnexpectedToken();
      if(token.tok==ASSIGN){
        e = expr(true,in);
        return table[token.s] = e;
      }
      if(table.find(token.s)==table.end())
        throw UndefinedVariable();
      return table[token.s];
    case MINUS:  return -prim(true,in);
    case LP:
      e = expr(true,in);
      if(token.tok!=RP)
        throw RightParenExpected();
      token.getTok(in);
      return e;
    default:  throw PrimaryExpected();
  }
}//------------------------------------
long double term(bool get,istream& in){
  for(long double left=prim(get,in); 1; )
    switch(token.tok){
      long double d;
      case MUL:  left*=prim(true,in); break;
      case DIV:
           d = prim(true,in);
           if(d==0) throw DivideByZero();
           left/=d; break;
      default:  return left;
    }
}//------------------------------------
long double expr(bool get,istream& in){
  for(long double left = term(get,in); 1; )
    switch(token.tok){
      case PLUS:  left += term(true,in); break;
      case MINUS: left -= term(true,in); break;
      default: return left;
    }
}//------------------------------------


