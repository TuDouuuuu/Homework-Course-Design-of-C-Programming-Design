//=====================================
// 统计天数_gene
//=====================================
#include"date.h"
#include<fstream>
#include<set>
#include<cmath>
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
  ofstream cout("A32.txt");
  for(int i=1; i<=200; i++)
  {
    string s = creName();
    int re = random(50)+1;
    Date d(random(400000)+365250);
    for(int j=1; j<=re; j++)
    {
      cout<<s<<" ";
      d += random(20)+1;
      d.print(cout, d.YYMD);
      cout<<" Out\n";
      cout<<s<<" ";
      d += random(20);
      d.print(cout, d.YYMD);
      cout<<" Back\n";
    }
  }
}//====================================
 