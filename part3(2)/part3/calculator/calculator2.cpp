//=====================================
// calculator ¹ý³Ì°æ
//=====================================
#include<iostream>
#include<sstream>
#include<fstream>
#include<cctype>
#include<map>
using namespace std;
//-------------------------------------
enum Token{
  NAME, NUMBER, END, PLUS='+', MINUS='-', MUL='*',
  DIV='/', MOD='%', PRINT=';', ASSIGN='=', LP='(', RP=')', RETURN='\n'};
  //-----------------------------------
istream* input;
int errorNum;
Token curTok=PRINT;
double value;
string s;
map<string, double> table;
//-------------------------------------
double prim(bool get);
double term(bool get);
double expr(bool get);
double error(const string& s);
Token getTok();
//-------------------------------------
int main(){
  table["pi"]=3.1415926535897932385;
  table["e"]=2.7182818284590452354;
  for(string str; getline(cin, str); ){
    for(input = new istringstream(str); *input; ){
      getTok();
      if(curTok==END) break;
      if(curTok==PRINT) continue;
      cout<<expr(false)<<"\n";
    }
    delete input;
    return errorNum;
  }
}//------------------------------------
double prim(bool get){
  if(get) getTok();
  switch(curTok){
    case NUMBER:{
       double v=value;
       getTok();
       return v;
    }case NAME:{
       double& v=table[s];
       if(getTok()==ASSIGN ) v=expr(true);
       return v;
    }case MINUS:
       return -prim(true);
    case LP:{
       double e=expr(true);
       if(curTok!=RP) return error(") expected");
       getTok();
       return e;
    }default:
       return error("primary expected");
  }
}//------------------------------------
double term(bool get){
  double left=prim(get);
  for(;;)
    switch(curTok){
    case MUL:
         left*=prim(true);
         break;
    case DIV:{
         double d=prim(true);
         if(!d) return error("divide by 0");
         left/=d;
         break;
    }default:
         return left;
    }
}//------------------------------------
double expr(bool get){
  double left=term(get);
  for(;;)
    switch(curTok){
    case PLUS:
         left+=term(true);
         break;
    case MINUS:
         left-=term(true);
         break;
    default:
         return left;
  }
}//------------------------------------
double error(const string& s){
  errorNum++;
  cerr<<"error: "+s+"\n";
  return 1;
}//------------------------------------
Token getTok(){
  char ch;
  do{
    if(!cin.get(ch)) return curTok=END;
  }while(ch!='\n' && isspace(ch));

  switch(ch){
  case RETURN:
       return curTok=PRINT;
  case PRINT: case MUL: case DIV: case PLUS: case MINUS:
  case LP: case RP: case ASSIGN:
       return curTok=Token(ch);
  case '0': case '1': case '2': case '3': case '4': case '5':
  case '6': case '7': case '8': case '9': case '.':
       cin.putback(ch);
       cin>>value;
       return curTok=NUMBER;
  default:
       if(isalpha(ch)){
         s=ch;
         while(cin.get(ch) && isalnum(ch)) s+=ch;
         cin.putback(ch);
         return curTok=NAME;
       }
       error("bad token");
       return curTok=PRINT;
  }
}//------------------------------------

