//=====================================
// BigIntApp.cpp
// 大整数加、减、乘、整除
//=====================================
#include"BigInt.h"
#include<fstream>
#include<iostream>
using namespace std;
//-------------------------------------
int main(){
  ifstream cin("in.txt");
  ofstream cout("test.out");
  char ch;
  int n=1;
  for(string a,b,c; cin>>ch && ch!='@'; n++){
    cin>>a>>b;
    switch(ch){
      case'-': cout<<n<<" "<<sub(a, b)<<"\n";
               break;
      case'+': cout<<n<<" "<<add(a, b)<<"\n";
               break;
      case'*': c = mul(a, b);
               if(c.length()>BYTENUM)
                 cout<<n<<" Too Large Number.\n";
               else
                 cout<<n<<" "<<c<<"\n";
               break;
      case'/': if(b!="0")
                 cout<<n<<" "<<div(a, b)<<"\n";
               else
                 cout<<n<<" Divide By Zero.\n";
               break;
      default: cout<<"Illegal Operator.\n";
    }
  }
}//====================================
 