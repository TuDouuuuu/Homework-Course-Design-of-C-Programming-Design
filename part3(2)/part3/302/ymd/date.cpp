//=====================================
// date.cpp
// Class Date with year-month-day Version
//=====================================
#include"date.h"
#include<iostream>
#include<iomanip>
using namespace std;
//-------------------------------------
const int Date::tians[]={0, 31, 59, 89, 120, 150, 181, 212, 242, 273, 303, 334};
//-------------------------------------
Date::Date(const string& s){
  year = atoi(s.substr(0,4).c_str());
  month = atoi(s.substr(5,2).c_str());
  day = atoi(s.substr(8,2).c_str());
}//------------------------------------
void Date::i2ymd(int absDay){
  absDay = absDay>0 && absDay<3650000 ? absDay : 1;
  int n = absDay;
  for(year=1; n>isLeapYear()+365; n-=isLeapYear()+365, year++);
  for(month=1;(month<12&& n>(isLeapYear()&& month>2)+tians[month]); month++);
  day = n-(isLeapYear()&& month>2)-tians[month-1];
}//------------------------------------
int Date::ymd2i()const{
  int absDay =(year-1)*365 + (year-1)/4 - (year-1)/100 + (year-1)/400;
  return absDay += tians[month-1] + (isLeapYear()&& month>2) + day;
}//------------------------------------
void Date::print(ostream& o)const{
  o<<setfill('0')<<setw(4)<<year<<'-'<<setw(2)<<month<<'-'
   <<setw(2)<<day<<"\n"<<setfill(' ');
}//------------------------------------
ostream& operator<<(ostream& o, const Date& d){
  d.print(o);
  return o;
}//------------------------------------

 