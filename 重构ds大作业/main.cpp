#include "AVLTree.h"
#include <iostream>
int main(){
    AVLTree ex;
    string filename;int opp;
    string username,password,newpassword;
    int flag;
    string op;
    while(1){
        ex.menu();
        cin>>op;
        if(op.length()>2){
            system("cls"); 
            continue;
        }
        opp = 0;
        for(int i=0;i<op.length();i++){
            opp *= 10;
            opp += op[i]-'0';
        }
        bool flag_while = 0;
        switch(opp){
            case 1:printf("What's the file's name?:");cin>>filename;system("cls");ex.input(filename);
                break;

            case 2:printf("What's the file's name?:");cin>>filename;system("cls");ex.output(filename);
                break;

            case 3:printf("What's your username?:");cin>>username;printf("What's your password?:");cin>>password;system("cls");
                if(ex.insert(username,password))printf("Successful!\n");
                else printf("Already same username!\n");
                break;

            case 4:printf("What's your username?:");cin>>username;printf("What's your password?:");cin>>password;system("cls");
                flag = ex.login(username,password);
                if(flag == 1)printf("Successful!\n");
                else if(flag == 0)printf("Cannot find the username!\n");
                else printf("Wrong password!\n");
                break;

            case 5:printf("What's your username?:");cin>>username;system("cls");
                if(ex.query(username))printf("Your are alive!\n");
                else printf("Cannot find the username!\n");
                break;

            case 6:printf("What's your username?:");cin>>username;printf("What's your password?:");cin>>password;system("cls");
                flag = ex.erase(username,password);
                if(flag == 1)printf("Successful!\n");
                else if(flag == 0)printf("Cannot find the username!\n");
                else printf("Wrong password!\n");
                break;

            case 7:printf("What's your username?:");cin>>username;printf("What's your password?:");cin>>password;printf("What's your new password?:");cin>>newpassword;system("cls");
                flag = ex.update(username,password,newpassword);
                if(flag == 1)printf("Successful!\n");
                else if(flag == 0)printf("Cannot find the username!\n");
                else printf("Wrong password!\n");
                break;

            case 8:system("cls");ex.graph();
                break;

            case 9:system("cls");ex.LVR();
                break;

            case 10:system("cls");ex.clear();
                break;

            case 11:flag_while = 1;break;

            case 12:ex.temp();break;
            default:system("cls");printf("Unknowed Operation!\n");
        }
        if(flag_while)break;
    }
}