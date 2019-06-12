#ifndef _HEADER_STRINT_
#define _HEADER_STRINT_
#include<iostream>
using std::string;
class strInt{
private:
	string sign;
	string num;
	void swap(int& x,int& y);
public:
	strInt();//默认构造函数值为0
	strInt(const string&);

	friend strInt mul(const strInt& a,const strInt& b);
	friend strInt add(const strInt& a,const strInt& b);
	friend strInt sub(const strInt& a,const strInt& b);
	friend strInt div(const strInt& a,const strInt& b);
	friend strInt mod(const strInt& a,const strInt& b);

	string display();
};
#endif