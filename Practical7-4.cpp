#include <iostream> 
#include <fstream> 
#include <vector> 
#include <iomanip> 
#include <string> 
#include <algorithm> 
using namespace std; 
 
struct Student { 
    string name; 
    double marks; 
    char grade; 
}; 
 
ostream& tabular(ostream& out) { 
    out << left << setw(15); 
    return out; 
} 
 
int main() { 
    ifstream inputFile("students.txt"); 
    if (!inputFile) { 
        cerr << "Error: Unable to open file." << endl; 
        cout<<"Dhruv Sheth_24DCE133"<<endl; 
        return 1; 
    } 
 
    vector<Student> students; 
    string name; 
    double marks; 
    char grade; 
 
 
    while (inputFile >> name >> marks >> grade) { 
        students.push_back({name, marks, grade}); 
    } 
    inputFile.close(); 
 
    sort(students.begin(), students.end(), [](const Student& a, const Student& 
b) { 
        return a.marks > b.marks; 
    }); 
 
    cout << tabular << "Name" << setw(10) << "Marks" << setw(10) << "Grade" << 
endl; 
    cout << setfill('-') << setw(35) << "-" << setfill(' ') << endl; 
 
    for (const auto& student : students) { 
        cout << tabular << student.name 
             << setw(10) << fixed << setprecision(2) << student.marks 
             << setw(10) << student.grade << endl; 
    } 
    return 0; 
} 