//=====================================
// 大数运算_数据生成
//=====================================
#include<fstream>
#include<cmath>
using namespace std;
//-------------------------------------
char op[4]={'+', '-', '*', '/'};
//-------------------------------------
string getNum(){
  string s;
  s += char('0'+random(10));
  if(s!="0"){
    int len = random(100);
    for(int i=1; i<=len; ++i)
      s += char('0'+random(10));
  }
  return s;
}//------------------------------------
int main(){
  ofstream cout("in.txt");
  for(int i=1; i<=1000; ++i)
    cout<<op[random(4)]<<"\n"<<getNum()<<"\n"<<getNum(cout)<<"\n";
  cout<<"@\n";
}//====================================