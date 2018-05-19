

#include <iostream>
#include<stdio.h>
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
       // cout<<namenum;
        for(int i=1;i<=namenum;i++)
        {
            //cout<<MyATM::name[i]<<endl;
            //cout<<name;
            if(!name.compare(MyATM::name[i]))
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
            if(!code.compare(MyATM::code[point]))
            {
                cout<<"密码正确，登陆成功"<<endl;
            }
            else
            {
                cout<<"密码错误，请重新输入密码"<<endl;
                return 0;
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
    //    cout<<MyATM::name[1]<<MyATM::code[1]<<endl;
        MyATM::money[namenum]=0;
        cout<<"用户注册成功"<<endl;
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
        cout<<"密码修改成功"<<endl;
    }
    
    
};

int MyATM::namenum=0;
string MyATM::name[1000]={"\0"};
string MyATM::code[1000]={"\0"};
int MyATM::money[10000]={0,0};


int main(int argc, const char * argv[])
{
    using namespace std;
    int choice;
    string namein,codein;
    int succeedpoint;
    int outtoout=0;
    while(true)
    {
        outtoout=0;
        cout<<"请选择操作：1.登陆；2.注册用户信息"<<endl;
        cin>>choice;
    if(choice==1)
    {
        while (true)
        {
        if(outtoout!=0)
            break;
        cout<<"请输入账户:";
        cin>>namein;
        cout<<"请输入密码:";
        cin>>codein;
       succeedpoint=MyATM::Judge(namein, codein);//账户在列表中的位置
        if(succeedpoint)
        {
            int choice=0;
            while(choice!=6)
            {
            cout<<"请选择操作：1.存款;2.取款;3.查账;4.转账;5.修改密码;6.退出账户:";
            cin>>choice;
            switch (choice)
                {
                case 1:
                        cout<<"请输入存款数额:";
                        int addmoney;
                        cin>>addmoney;
                        MyATM::Deposit(succeedpoint, addmoney);
                    break;
                case 2:
                        while(true)
                        {
                        cout<<"请输入取款数额";
                        int submoney;
                        cin>>submoney;
                        if(!MyATM::Withdrawal(succeedpoint, submoney))
                            continue;
                        else break;
                        }
                    break;
                case 3:
                        MyATM::Audit(succeedpoint);
                    break;
                case 4:
                        while(true)
                        {
                            cout<<"请输入转账对象：";
                            string transfertarget;
                            cin>>transfertarget;
                            int num2=MyATM::Match(transfertarget);
                            if(!num2)
                            {
                                cout<<"转账对象输入错误，请重新输入"<<endl;
                                continue;
                            }
                            else
                            {
                                while(true)
                                {
                                    cout<<"请输入转账金额:";
                                    int transfermoney;
                                    cin>>transfermoney;
                                    if(!MyATM::Transfer(succeedpoint, num2, transfermoney))
                                        continue;
                                    else
                                        break;
                                }
                            }
                            break;
                        }
                        break;
                case 5:
                    {
                        string newcode;
                        cout<<"请输入新密码:";
                        cin>>newcode;
                        MyATM::ChangeCode(succeedpoint, newcode);
                    }
                        break;
                    case 6:
                    {
                        cout<<"退出"<<endl;
                        outtoout++;
                    }
                        break;
                default:
                        cout<<"选项有误有误，请重新输入"<<endl;
                    break;
                }
            }
        }
        else
            continue;
        }
    }
    else if(choice==2)
    {
        string newname;
        string newcode;
        cout<<"请输入注册用户名:";
        cin>>newname;
        cout<<"请输入用户密码:";
        cin>>newcode;
        MyATM::Creat(newname, newcode);
    }
    else
    {
        cout<<"请重新输入选择"<<endl;
        continue;
    }
    }
    
}
