//=====================================
// date.cpp  ÌìÊý°æ
//=====================================
#include"date.h"
#include"myexcept.h"
#include<cstdlib>
#include<iostream>
#include<iomanip>
using namespace std;
//-------------------------------------
const int Date::tians[]={0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
const char* Date::weekDay[]={"Sun.", "Mon.", "Tue.", "Wed.", "Thu.", "Fri.", "Sat." };
//-------------------------------------
Date::Date(const string& s){
  int y = atoi(s.substr(0,4).c_str());
  int m = atoi(s.substr(5,2).c_str());
  int d = atoi(s.substr(8,2).c_str());
  ymd2i(y,m,d);
}//------------------------------------
void Date::ymd2i(int y, int m, int d){
  if( y<=0||y>9999) throw MyIllegal();
  if(m<=0||m>12) throw MyIllegal();
  if(d<=0||d>tians[m]-tians[m-1]+ m==2&&isLeapYear(y) ) throw MyIllegal();
  absDay =(y-1)*365 + 97*(y-1)/400 + tians[m-1] + (isLeapYear(y)&& m>2) + d;
}//------------------------------------
void Date::i2ymd(int& y, int& m, int& d)const{
  d = absDay % 146097;
  y = (absDay /146097)*400 + (d/36524)*100;
  if( d/36524==4){ m=12, d=30; return; }
  d %= 36524;
  y += (d / 1461)*4;
  d %= 1461;
  y += d / 365;
  if(d/365==4){ m=12, d=30; return; }
  y += (d%=365)!=0;
  for(m=1; (m<12 && d>(isLeapYear(y)&& m>=2)+tians[m]); m++);
  d -= tians[m-1]+(isLeapYear(y)&& m>2);
}//------------------------------------
void Date::print(ostream& o, int ktype)const{
  int y,m,d;
  i2ymd(y,m,d);
  o<<right<<setfill('0');
  switch(ktype){
    case YMD: o<<setw(2)<<y%100<<"-"<<setw(2)<<m<<"-"<<setw(2)<<d; break;
    case MDY: o<<setw(2)<<m<<"-"<<setw(2)<<d<<"-"<<setw(2)<<y%100; break;
    case YYMD: o<<setw(4)<<y<<"-"<<setw(2)<<m<<"-"<<setw(2)<<d; break;
    case MDYY: o<<setw(2)<<m<<"-"<<setw(2)<<d<<"-"<<setw(4)<<y; break;
    default:   throw MyFormatError();
  }
  o<<setfill(' ');
}//------------------------------------
istream& operator>>(istream& i, Date& d){
  string s;
  if(i>>s)
    d = Date(s);
  return i;
}//------------------------------------
ostream& operator<<(ostream& o, const Date& d){
  d.print(o, d.YYMD);
  return o;
}//------------------------------------
