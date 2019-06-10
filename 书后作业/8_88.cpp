#include<iostream>
class Poi{
private:
	static int x;
public:
	Poi(){x++;}
	~Poi(){x--;print();}
	void print(){std::cout<<x<<'\n';}
};
int Poi::x=0;
int main(){
	Poi p1;
	p1.print();
	Poi p2;
	p2.print();
	Poi p3;
	p3.print();
}