/*
    叶璇@201806060825    
*/  
#include "AVLTree.h"
// node部分
node::node(const string& _username,const string& _password){
    username = _username;password = _password;
    deep = 1;
    lson = NULL;rson = NULL;
}
bool node::operator <(const node& b)const{
    return username < b.username;
}

// AVLTree部分
int AVLTree::getDeep(node*& rt){    //获得树高
    if(rt == NULL)return 0;
    else return rt->deep;
}

int AVLTree::deltaDeep(node*& rt){   //左子树高减右子树高
    if(rt->lson)updateDeep(rt->lson);
    if(rt->rson)updateDeep(rt->rson);
    return getDeep(rt->lson)-getDeep(rt->rson);
}

void AVLTree::updateDeep(node*& rt){    //更新树高
    rt->deep = max(getDeep(rt->lson),getDeep(rt->rson))+1;
}

void AVLTree::L(node*& rt){ //左旋
    node* tmp = rt->rson;
    rt->rson = tmp->lson;
    tmp->lson = rt;
    updateDeep(tmp);updateDeep(rt);
    rt = tmp;
}

void AVLTree::R(node*& rt){ //右旋
    node* tmp = rt->lson;
    rt->lson = tmp->rson;
    tmp ->rson = rt;
    updateDeep(tmp);updateDeep(rt);
    rt = tmp;
}

int AVLTree::_insert(node*& rt,string& _username,string& _password){ //插入的辅助函数
    if(rt == NULL){
        rt = new node(_username,_password);
        return 1;
    }
    int flag = 0;
    if(_username < rt->username)flag = _insert(rt->lson,_username,_password);
    else if(_username > rt->username)flag = _insert(rt->rson,_username,_password);
    if(flag == 0)return 0;
    _AVL(rt);
    return 1;
}

node** AVLTree::_query(node*& rt,string& _username){  //查询和验证用户辅助函数
    if(rt == NULL)return &rt; //rt为空返回此时的地址
    else if(_username < rt->username)return _query(rt->lson,_username);
    else if(_username > rt->username)return _query(rt->rson,_username);
    else return &rt;
}

int AVLTree::_erase(node*& rt,string& _username,string& _password){  //删除的辅助函数
    if(rt == NULL)return 0;  //0表示找不到
    int flag = -1; //-1表示密码错误
    if(_username < rt->username)flag = _erase(rt->lson,_username,_password);
    else if(_username > rt->username)flag = _erase(rt->rson,_username,_password);
    else{
        if(_password == rt->password){
            printf("rt->username=%s\n",rt->username.c_str());
            if(rt->lson && rt->rson){
                node* tmp = rt->lson;
                while(tmp->rson)tmp = tmp->rson;
                // (*rt)=(*tmp);
                rt->username = tmp->username;
                rt->password = tmp->password;
                _erase(rt->lson,tmp->username,tmp->password);
            }
            else{
                node* tmp = rt;
                if(rt->lson)rt = rt->lson;
                else if(rt->rson)rt = rt->rson;
                // delete tmp;tmp = NULL;
                else{
                    delete rt;
                    rt = NULL;
                }
                if(rt)delete tmp;
                // delete tmp;rt = NULL;
                return 1;//1表示成功
            }
            _AVL(rt);// 重新平衡
            return 1;
        }
        else return -1;
    }
    return flag;
}

int AVLTree::_update(node*& rt,string& _username,string& _password,string& _newpassword){
    node** p = _query(head,_username);
    if((*p) == NULL) return 0;
    else if((*p)->password == _password){
        (*p)->password = _newpassword;
        return 1;
    }
    else return -1; //更新密码辅助函数  
}

void AVLTree::_graph(node*& rt,bool flag,const string& str){  //图形化辅助函数
    int len = (rt->username).length();
    if(rt->rson)_graph(rt->rson,false,str + (flag?"|     " : "      ") + string(max(len-1,0),' '));
    printf("%s%c-----",str.c_str(),flag?'\\':'/');
    printf("%s\n",(rt->username).c_str());
    if(rt->lson)_graph(rt->lson,true, str + (flag?"      " : "|     ") + string(max(len-1,0),' '));
}

void AVLTree::_AVL(node*& rt){  //平衡操作
    updateDeep(rt);
    int delta = deltaDeep(rt);
    if(delta > 1 || delta < -1){
        if(delta >1){
            int ldelta = deltaDeep(rt->lson);
            if(ldelta > 0)R(rt);
            else if(ldelta <0){L(rt->lson);R(rt);}
        }
        else if(delta <-1){
            int rdelta = deltaDeep(rt->rson);
            if(rdelta <0)L(rt);
            else if(rdelta >0){R(rt->rson);L(rt);}
        }
    }
}

void AVLTree::_LVR(node*& rt){
    if(rt == NULL)return;
    
    printf("%s\n",rt->username.c_str());
    _LVR(rt->lson);
    _LVR(rt->rson);
}

// public 部分
int AVLTree::insert(string& _username,string& _password){   //插入函数
    _insert(head,_username,_password);
}

bool AVLTree::query(string& _username){ //查询和验证用户
    if(*_query(head,_username) != NULL)return 1;
    else return 0;
}

int AVLTree::erase(string& _username,string& _password){    //删除函数
    return _erase(head,_username,_password);
}

int AVLTree::update(string& _username,string& _password,string& _newpassword){  //更新密码
    return _update(head,_username,_password,_newpassword);
}

void AVLTree::graph(){
    if(head == NULL){printf("Empty Tree!!\n");return ;}
    int len = (head->username).length();
    if (head->rson){
        _graph(head->rson, false, string(max(len-1,0),' '));
    }
    printf("%s\n",(head->username).c_str());
    if (head->lson){
        _graph(head->lson, true, string(max(len-1,0),' '));
    }
}

void AVLTree::LVR(){ //中序遍历
    _LVR(head);
}

int main(){
    AVLTree T;
    string str[15];
    str[1]="qwq01";str[2]="qwq02";str[3]="qwq03";str[4]="qwq04";str[5]="qwq05";str[6]="qwq06";str[7]="qwq07";
    str[8]="qwq08";str[8]="qwq08";str[9]="qwq09";str[10]="qwq10";str[11]="qwq11";
    for(int i=1;i<=11;i++){
        T.insert(str[i],str[1]);
    }
    T.LVR();

    printf("\n");
    T.graph();

    printf("%d\n",T.erase(str[7],str[1]));
    T.LVR();
    printf("%d\n",T.erase(str[6],str[1]));
    T.LVR();

    printf("\n");
    T.graph();
}