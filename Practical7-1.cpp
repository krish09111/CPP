#include <iostream> 
#include <sstream> 
#include <map> 
#include <algorithm> 
using namespace std; 
int main() { 
    string paragraph; 
    cout << "Enter a paragraph: "; 
    getline(cin, paragraph); 
    transform(paragraph.begin(), paragraph.end(), paragraph.begin(), 
::tolower); 
    stringstream ss(paragraph); 
    string word; 
    map<string, int> wordFrequency; 
    while (ss >> word) { 
        wordFrequency[word]++; 
    } 
    cout << "\nWord Frequencies:\n"; 
    for (const auto& entry : wordFrequency) { 
        cout << entry.first << ": " << entry.second << endl; 
    } 
    return 0; 
} 