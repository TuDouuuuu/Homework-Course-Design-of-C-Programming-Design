//=====================================
// 大数运算_数据生成
//=====================================
#include<fstream>
#include<cmath>
using namespace std;
//-------------------------------------
char op[5]={'+', '-', '*', '/', '%'};
//-------------------------------------
bool printNum(ostream& cout, int a){
  cout<<a;
  if(a){
    int len = random(100);
    for(int i=1; i<=len; ++i)
      cout<<random(10);
  }
  cout<<"\n";
}//------------------------------------
int main(){
  ofstream cout("bignumm.in");
  for(int i=1; i<=1000; ++i){
    cout<<op[random(5)]<<"\n";
    printNum(cout, random(10));
    printNum(cout, random(10));
  }
  cout<<"@\n";
}//====================================