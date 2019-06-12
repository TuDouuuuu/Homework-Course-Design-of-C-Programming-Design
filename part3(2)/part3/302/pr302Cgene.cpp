//=====================================
// 确定天数_gene
//=====================================
#include"date.h"
#include<fstream>
#include<iostream>
#include<cmath>
#include<set>
using namespace std;
//-------------------------------------
string creName(){
  static set<string> names;
  int num = random(10)+1;
  string s;
  for(int i=1; i<=num; ++i)
    s += char(random(26)+'a');
  if(names.find(s)!=names.end()) return creName();
  names.insert(s);
  return s;
}//------------------------------------
int main(){
  ofstream cout("C32.txt");
  Date d( random(3000)+730000 );
  d.print(cout, d.YYMD);
  cout<<"\n";
  for(int i=1; i<=200; i++)
    cout<<creName()<<" "<< d + random(200) <<"\n";
}//====================================
 