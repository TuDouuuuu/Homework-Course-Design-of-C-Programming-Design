//=====================================
// StrInt.cpp  -- 类型字串版
//=====================================
#include"strInt.h"
#include"myexcept.h"
//-------------------------------------
static string adding( const string& a, const string& b );
static string subing( const string& a, const string& b );  // suppose a>b
static bool absLess( const string& a, const string& b );
//-------------------------------------
StrInt::StrInt(const string& a){
  if(a.length()==0 || a[0]=='0'&& a.length()>1) throw MyIllegal();
  if(a[0]=='-'){ sign="-"; num=a.substr(1); }
  else num = a;
}//------------------------------------
StrInt add( const StrInt& a, const StrInt& b ){
  if(a.num=="0") return b;
  if(b.num=="0") return a;
  StrInt s;
  if(a.sign==b.sign){
    s.sign = a.sign;
    s.num = adding(a.num, b.num);
  }else if( absLess(a.num, b.num) ){
    s.sign = b.sign;
    s.num = subing(b.num, a.num);
  }else{
    s.sign = a.sign;
    s.num = subing(a.num, b.num);
  }
  if( s.num.length() > StrInt::BITNUM ) throw MyTooLarge();
  return s;
}//------------------------------------
StrInt sub( const StrInt& a, const StrInt& b ){
  StrInt s(b);
  s.sign = (s.sign=="-" ? "":"-");
  return add( a, s );
}//------------------------------------
StrInt mul( const StrInt& a, const StrInt& b ){
  if(a.num=="0" || b.num=="0") return string("0");
  StrInt ss;
  ss.sign = (a.sign==b.sign ? "" : "-");

  string s(a.num.length()+b.num.length(), '0');
  for(int bi=b.num.length()-1; bi>=0; --bi){
    if(b.num[bi]=='0') continue;
    for(int t=0, ai=a.num.length()-1, si=s.length()-b.num.length()+bi; ai>=0; --ai){
      t += (a.num[ai]-'0')*(b.num[bi]-'0') + s[si]-'0';
      s[si--] = char(t%10+'0');
      t/=10;
    }
  }
  int pos = s.find_first_not_of('0');
  ss.num = (pos!=string::npos ? s.substr(pos) : s);
  if( ss.num.length() > StrInt::BITNUM ) throw MyTooLarge();
  return ss;
}//------------------------------------
StrInt div( const StrInt& a, const StrInt& b ){
  if(b.num=="0") throw MyDivideZero();
  if( absLess(a.num, b.num) ) return string("0");
  StrInt ss;
  ss.sign = (a.sign==b.sign ? "" : "-");

  string s, y(a.num.substr(0, b.num.length()-1));
  for(int i=b.num.length()-1; i<a.num.length(); ++i){
    int cnt=0;
    for(y=(y=="0"? string(1,a.num[i]): y+a.num[i]); !absLess( y, b.num ); cnt++)
      y = subing( y, b.num );
    s += char(cnt+'0');
  }
  int pos = s.find_first_not_of('0');
  ss.num = (pos!=string::npos ? s.substr(pos) : s);
  return ss;
}//------------------------------------
StrInt mod( const StrInt& a, const StrInt& b ){
  if(b.num=="0") throw MyDivideZero();
  if(a.num=="0" || b.num=="1" || a.num == b.num) return string("0");
  if( absLess( a.num, b.num ) ) return a;
  StrInt ss;
  ss.sign = a.sign;
  string s, y(a.num.substr(0, b.num.length()-1));
  for(int i=b.num.length()-1; i<a.num.length(); ++i){
    int cnt=0;
    for(y=(y=="0"? string(1,a.num[i]): y+a.num[i]); !absLess( y, b.num ); cnt++)
      y = subing( y, b.num );
    s += char(cnt+'0');
  }
  ss.num = y;
  return ss;
}//------------------------------------
bool absLess( const string& a, const string& b ){
  return a.length()<b.length() || a.length()==b.length() && a<b;
}//------------------------------------
string adding( const string& a, const string& b ){
  int len = (a.length()<b.length() ? b.length() : a.length())+1;
  string s = string(len-a.length(), '0')+a;
  int tmp = 0;
  for(int i=1, bi=b.length()-1, si=s.length()-1; i<=b.length()||tmp; ++i, si--){
    if(i<=b.length()) tmp += s[si]-'0' + b[bi--]-'0';
    else tmp += s[si]-'0';
    s[si] = char(tmp%10+'0');
    tmp /= 10;
  }
  int pos = s.find_first_not_of('0');
  return (pos!=string::npos ? s.substr(pos) : s);
}//------------------------------------
string subing( const string& a, const string& b ){
  if(a==b) return "0";
  string s(a);
  for(int i=1, bi=b.length()-i,si=s.length()-i; i<=b.length(); ++i,si--,bi--)
    if((s[si]-=(b[bi]-'0'))<'0')
      s[si]+=10, s[si-1]--;
  int pos = s.find_first_not_of('0');
  return (pos!=string::npos ? s.substr(pos) : s);
}//------------------------------------
istream& operator>>(istream& in, StrInt& a){
  string s;
  in>>s;
  a = StrInt(s); //可能抛掷Illegal异常
  return in;
}//------------------------------------
ostream& operator<<(ostream& out, const StrInt& a){
  return out<<a.sign + a.num;
}//------------------------------------
