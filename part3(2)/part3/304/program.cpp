//=====================================
// program.cpp ¹ý³Ì°æ
//=====================================
#include"program.h"
#include"myexcept.h"
#include"expr.h"
#include<sstream>
using namespace std;
//-------------------------------------
void Program::run(){
  Expression::nameTable["pi"]=3.1415926535897932385;
  Expression::nameTable["e"]=2.7182818284590452354;
  _out<<fixed;
  for(string str; getline(_in, str); )
  {
    if(str=="") continue;
    istringstream in(str);
    Expression e(in);
    try{
      long double d = e.expr(true);
      if(e.token._tok!=END) throw UnexpectedToken();
      _out<<d<<"\n";
    }catch(MyExcept& e){
      _out<<e.getWhat()<<"\n";
    }
  }
}//------------------------------------

