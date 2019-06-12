//=====================================
// StrInt + - * /(Õû³ý) % (È¡Ä£)
//=====================================
#include<iostream>
using namespace std;
//-------------------------------------
class StrInt{
  enum { BITNUM = 200 };
  string sign;
  string num;
public:
  StrInt(const string& a = string("0") );
  friend StrInt mul( const StrInt& a, const StrInt& b );
  friend StrInt add( const StrInt& a, const StrInt& b );
  friend StrInt sub( const StrInt& a, const StrInt& b );
  friend StrInt div( const StrInt& a, const StrInt& b );
  friend StrInt mod( const StrInt& a, const StrInt& b );
  friend istream& operator>>(istream& in, StrInt& a);
  friend ostream& operator<<(ostream& out, const StrInt& a);
};//-----------------------------------

 