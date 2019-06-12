// calculator
#include<iostream>
#include<sstream>
// #include<fstream>
// #include<cctype>
#include<map>
using namespace std;

enum Token_value{
  NAME, NUMBER, END, PLUS='+', MINUS='-', MUL='*',
  DIV='/', PRINT=';', ASSIGN='=', LP='(', RP=')', RETURN='\n'};
istream* input;
int no_of_errors;
Token_value curr_tok=PRINT;
double number_value;
string string_value;
map<string, double> table;

double prim(bool get);
double term(bool get);
double expr(bool get);
double error(const string& s);
Token_value get_token();

#pragma argsused
int main(int argc, char* argv[])
{
  if(argc==1)  // deal with argc
    input=&cin;
  else if(argc==2)
    input=new istringstream(argv[1]);
  else{
    error("too many arguments");
    return 1;
  }
  table["pi"]=3.1415926535897932385;
  table["e"]=2.7182818284590452354;

  while(*input){
    get_token();
    if(curr_tok==END) break;
    if(curr_tok==PRINT) continue;
    cout<<expr(false)<<endl;
  }
  if(input!=&cin) delete input;
  return no_of_errors;
}

double prim(bool get)
{
  if(get) get_token();

  switch(curr_tok){
  case NUMBER:{
       double v=number_value;
       get_token();
       return v;
  }
  case NAME:{
       double& v=table[string_value];
       if(get_token()==ASSIGN) v=expr(true);
       return v;
  }
  case MINUS:
       return -prim(true);
  case LP:{
       double e=expr(true);
       if(curr_tok!=RP) return error(") expected");
       get_token();
       return e;
  }
  default:
       return error("primary expected");
  }
}

double term(bool get)
{
  double left=prim(get);

  for(;;)
    switch(curr_tok){
    case MUL:
         left*=prim(true);
         break;
    case DIV:
         if(double d=prim(true)){
           left/=d;
           break;
         }
        return error("divide by 0");
    default:
        return left;
    }
}

double expr(bool get)
{
  double left=term(get);

  for(;;)
    switch(curr_tok){
    case PLUS:
         left+=term(true);
         break;
    case MINUS:
         left-=term(true);
         break;
    default:
         return left;
  }
}

double error(const string& s)
{
  no_of_errors++;
  cerr<<"error: "<< s <<endl;
  return 1;
}

// version 2
Token_value get_token()
{
  char ch;
  do{
    if(!cin.get(ch)) return curr_tok=END;
  }while(ch!='\n' && isspace(ch));

  switch(ch){
  case RETURN:
       return curr_tok=PRINT;
  case PRINT: case MUL: case DIV: case PLUS: case MINUS:
  case LP: case RP: case ASSIGN:
       return curr_tok=Token_value(ch);
  case '0': case '1': case '2': case '3': case '4': case '5':
  case '6': case '7': case '8': case '9': case '.':
       cin.putback(ch);
       cin>>number_value;
       return curr_tok=NUMBER;
  default:
       if(isalpha(ch)){
         string_value=ch;
         while(cin.get(ch) && isalnum(ch)) string_value.push_back(ch);
         cin.putback(ch);
         return curr_tok=NAME;
       }
       error("bad token");
       return curr_tok=PRINT;
  }
}

