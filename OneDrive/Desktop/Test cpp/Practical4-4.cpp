#include<iostream>
using namespace std;

class bankaccount {
protected:
    int accnum;
    float balance;
public:
    bankaccount() {}
    bankaccount(int a, float b) {
        accnum = a;
        balance = b;
    }
    void deposit(float amount) {
        balance += amount;
        cout << "Balance: " << balance << endl;
        cout << "Deposit Completed." << endl;
    }
    void withdraw(float amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Balance: " << balance << endl;
            cout << "Withdraw Completed." << endl;
        }
        else {
            cout << "Insufficient Balance to withdraw." << endl;
        }
    }
};

class saving : public bankaccount {
    float interest;
public:
    saving() {}
    saving(int a, float b, float c) : bankaccount(a, b) {
        cout << "Saving account created." << endl;
        interest = c;
    }
    ~saving() {
        cout << "Saving account closed." << endl;
    }
    void display() {
        cout << "Saving account details:" << endl;
        cout << "Account Number: " << accnum << endl;
        cout << "Account Balance: " << balance << endl;
        cout << "Interest Rate: " << interest << "%" << endl;
    }
};

class current : public bankaccount {
    float overdraft;
public:
    current() {}
    current(int a, float b, float c) : bankaccount(a, b) {
        cout << "Current account created." << endl;
        overdraft = c;
    }
    ~current() {
        cout << "Current account closed." << endl;
    }
    void withdraw1(float amount) {
        if (balance + overdraft >= amount) {
            balance -= amount;
            cout << "Withdraw Completed." << endl;
            cout << "Balance: " << balance << endl;
        }
        else {
            cout << "Insufficient funds. Overdraft limit reached." << endl;
        }
    }
    void display() {
        cout << "Current account details:" << endl;
        cout << "Account Number: " << accnum << endl;
        cout << "Account Balance: " << balance << endl;
        cout << "Overdraft Limit: " << overdraft << endl;
    }
};

int main() {

    saving s(101, 2540, 5);
    current c(102, 5600, 500);


    s.deposit(5000);
    cout << "Transaction: Deposit 5000 to saving account" << endl;

    s.withdraw(560);
    cout << "Transaction: Withdraw 560 from saving account" << endl;

    c.deposit(5000);
    cout << "Transaction: Deposit 5000 to current account" << endl;

    c.withdraw1(6000);
    cout << "Transaction: Withdraw 6000 from current account" << endl;


    s.display();
    c.display();

    return 0;
}
