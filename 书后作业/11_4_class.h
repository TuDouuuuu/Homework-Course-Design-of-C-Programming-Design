#ifndef _HEADER_11_4_CLASS_H
#define _HEADER_11_4_CLASS_H
#include"11_2_class.h"
#include<iostream>
using std::ostream;
using namespace std;
class Complex:public strInt{
private:
	strInt a;strInt b;
public:
	Complex(const string& x,const string y):a(x),b(y){};
	friend bool cmp(const Complex& x,const Complex& y);
	friend ostream& operator<<(ostream &os,const Complex& n);
};

ostream& operator<<(ostream &os,const Complex& n){
	os<<n.a.display()<<" + "<<n.b.display();
	os<<"i";
}

bool cmp(const Complex& x,const Complex& y){
	strInt t1=add(mul(abs(x.a),abs(x.a)),mul(abs(x.b),abs(x.b)));
	strInt t2=add(mul(abs(y.a),abs(y.a)),mul(abs(y.b),abs(y.b)));
	return strIntCmp(t1,t2);
}
#endif