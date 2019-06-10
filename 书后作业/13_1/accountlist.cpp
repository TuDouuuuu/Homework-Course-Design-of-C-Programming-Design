#include<iostream>
using std::cout;
#include"accountlist.h"
void AccountList::add(Account &a){
	Node* pN=new Node(a);
	if(first){
		pN->next=first;
		first->prev=pN;
	}
	first=pN;size++;
}
void AccountList::remove(string acntNo){
	for(Node* p=first;p;p=p->next)
		if(p->acnt.getAcntNo()==acntNo){
			if(p->prev)p->prev->next=p->next;
			if(p->next)p->next->prev=p->prev;
			if(p==first)first=p->next;
			delete p;
			size--;
			break;
		}
}
Account* AccountList::find(string acntNo)const{
	for(Node* p=first;p;p=p->next)
		if(p->acnt.getAcntNo()==acntNo)
			return &(p->acnt);
	return 0;
}
void AccountList::display()const{
	std::cout<<"There are "<<size<<" accounts.\n";
	for(Node* p=first;p;p=p->next)
		(p->acnt).display();
}
AccountList::~AccountList(){
	for(Node* p=first;p=first;delete p)
		first=first->next;
}