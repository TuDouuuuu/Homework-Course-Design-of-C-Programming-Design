//=====================================
// program.h
//=====================================
#ifndef PROGRAM_HEADER
#define PROGRAM_HEADER
//#include"token.h"
#include<iostream>
#include<map>
using namespace std;
//-------------------------------------
class Program{
public:
  Program(istream& in, ostream& out):_in(in),_out(out){}
  istream& _in;
  ostream& _out;
  void run();
};//-----------------------------------
#endif  // PROGRAM_HEADER

 