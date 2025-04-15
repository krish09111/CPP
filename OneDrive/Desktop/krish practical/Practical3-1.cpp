#include<iostream>
using namespace std;

class Employee {
    string name;
    float salary, bonus;

public:
    Employee() {}

    Employee(string a, float b, float c = 7000) {
        name = a;
        salary = b;
        bonus = c;
    }

    inline float calculatesalary() {
        return salary + bonus;
    }

    void display() {
        cout << "Employee Name : " << name << endl;
        cout << "Total Salary : " << calculatesalary() << endl;
        cout << "Bonus : " << bonus << endl;
    }
};

int main() {
    Employee a[2];


    a[0] = Employee("Kohli", 11500);
    a[1] = Employee("Rohit", 5600, 500);

    for (int i = 0; i < 2; i++) {
        a[i].display();
    }

    return 0;
}

