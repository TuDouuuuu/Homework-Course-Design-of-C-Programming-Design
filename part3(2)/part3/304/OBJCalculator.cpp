//=====================================
// ¼ÆËãÆ÷³ÌÐò
//=====================================
#include"program.h"
#include<fstream>
#include<iostream>
using namespace std;
//-------------------------------------
int main(){
  ifstream cin("calc.txt");
  //ofstream cout("calc.out");
  Program p(cin, cout);
  p.run();
}//=====================================


