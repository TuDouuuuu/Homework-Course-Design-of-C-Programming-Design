#ifndef ACCOUNTLIST
#define ACCOUNTLIST
#include"account.h"
class Node{
public:
	Account& acnt;
	Node *next,*prev;
	Node(Account& a):acnt(a),next(0),prev(0){}
	bool operator==(const Node& n)const{return acnt==n.acnt;}
};
class AccountList{
	int size;
	Node *first;
public:
	AccountList():first(0),size(0){}
	~AccountList();
	Node* getFirst()const{return first;}
	int getSize()const{return size;}
	void add(Account& a);
	void remove(string acntNo);
	Account* find(string acntNo)const;
	bool isEmpty()const{return !size;}
	void display()const;
	
};
#endif