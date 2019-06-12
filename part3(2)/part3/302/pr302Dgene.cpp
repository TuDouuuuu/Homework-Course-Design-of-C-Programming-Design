//=====================================
// ÐÇÆÚ¼¸_gene
//=====================================
#include"date.h"
#include<fstream>
#include<cmath>
using namespace std;
//-------------------------------------
int main(){
  ofstream cout("D32.txt");
  for(int i=1; i<=100; i++)
    cout<<Date(random(33000)+700000)<<"\n";
}//====================================
 