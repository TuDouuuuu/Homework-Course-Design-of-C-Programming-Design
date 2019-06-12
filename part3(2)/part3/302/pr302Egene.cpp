//=====================================
// ∞≤≈≈ª·“È_gene
//=====================================
#include"date.h"
#include<fstream>
#include<cmath>
using namespace std;
//-------------------------------------
int main(){
  ofstream cout("E32.txt");
  cout<<"2007-12-15 2008-12-15 "<<random(10)+1<<"\n";
  Date curD(2007,12,15), lastD(2008,12,15);
  Date d1(2007,12,18), d2(2007,12,21);
  for(int i=1,n; d2<lastD; i++){
    cout<<d1;
    if(d1!=d2) cout<<" "<<d2;
    cout<<"\n";
    n = random(25);
    d1 = d2+(random(n)+1), d2 = d1+random(20);
  }
}//====================================
 