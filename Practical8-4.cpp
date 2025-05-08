#include <iostream> 
#include <vector> 
#include <string> 
#include <algorithm> 
using namespace std; 
 
int main() { 
    vector<pair<string, int>> students; 
    int n; 
    string name; 
    int score; 
 
    cout << "Enter number of students: "; 
    cin >> n; 

 
    for (int i = 0; i < n; ++i) { 
        cout << "Enter name of student " << i + 1 << ": "; 
        cin >> name; 
        cout << "Enter score of student " << i + 1 << ": "; 
        cin >> score; 
        students.push_back(make_pair(name, score)); 
    } 
 
    sort(students.begin(), students.end(), [](const pair<string, int>& a, 
const pair<string, int>& b) { 
        return a.second > b.second; 
    }); 
 
    cout << "\nSorted Students by Scores (Descending):\n"; 
    for (const auto& student : students) { 
        cout << student.first << ": " << student.second << endl; 
    } 
    return 0; 
}