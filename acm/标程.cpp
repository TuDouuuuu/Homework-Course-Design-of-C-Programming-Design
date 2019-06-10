#include<bits/stdc++.h>
using namespace std;
int k;
char str1[1005],str2[1005];int same,differ,res;
int main(){
	ifstream cin("in.txt");
	ofstream cout("out.txt");
	while(cin>>k){
		cin>>str1>>str2;
		same=0;differ=0;
		for(int i=0;i<strlen(str1);i++){
			if(str1[i]==str2[i])same++;
			else differ++;
		}
		if(k<same)res=k+differ;
		else res=same+(differ-(k-same));
		cout<<res<<endl;
	}
	return 0;
}