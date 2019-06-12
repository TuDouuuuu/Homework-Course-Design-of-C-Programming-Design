//=====================================
// calculator ¹ý³Ì°æ
//=====================================
#include"myexcept.h"
#include<iostream>
#include<sstream>
#include<fstream>
#include<map>
using namespace std;
//-------------------------------------
map<string, long double> table;
class Token{
public:
  enum Tok{NAME,NUMBER,END,PLUS='+',MINUS='-',MUL='*',DIV='/',ASSIGN='=',LEFTP='(',RIGHTP=')'};
  Tok tok;
  long double value;
  string s;
  Tok Token::getTok(istream& in){
    char ch;
    while(in.get(ch) && ch==' ');
    if(!in){ return tok=END; }
    switch(ch){
      case MUL: case DIV: case PLUS: case MINUS:
      case LEFTP: case RIGHTP: case ASSIGN:
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
  }
}token;//-----------------------------
long double prim(bool get,istream&);
long double term(bool get,istream&);
long double expr(bool get,istream&);
//-------------------------------------
int main(){
  table[string("pi")]=3.1415926535897932385;
  table[string("e")]=2.7182818284590452354;
  ifstream cin("calcf.txt");
  //ofstream cout("calcf.out");
  cout<<fixed<<scientific;
  for(string str; getline(cin, str); )
    try{
      for(istringstream sin(str); sin; ){
        if( token.getTok(sin)==Token::END) break;
        long double e = expr(false,sin);
        if(token.tok!=Token::END) throw PrimaryExpected();
        cout<<e<<"\n";
      }
    }catch(MyExcept& e){
      cout<<e.getWhat()<<"\n";
    }
}//------------------------------------
long double prim(bool get,istream& in){
  if(get) token.getTok(in);
  switch(token.tok){
    long double e;
    case Token::NUMBER:
      token.getTok(in);
      if(token.tok==Token::NUMBER||token.tok==Token::NAME||token.tok==Token::LEFTP||token.tok==Token::ASSIGN)
        throw UnexpectedToken();
      return token.value;
    case Token::NAME:
      token.getTok(in);
      if(token.tok==Token::NAME||token.tok==Token::NUMBER||token.tok==Token::LEFTP)
        throw UnexpectedToken();
      if(token.tok==Token::ASSIGN){
        e = expr(true,in);
        return table[token.s] = e;
      }
      if(table.find(token.s)==table.end())
        throw UndefinedVarible();
      return table[token.s];
    case Token::MINUS:  return -prim(true,in);
    case Token::LEFTP:
      e = expr(true,in);
      if(token.tok!=Token::RIGHTP)
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
      case Token::MUL:  left*=prim(true,in); break;
      case Token::DIV:
           d = prim(true,in);
           if(d==0) throw DivideByZero();
           left/=d; break;
      default:  return left;
    }
}//------------------------------------
long double expr(bool get,istream& in){
  for(long double left = term(get,in); 1; )
    switch(token.tok){
      case Token::PLUS:  left += term(true,in); break;
      case Token::MINUS: left -= term(true,in); break;
      default: return left;
    }
}//------------------------------------


