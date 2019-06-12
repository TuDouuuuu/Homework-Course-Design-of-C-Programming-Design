#include"date.h"
#include<iostream>
using namespace std;
int main(){
  Date d1(733127), e1("2008-03-26");
  cout<<d1<<" "<<e1<<"\n";
  Date d2(733066), e2("2008-01-25");
  cout<<d2<<" "<<e2<<"\n";
  Date d3(733100), e3("2008-02-28");
  Date d4(733101), e4("2008-02-29");
  Date d5(733102), e5("2008-03-01");
  cout<<d3<<" "<<e3<<"\n";
  cout<<d4<<" "<<e4<<"\n";
  cout<<d5<<" "<<e5<<"\n";
}//====================================
 