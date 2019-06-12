#include"strint.h"
#include"unexpected.h"
using namespace std;
#include<iostream>
const int BITNUM = 200;

bool cmp(const string& a,const string& b){
	return a.length()<b.length()||a.length()==b.length()&& a<b;
}

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
}

string subing(const string& a,const string& b){
	if(a==b) return "0";
	string s(a);
	for(int i=1, bi=b.length()-i,si=s.length()-i; i<=b.length(); ++i,si--,bi--)
		if((s[si]-=(b[bi]-'0'))<'0')
			s[si]+=10, s[si-1]--;
	int pos = s.find_first_not_of('0');
	return (pos!=string::npos ? s.substr(pos) : s);
}

strInt::strInt(){
	num="0";
}

strInt::strInt(const string& a){
	if(a.length()==0 || (a[0]=='0'&& a.length()>1)){
		throw unexpectedNull();
	}
	if(a[0]=='-'){ sign="-"; num=a.substr(1); }
	else num = a;
}

strInt add( const strInt& a, const strInt& b ){
	if(a.num=="0") return b;
	if(b.num=="0") return a;
	strInt s;
	if(a.sign==b.sign){
		s.sign = a.sign;
		s.num = adding(a.num, b.num);
	}
	else if( cmp(a.num, b.num) ){
		s.sign = b.sign;
		s.num = subing(b.num, a.num);
	}
	else{
    	s.sign = a.sign;
    	s.num = subing(a.num, b.num);
 	}
  	if( s.num.length() > BITNUM ) throw unexpectedLarge();
  	return s;
}

strInt sub( const strInt& a, const strInt& b ){
	strInt s(b);
	s.sign = (s.sign=="-" ? "":"-");
	return add( a, s );
}

strInt mul( const strInt& a, const strInt& b ){
	if(a.num=="0" || b.num=="0") return string("0");
	strInt ss;
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
	if( ss.num.length() > BITNUM ) throw unexpectedLarge();
	return ss;
}

strInt div( const strInt& a, const strInt& b ){
	if(b.num=="0") throw unexpectedZero();
	if( cmp(a.num, b.num) ) return string("0");
	strInt ss;
	ss.sign = (a.sign==b.sign ? "" : "-");

	string s, y(a.num.substr(0, b.num.length()-1));
	for(int i=b.num.length()-1; i<a.num.length(); ++i){
	    int cnt=0;
	    for(y=(y=="0"? string(1,a.num[i]): y+a.num[i]); !cmp( y, b.num ); cnt++)
	      	y = subing( y, b.num );
	    s += char(cnt+'0');
  	}
	int pos = s.find_first_not_of('0');
	ss.num = (pos!=string::npos ? s.substr(pos) : s);
	return ss;
}

strInt mod( const strInt& a, const strInt& b ){
	if(b.num=="0") throw unexpectedZero();
	if(a.num=="0" || b.num=="1" || a.num == b.num) return string("0");
	if( cmp( a.num, b.num ) ) return a;
	strInt ss;
	ss.sign = a.sign;
	string s, y(a.num.substr(0, b.num.length()-1));
	for(int i=b.num.length()-1; i<a.num.length(); ++i){
	    int cnt=0;
	    for(y=(y=="0"? string(1,a.num[i]): y+a.num[i]); !cmp( y, b.num ); cnt++)
	      	y = subing(y, b.num );
	    s += char(cnt+'0');
  	}
	ss.num = y;
	return ss;
}

string strInt::display(){
	return sign+num;
}