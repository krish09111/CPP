#include<iostream>
using namespace std;

class Bankaccount {
    string name;
    int accnum;
    float balance;

    static int totalaccount;

public:
    Bankaccount() {}

    Bankaccount(string a, int b, float c) {
        name = a;
        accnum = b;
        balance = c;
        totalaccount++;
    }

    void deposit(float x) {
        balance += x;
    }

    int withdraw(float y) {
        if (balance >= y) {
            balance -= y;
            return 1;
        } else {
            cout << "Not to withdraw." << endl;
            return 0;
        }
    }

    void display() {
        cout << "Account Holder Name : " << name << endl;
        cout << "Account Number : " << accnum << endl;
        cout << "Total Balance : " << balance << endl;
    }

    int getAccountNumber() {
        return accnum;
    }

    static int display1() {
        return totalaccount;
    }

    friend void transfer(Bankaccount &s, Bankaccount &r, float amount);
};

int Bankaccount::totalaccount = 0;

void transfer(Bankaccount &s, Bankaccount &r, float amount) {
    if (s.withdraw(amount))
        r.deposit(amount);
    else
        cout << "Not sufficient balance to transfer." << endl;
}

int main() {
    Bankaccount x[100];
    int n;
    cout << "Enter Number Of Accounts: ";
    cin >> n;

    int a;
    string b;
    float c;

    for (int i = 0; i < n; i++) {
        cout << "Enter Account Number, Name, and Initial Balance: ";
        cin >> a >> b >> c;
        x[i] = Bankaccount(b, a, c);
    }

    cout << "\n-- Account Details --\n";
    for (int i = 0; i < n; i++) {
        x[i].display();
    }

    int f, t;
    float amount;
    cout << "\nEnter bank account number to transfer FROM: ";
    cin >> f;
    cout << "Enter bank account number to transfer TO: ";
    cin >> t;
    cout << "Enter amount to transfer: ";
    cin >> amount;

    Bankaccount *from = nullptr, *to = nullptr;
    for (int i = 0; i < n; i++) {
        if (x[i].getAccountNumber() == f)
            from = &x[i];
        if (x[i].getAccountNumber() == t)
            to = &x[i];
    }

    if (from && to) {
        transfer(*from, *to, amount);
    } else {
        cout << "Invalid account number(s)!" << endl;
    }

    cout << "\n-- Updated Account Details --\n";
    for (int i = 0; i < n; i++) {
        x[i].display();
    }

    cout << "Total Number of Accounts: " << Bankaccount::display1() << endl;

    return 0;
}

