//=====================================
// 大整数加、减、乘、整除、取余
//=====================================
#include"strint.h"
#include"myexcept.h"
#include<fstream>
#include<iostream>
using namespace std;
//-------------------------------------
int main(){
  //ifstream cin("b.txt");
  StrInt a,b;
  for(char ch; cin>>ch && ch!='@'; ){
    try{
      cin>>a>>b;
      switch(ch){
        case'-': cout<<sub(a,b)<<"\n"; break;
        case'+': cout<<add(a,b)<<"\n"; break;
        case'*': cout<<mul(a,b)<<"\n"; break;
        case'/': cout<<div(a,b)<<"\n"; break;
        case'%': cout<<mod(a,b)<<"\n"; break;
      }
    }catch(MyExcept& e){
      cout<<e.getWhat()<<"\n";
    }
  }
}//====================================
 