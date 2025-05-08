#include <iostream> 
#include <fstream> 
#include <sstream> 
#include <stdexcept> 
using namespace std; 
 
void processFile(const string& filePath) { 
    ifstream inputFile(filePath); 
    if (!inputFile) { 
        throw runtime_error("File not found."); 
    } 
    string line; 
    int lineNumber = 0; 
    cout << "Processing file: " << filePath << endl; 
    while (getline(inputFile, line)) { 
        lineNumber++; 
        stringstream ss(line); 
        string word; 
        while (ss >> word) { 
            try { 
                for (char c : word) { 
                    if (!isdigit(c)) { 
                        throw invalid_argument("Corrupted data: Non-numeric value found."); 
                    } 
                } 
                cout << "Valid number: " << word << endl; 
            } catch (const invalid_argument& e) { 
                cerr << "Error on line " << lineNumber << ": " << e.what() << 
endl; 

            } 
        } 
    } 
    inputFile.close(); 
} 
int main() { 
    string filePath; 
    while (true) { 
        try { 
            cout << "Enter file path: "; 
            cin >> filePath; 
            processFile(filePath); 
            break; 
        } catch (const runtime_error& e) { 
            cerr << "Error: " << e.what() << endl; 
            cout << "try again." << endl; 
        } 
    } 
    return 0; 
} 