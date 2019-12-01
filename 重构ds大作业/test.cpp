#include<bits/stdc++.h>
using namespace std;
class node{
public:
    string username,password; //数据的储存
    int deep = 1;   //树高
    node* lson = NULL;node* rson = NULL;    //左儿子右儿子
    node(const string& _username,const string& _password){
        username = _username;password = _password;
    }
    // bool operator < (const node& b)const;
};

int poi(node* rt){
    if(rt == NULL)return 0;
    else return rt->deep;
}

int main(){
    string s1 = "zkasb";
    string s2 = "shknb";
    node* nd = new node(s1,s2);
    printf("%d\n",poi(nd));
    printf("%d\n",poi(nd->lson));

}