/*
    叶璇@201806060825    
*/  
#include<string>
#include<fstream>
using namespace std;
class node{
public:
    string username,password; //数据的储存
    int deep = 1;   //树高
    node* lson = NULL;node* rson = NULL;    //左儿子右儿子
    node(const string& _username,const string& _password); 
    bool operator < (const node& b)const;
};

class AVLTree{
private:
    // data
    node* head = NULL;
    // function
    int getDeep(node*& rt);  //获得树高
    int deltaDeep(node*& rt);    //左子树高减右子树高
    void updateDeep(node*& rt);  //更新树高
    void L(node*& rt); //左旋
    void R(node*& rt); //右旋
    int _insert(node*& rt,string& _username,string& _password); //插入的辅助函数
    node** _query(node*& rt,string& _username);  //查询和验证用户辅助函数
    int _erase(node*& rt,string& _username,string& _password); //删除的辅助函数
    int _update(node*& rt,string& _username,string& _password,string& _newpassword);    //更新密码辅助函数  
    void _graph(node*& rt,bool flag,const string& str);  //图形化辅助函数
    void _AVL(node*& rt);    // 平衡操作
    void _LVR(node*& rt);// 中序遍历
    void _release(node*& rt); //清空缓存辅助函数
    void _output(node*& rt,ofstream& out);    //导出文件辅助函数

public:
    AVLTree();   //构造函数
    ~AVLTree();  //析构函数
    int insert(string& _username,string& _password); //插入函数
    int login(string& _username,string& _password);   //登陆操作
    bool query(string& _username);  //登陆操作
    int erase(string& _username,string& _password);   //删除函数
    int update(string& _username,string& _password,string& _newpassword);  //更新密码
    void graph();  //图形化展示 
    void LVR(); //中序遍历
    void clear();   //清空二叉树
    void input(string& _filename); //从文件中导入
    void output(string& _filename); //导出文件
    void menu();    //菜单
    void temp();    
};  