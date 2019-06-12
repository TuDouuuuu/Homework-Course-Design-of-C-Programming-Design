//=====================================
// 统计天数
//=====================================
#include"date.h"
#include<fstream>
#include<iomanip>
#include<map>
#include<cmath>
using namespace std;
//-------------------------------------
int main(){
  ifstream cin("pr302A.txt");
  map<string, int> si;
  map<string, Date> sd;
  string n, fs;
  for(Date d; cin>>n; ){
    cin>>d>>fs;
    if(fs=="Out") sd[n]=d;
    else si[n] += d-sd[n]+1;
  }
  cout<<"统计天数:\n";
  for(map<string, int>::iterator it=si.begin(); it!=si.end(); ++it)
    cout<<left<<setw(10)<<it->first<<right<<setw(5)<<it->second<<"\n";
}//====================================
 