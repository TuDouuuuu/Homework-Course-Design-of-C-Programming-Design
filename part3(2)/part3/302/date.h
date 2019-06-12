//=====================================
// date.h   ÌìÊý°æ
//=====================================
#ifndef DATE_HEADER
#define DATE_HEADER
#include<iostream>
using namespace std;
//-------------------------------------
class Date{
  int absDay;
  void ymd2i(int y, int m, int d);
  void i2ymd(int& y, int& m, int& d)const;
  static const int tians[];
  static const char* weekDay[];
public:
  enum { YYMD, MDYY, YMD, MDY };
  Date(const string& s);
  Date(int n=1) : absDay(n){}
  Date(int y, int m, int d){ ymd2i(y,m,d); }
  Date operator+(int n)const{ return Date(absDay + n); }
  Date& operator+=(int n){ absDay += n; return *this; }
  Date& operator++(){ absDay++; return *this; }
  Date& operator--(){ absDay--; return *this; }
  bool operator==(const Date& d)const{ return absDay==d.absDay; }
  bool operator!=(const Date& d)const{ return absDay!=d.absDay; }
  bool operator<(const Date& d)const{ return absDay < d.absDay; }
  void print(ostream& out, int type)const;
  int operator-(Date& d)const{ return absDay - d.absDay; }
  bool isLeapYear(int y)const{ return y%4==0 && y%100 || y%400==0; }
  const char* getWeekDay(){ return weekDay[absDay%7]; }
  friend istream& operator>>(istream& i, Date& d);
  friend ostream& operator<<(ostream& o, const Date& d);
};//-----------------------------------
#endif  // DATE_HEADER

