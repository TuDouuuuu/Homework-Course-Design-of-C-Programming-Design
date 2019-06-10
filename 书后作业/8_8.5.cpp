#include<iostream>
class Poi{
	static int x;
private:
	int y;
public:
	Poi(){x++;}
	~Poi(){x--;}
	void print(){std::cout<<x<<'\n';}
};
int main(){
	Poi p1;p1.print();
	Poi p2;p2.print();
	Poi p3;p3.print();
}