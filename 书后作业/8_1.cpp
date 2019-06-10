#include<cmath>
#include<iostream>
using namespace std;
class Point{
private:
	double x;double y;
public:
	void Set(double ix,double iy){
		x=ix;y=iy;
	}
	double xOffset(){
		return x;
	}
	double yOffset(){
		return y;
	}
	double angle(){
		return (180/3.14159)*atan2(y,x);
	}
	double radius(){
		return sqrt(x*x+y*y);
	}
	//需增加：
	void fun(){
		x+=5;y+=6;
	}
};
int main(){
	Point p;
	double x,y;
	cout<<"Enter x and y:\n";//在开头没有用iostream的头文件
	cin>>x>>y;//在开头没有用iostream的头文件
	p.Set(x,y);
	p.fun();//需增加
	//p.x+=5;//不能直接操作
	//p.y+=6;//不能直接操作

	cout<<"angle="<<p.angle()<<",radius="<<p.radius()<<",x offset="<<p.xOffset()<<",y offset="<<p.yOffset()<<endl;
}