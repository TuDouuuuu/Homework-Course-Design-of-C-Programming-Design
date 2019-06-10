#include<iostream>
using namespace std;
class MyClass{
	int number;
public:
	MyClass();
	MyClass(int);
	~MyClass();
	void Display();
};
MyClass::MyClass(){cout<<"Constructing normally.\n";}
MyClass::MyClass(int m):number(m){
	cout<<"Constructing with a number:"<<number<<endl;
}
void MyClass::Display(){cout<<"Display a number: "<<number<<endl;}
MyClass::~MyClass(){cout<<"Destructing.\n";}
int main(){
	MyClass obj1;
	MyClass obj2(20);
	obj1.Display();
	obj2.Display();
}