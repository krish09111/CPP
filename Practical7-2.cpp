#include <iostream> 
#include <fstream> 
#include <vector> 
#include <string> 
#include <sstream> 
using namespace std; 
int main() { 
    ifstream inputFile("students.txt"); 
    if (!inputFile) { 
        cerr << "Error: Unable to open file." << endl; 
        cout<<"Dhruv Sheth_24DCE133"<<endl; 
        return 1; 
    } 
    vector<string> lines; 
    string line; 
    int totalCharacters = 0, totalWords = 0, totalLines = 0; 
    while (getline(inputFile, line)) { 
        lines.push_back(line); 
        totalLines++; 
        totalCharacters += line.size(); 
        stringstream ss(line); 
        string word; 
        while (ss >> word) { 
            totalWords++; 
        } 
    } 
    inputFile.close(); 
    cout << "Total Lines: " << totalLines << endl; 
    cout << "Total Words: " << totalWords << endl; 
    cout << "Total Characters: " << totalCharacters << endl; 
    return 0; 
} 