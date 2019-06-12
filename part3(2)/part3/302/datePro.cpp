//=====================================
// 日期处理
//=====================================
#include"dateProf.h"
#include"date.h"    // shared
#include<conio.h>   // for clreol()
#include<iomanip>   // for pr302A, pr302B
#include<map>       // for pr302A
#include<vector>    // for pr302B, pr302C
#include<algorithm> // for pr302B, pr302C
#include<sstream>   // for pr302E
using namespace std;
//-------------------------------------
struct NameD{
  NameD(const string& s, const Date& d):name(s), day(d){}
  string name;
  Date day;
};//-----------------------------------
bool operator<(const NameD& nd1, const NameD& nd2){
  return nd1.day==nd2.day ? (nd1.name < nd2.name) : (nd1.day < nd2.day);
}//------------------------------------
struct NameN{
  NameN(const string& s, int n):name(s), tian(n){}
  string name;
  int tian;
};//-----------------------------------
bool operator<(const NameN& n1, const NameN& n2){
  return n1.tian==n2.tian ? (n1.name < n2.name):(n1.tian < n2.tian);
}//------------------------------------
void pr302A(istream& cin, ostream& cout){
  map<string, int> si;
  map<string, Date> sd;
  string n, fs;
  for(Date d; cin>>n; ){
    cin>>d>>fs;
    if(fs=="Out") sd[n]=d;
    else si[n] += d-sd[n]+1;
  }
  cout<<"统计天数:\n";
  for(map<string, int>::iterator it=si.begin(); it!=si.end(); ++it){
    cout<<left<<setw(10)<<it->first<<right<<setw(5)<<it->second<<"\n";
    //clreol();
  }
}//------------------------------------
void pr302B(istream& cin, ostream& cout){
  vector<NameD> nd;
  Date curDay;
  cin>>curDay;
  int n;
  for(string s; cin>>s>>n; )
    nd.push_back( NameD(s, curDay + n) );
  sort(nd.begin(), nd.end());
  cout<<"推排日期:\n";
  for(int i=0; i<nd.size(); ++i){
    cout<<left<<setw(11)<<nd[i].name<<nd[i].day<<"\n";
    //clreol();
  }
}//------------------------------------
void pr302C(istream& cin, ostream& cout){
  vector<NameN> nd;
  Date curDay, d;
  cin>>curDay;
  for(string s; cin>>s>>d; )
    nd.push_back( NameN(s, d-curDay) );
  sort(nd.begin(), nd.end());
  cout<<"确定天数:\n";
  for(int i=0; i<nd.size(); ++i){
    cout<<nd[i].name<<" "<<nd[i].tian<<"\n";
    //clreol();
  }
}//------------------------------------
void pr302D(istream& cin, ostream& cout){
  cout<<"星期几:\n";
  for(Date d; cin>>d; ){
    cout<<d.getWeekDay()<<"\n";
    //clreol();
  }
}//------------------------------------
void pr302E(istream& cin, ostream& cout){
  Date a,b,d, mD;
  int n, maxd = 0;
  cin>>a>>b>>n;
  cin.ignore();
  for(string s,t; getline(cin, s); a=d+1){
    istringstream sin(s);
    sin>>d;
    if(d-a > maxd) maxd = d-a, mD = a;
    sin>>d;
  }
  if(b-a+1>maxd) maxd=b-a+1, mD=a;
  d = mD + (maxd - n)/2;
  cout<<"安排会议:\n";
  d.print(cout, d.MDYY);
  cout<<"\n";
  //clreol();
}//------------------------------------

