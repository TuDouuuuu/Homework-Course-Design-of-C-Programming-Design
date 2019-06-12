#include"strint.h"
#include"unexpected.h"
#include"iostream"
#include<fstream>
using namespace std;
int main(){
	ifstream cin("in.txt");//输入文件
	ofstream cout("out.txt");//输出文件
	char ch;string s1,s2;
	int cnt=1;
	while(cin>>ch&&ch!='@'){
		try{
			if(!(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='%'))
				throw unexpectedOp();
			else{
				cin>>s1>>s2;
				strInt a(s1);strInt b(s2);
				cout<<cnt++<<" ";
				switch(ch){
					case'+':cout<<add(a,b).display();break;
					case'-':cout<<sub(a,b).display();break;
					case'*':cout<<mul(a,b).display();break;
					case'/':cout<<div(a,b).display();break;
					case'%':cout<<mod(a,b).display();break;
				}
				cout<<endl;//保证每行换行
			}
		}
		catch(unexpect& n){//处理异常
			cout<<n.getWhat()<<endl;
		}

	}
}