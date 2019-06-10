#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
class Point{
protected:
	float x,y;
public:
	Point(float xx=0,float yy=0){x=xx;y=yy;}
	void setPoint(float xx=0,float yy=0){x=xx;y=yy;}
	float getX()const{return x;}
	float getY()const{return y;}
};
class Shape{
public:
	virtual float area()=0;
	void display(){cout<<area()<<endl;}
};
class Circle:public Shape{
protected:
	float r;Point p;
public:
	Circle(float xx=0,float yy=0,float rr=0):p(xx,yy),r(rr){}
	void setR(float rr){r=rr;}
	virtual float area()const{cout<<"adsfds";return 3.1415926*r*r;}
};
class Rectangle:public Shape{
protected:
	Point p1,p2;
public:
	Rectangle(float x1=0,float x2=0,float y1=0,float y2=0):p1(x1,y1),p2(x2,y2){}
	void setRectangle(float x1=0,float x2=0,float y1=0,float y2=0){
		p1.setPoint(x1,y1);p2.setPoint(x2,y2);
	}
	virtual float area()const{return abs(p1.getX()-p2.getX())*abs(p1.getY()-p2.getY());}
};
class Triangle:public Shape{
protected:
	Point p1,p2,p3;
public:
	Triangle(float x1=0,float x2=0,float x3=0,float y1=0,float y2=0,float y3=0):p1(x1,y1),p2(x2,y2),p3(x3,y3){}
	void setTriangle(float x1=0,float x2=0,float x3=0,float y1=0,float y2=0,float y3=0){
		p1.setPoint(x1,y1);p2.setPoint(x2,y2);p3.setPoint(x3,y3);
	}
	virtual float area()const{return (p1.getX()*p2.getY()+p2.getX()*p3.getY()+p2.getX()*p1.getX())/2;}
};




int main(){
	char ch;
	Shape* pt=NULL;
	while(cin>>ch){
		if(ch=='C'){
			int x,y,r;cin>>x>>y>>r;
			//Shape t(x,y,r);pt=&t;
		}
		else if(ch=='T'){
			int x1,x2,x3,y1,y2,y3;
			cin>>x1>>x2>>x3>>y1>>y2>>y3;
			//Shape t(x1,x2,x3,y1,y2,y3);pt=&t;
		}
		else if(ch=='R'){
			int x1,x2,y1,y2;
			cin>>x1>>x2>>y1>>y2;
			//Shape t(x1,x2,y1,y2);pt=&t;
		}
		else if(ch=='X')break;
		pt->display();
	}
}