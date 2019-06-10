#include<iostream>
class Time{
private:
	int hour,min,second;
public:
	Time(int h=0,int m=0,int s=0){hour=h;min=m;second=s;check();}
	void set(int h,int m,int s);
	void print();
	void check();
};