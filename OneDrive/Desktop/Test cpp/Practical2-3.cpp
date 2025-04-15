 #include<iostream>
#include<string>
#include<cmath>
using namespace std;
class BankAccount
{
    private:
    string acc_holdername;
    int acc_number;
    int acc_balance;
    public:
    BankAccount()
    {
        acc_balance=0;
    }


    BankAccount(string name,int accnu,int balance)
    {
        acc_holdername=name;
        acc_number=accnu;
        acc_balance=balance;
    }
    void deposit(int amount)
    {
        cout<<"Enter amount of deposit=";
        cin>>amount;
        acc_balance=acc_balance+amount;
        cout<<"Deposit="<<acc_balance<<endl;
    }
    void withdraw(int amount)
    {
        cout<<"Enter the amount of widthraw=";
        cin>>amount;
        if(amount<=acc_balance)
        {
            acc_balance=acc_balance-amount;
            cout<<"The amount is="<<acc_balance<<endl;
        }
        else
        {


            cout<<"please enter valid amount."<<endl;
        }
    }
    void display()
    {
        cout<<"Account holder="<<acc_holdername<<endl;
        cout<<"Account number="<<acc_number<<endl;
        cout<<"Account balance="<<acc_balance<<endl;
    }
};
int main()
{
    int amount;
    BankAccount a1("PQRS",2345,10000);
    cout << "Account 1 Details:" << endl;
    a1.display();
    cout<<"Account 1:"<<endl;
    a1.deposit(amount);
    cout<<"Account 1:"<<endl;
    a1.withdraw(amount);
    cout<<"ACCOUNT 1:"<<endl;
    a1.display();
    BankAccount a2("ABCD", 12345, 5000);
    cout << "Account 2 Details:" << endl;

a2.display();
cout<<"Account 2:"<<endl;
a2.deposit(amount);
cout<<"Account 2:"<<endl;
a2.withdraw(amount);
cout<<"ACCOUNT 2:"<<endl;
a2.display();

return 0;
}
