#include<iostream>
#include<iomanip>
using namespace std;
int moday[13]={0,31,0,31,30,31,30,31,31,30,31,30,31};//每月有多少天
class Date{
	int year,month,day;
	void init();
public:
	Date(const string& s);
	Date(int y=2000,int m=1,int d=1);
	Date plus(int d);//通过加天数获得另一个日期
	bool isLeapYear()const;
	friend ostream& operator<<(ostream& o,const Date& d);
	friend int operator-(const Date& d1,const Date& d2);//日期减日期获得相隔天数
	friend bool operator!=(const Date& d1,const Date& d2);
};
void Date::init(){
	if(year>5000||year<1||month<1||month>12||day<1||day>31)
		exit(1);
}
Date::Date(const string& s){
	year =atoi(s.substr(0,4).c_str());
	month=atoi(s.substr(5,2).c_str());
	day=atoi(s.substr(8,2).c_str());
	init();
}
Date::Date(int y,int m,int d){
	year=y,month=m,day=d;
	init();
}

bool Date::isLeapYear()const{
	return(year%4==0&&year%100)||year%400==0;
}
ostream& operator<<(ostream& o,const Date& d){
	o<<setfill('0')<<setw(4)<<d.year<<'-'<<setw(2)<<d.month<<'-';
	return o<<setw(2)<<d.day<<'\n'<<setfill(' ');
}
	
bool operator!=(const Date& d1,const Date& d2){
	//cout<<"dsaf:"<<d1.year<<" "<<d2.year;
	if(d1.year==d2.year&&d1.month==d2.month&&d1.day==d2.day)return 0;
	return 1;
}

int operator-(const Date& d1,const Date& d2){
	int cnt=0;Date temp1,temp2;
	if(d1.year>d2.year||d1.month>d2.month||d1.day>d2.day){//默认d1先于d2，此处交换。
		temp2.year=d1.year;temp2.month=d1.month;temp2.day=d1.day;
		temp1.year=d2.year;temp1.month=d2.month;temp1.day=d2.day;
		//swap(&d1.year,&d2.year);swap(&d1.month,&d2,month);swap(&d1.day,&d2.day);
	}
	else{
		temp1.year=d1.year;temp1.month=d1.month;temp1.day=d1.day;
		temp2.year=d2.year;temp2.month=d2.month;temp2.day=d2.day;
	}
	while(temp1!=temp2){
		temp1=temp1.plus(1);
		cnt++;//cout<<temp<<" "<<d2<<endl;
	}
	
	return cnt;

}

Date Date::plus(int d){
	Date temp(year,month,day);
	temp.day+=d;
	if(temp.isLeapYear())moday[2]=29;
	else moday[2]=28;
	while(temp.day>moday[temp.month]){
		temp.day-=moday[temp.month];
		temp.month++;
		if(temp.month>12){
			temp.year++;temp.month=1;
			if(temp.isLeapYear())moday[2]=29;
			else moday[2]=28;
		}
	}
	return temp;
}

int main(){
	Date c("2005-12-28");
	Date d(2003,12,6);
	Date e(2002);
	Date f(2002,12);
	cout<<"example:"<<endl;
	Date ex1(2005,8,21);
	Date ex2(2008,8,8);
	cout<<ex1<<ex2;
	cout<<ex2-ex1<<endl;
	cout<<ex1.plus(300);
}