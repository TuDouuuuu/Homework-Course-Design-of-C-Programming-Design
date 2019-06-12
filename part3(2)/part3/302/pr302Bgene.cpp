//=====================================
// ÍÆÅÅÈÕÆÚ_gene
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
  ofstream cout("B32.txt");
  Date d(random(400000)+365250);
  d.print(cout, d.YYMD);
  cout<<"\n";
  for(int i=1; i<=1000; i++)
    cout<<creName()<<" "<<random(1000)<<"\n";
}//====================================
 