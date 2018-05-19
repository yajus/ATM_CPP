//
//  ATMMod.cpp
//  实验四—ATM
//
//  Created by apple on 2018/4/19.
//  Copyright © 2018年 apple. All rights reserved.
//

#include<iostream>
using namespace std;
class MyATM
{
private:
    static string name[1000];
private:
    static string code[1000];
private:
    static int money[10000];
private:
    static int namenum;
public:
    static int Match(string name)
    {
        int point=0;
        for(int i=1;i<=namenum;i++)
        {
            if(name.compare(MyATM::name[i]))
               {
               point=i;
                   break;
               }
        }
        return point;
    }
public:
    static int Judge(string name,string code)
    {
        int point=Match(name);
        if(!point)
        {
            cout<<"输出名字错误请重新输入"<<endl;
        }
        else
        {
            if(code.compare(MyATM::code[point]))
            {
                cout<<"密码正确，登陆成功"<<endl;
            }
            else
            {
                cout<<"密码错误，请重新输入密码"<<endl;
            }
        }
        return point;
    }
public:
    static void Creat(string name,string code)
    {
    namenum++;
    MyATM::name[namenum].assign(name);
    MyATM::code[namenum].assign(code);
    MyATM::money[namenum]=0;
        cout<<"用户注册成功";
    }
public:
    static void Deposit(int num,int addmoney)
    {
        MyATM::money[num]+=addmoney;
        cout<<"存入成功，"<<"存入金额："<<addmoney<<" 账户余额为："<<MyATM::money[num]<<endl;
    }
public:
    static bool Withdrawal(int num,int submoney)
    {
        if(submoney>MyATM::money[num])
        {
            cout<<"账户余额不足"<<endl;
            return false;
        }
        else
        {
            MyATM::money[num]-=submoney;
            cout<<"取款成功，"<<"取出金额："<<submoney<<" 账户余额为："<<MyATM::money[num]<<endl;
            return true;
        }
    }
public:
    static void Audit(int num)
    {
        cout<<"账户余额为："<<MyATM::money[num]<<endl;
    }
public:
    static bool Transfer(int num1,int num2,int transfermoney)
    {
        if(transfermoney>MyATM::money[num1])
        {
            cout<<"账户余额不足，转账失败"<<endl;
            return false;
        }
        else
        {
        MyATM::money[num1]-=transfermoney;
        MyATM::money[num2]+=transfermoney;
        cout<<"用户："<<MyATM::name[num1]<<"  成功转账金额："<<transfermoney<<"给用户："<<MyATM::name[num2]<<endl;
            return true;
        }
    }
public:
    static void ChangeCode(int num,string changecode)
    {
        MyATM::code[num].assign(changecode);
    }
    
    
};

int MyATM::namenum=0;
string MyATM::name[1000]={"\0"};
string MyATM::code[1000]={"\0"};
int MyATM::money[10000]={0,0};
