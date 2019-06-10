#include<iostream>
#include<iomanip>
class Date{
private:
	int year,month,day;
public:
	void check(){
		if(month>12||month<1||day<1||day>31){
			std::cout<<"The program boom!!"<<"\n";exit(1);
		}
	}
	Date(int y=2000,int m=1,int d=1){
		year=y;month=m;day=d;check();
	}
	void set(int y=2000,int m=1,int d=1){
		year=y;month=m;day=d;check();
	}
	void print(){
		std::printf("Today is %04d/%02d/%02d\n",year,month,day);
	}
	void add(){
		day++;
		if(month==2){
			if(year%100==0){
				if(year%400==0){
					if(day==29){day=1;month=3;}
				}
				else{
					if(day==28){day=1;month=3;}
				}
			}
			else{
				if(year%4==0){
					if(day==29){day=1;month=3;}
				}
				else{
					if(day==28){day=1;month=3;}
				}
			}
		}
		else if(month==4||month==6||month==9||month==11){
			if(day==30){day=1;month++;}
		}
		else{
			if(day==31){day=1;month++;}
		}
		if(month==13){month=1;year++;}
	}
};

int main(){
	Date cyz(1999,5,13);
	cyz.add();
	cyz.print();
}