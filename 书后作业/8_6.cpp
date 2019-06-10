#include<iostream>
class Boat;
class Car{
	int size;
public:
	void setSize(int j){size=j;}
	//int getSize(){return size;}
	friend int leisure(int time,Car &aobj,Boat &bobj);
};
class Boat{
	int size;
public:
	void setSize(int j){size=j;}
	//int getSize(){return size;}
	friend int leisure(int time,Car &aobj,Boat &bobj);
};

int leisure(int time,Car &aobj,Boat &bobj){
	return time*aobj.size*bobj.size;
}

int main(){
	Car c1;c1.setSize(2);
	Boat b1;b1.setSize(3);
	std::cout<<leisure(5,c1,b1);
}