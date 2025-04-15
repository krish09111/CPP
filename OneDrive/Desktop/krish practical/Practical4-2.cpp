#include<iostream>
using namespace std;

class person {
    string name;
    int age;
public:
    person() {}
    person(string a, int b) {
        name = a;
        age = b;
    }
    void display1() {
        cout << "Employee Name : " << name << endl;
        cout << "Employee Age : " << age << endl;
    }
};

class employee : public person {
    int employeeid;
public:
    employee() {}
    employee(string a, int b, int c) : person(a, b) {
        employeeid = c;
    }
    void display2() {
        display1();
        cout << "Employee ID : " << employeeid << endl;
    }
};

class manager : public employee {
    string dept;
public:
    manager() {}
    manager(string a, int c, int d, string b) : employee(a, c, d) {
        dept = b;
    }
    void display() {
        display2();
        cout << "Employee Department : " << dept << endl;
    }
};

int main() {
    int n;
    cout << "Enter number of managers: ";
    cin >> n;

    if (n > 100) {
        cout << "Too many managers. Max allowed is 100." << endl;
        return 1;
    }

    manager m[n];

    for (int i = 0; i < n; i++) {
        string dept, name;
        int age, id;

        cout << "Enter Department, Age, ID, Name for manager " << i + 1 << ": ";
        cin >> dept >> age >> id >> name;

        m[i] = manager(name, age, id, dept);
    }

    cout << "\nManager Details:\n";
    for (int i = 0; i < n; i++) {
        m[i].display();
        cout << endl;
    }

    return 0;
}
