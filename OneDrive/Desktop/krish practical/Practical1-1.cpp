#include<iostream>
using namespace std;

class BanckAccount

{
    private:
    string acc_holdername;
    int acc_number;
    int acc_balance;
    public:
    void details()
    {
        cout<<"Account holder name=";
        cin>>acc_holdername;
        cout<<"Account number=";
        cin>>acc_number;
        cout<<"Account balance=";
        cin>>acc_balance;
    }
    void deposit(float amount)
    {
        cout<<"Enter the deposit=";
        cin>>amount;
        acc_balance=acc_balance+amount;
        cout<<"The Total amount is="<<acc_balance<<endl;




    }
    void withdraw(float amount)
    {
        cout<<"Enter the withdraw=";
        cin>>amount;
        if(amount>=acc_balance)
        {
            cout<<"error";
        }
        else
        {
            acc_balance=acc_balance-amount;
            cout<<"The Total amount is="<<acc_balance<<endl;
        }
    }
    void display()
    {
        cout<<"Account holder name="<<acc_holdername<<endl;

        cout<<"Account number="<<acc_number<<endl;

        cout<<"Account balance="<<acc_balance<<endl;

    }
};
int main()
{
    float amount;
    BanckAccount p1;
    p1.details();
    p1.deposit(amount);
    p1.withdraw(amount);
    p1.display();

    return 0;
}
