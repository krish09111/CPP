#include <iostream>
#include <string>
using namespace std;


class Student {
protected:
    string name;
    float marks;
public:
    Student(string n, float m) : name(n), marks(m) {}
    virtual ~Student() {}

    virtual string computeGrade() = 0;

    void display() {
        cout << "Student Name: " << name << endl;
        cout << "Marks: " << marks << endl;
        cout << "Grade: " << computeGrade() << endl;
    }
};


class Undergraduate : public Student {
public:
    Undergraduate(string n, float m) : Student(n, m) {}

    string computeGrade() override {
        if (marks >= 85) return "A";
        else if (marks >= 70) return "B";
        else if (marks >= 50) return "C";
        else return "F";
    }
};


class Postgraduate : public Student {
public:
    Postgraduate(string n, float m) : Student(n, m) {}

    string computeGrade() override {
        if (marks >= 90) return "A";
        else if (marks >= 75) return "B";
        else if (marks >= 60) return "C";
        else return "F";
    }
};


int main() {
    int numStudents;

    cout << "Enter the number of students: ";
    cin >> numStudents;


    Student* students[100];

    for (int i = 0; i < numStudents; ++i) {
        string name;
        float marks;
        int level;

        cout << "Enter the student's name: ";
        cin >> name;

        cout << "Enter the student's marks: ";
        cin >> marks;

        cout << "Enter student level : ";
        cin >> level;


        if (level == 1) {
            students[i] = new Undergraduate(name, marks);
        } else if (level == 2) {
            students[i] = new Postgraduate(name, marks);
        } else {
            cout << "Invalid " << endl;
            --i;
            continue;
        }
    }


    for (int i = 0; i < numStudents; ++i) {
        students[i]->display();

    }


    for (int i = 0; i < numStudents; ++i) {
        delete students[i];
    }

    return 0;
}

