#include"8_4_class.cpp"
void Time::set(int h,int m,int s){hour=h;min=m;second=s;check();}
void Time::print(){std::cout<<"The time is "<<hour<<":"<<min<<":"<<second<<'\n';}
void Time::check(){
	if(hour<1||hour>12||min<1||min>=60||second<1||second>=60){
		std::cout<<"The program is booming!!"<<'\n';exit(1);
	}
}
int main(){
	Time haha(7,4,2);
	haha.print();
}