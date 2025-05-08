#include <iostream> 
#include <sstream> 
#include <map> 
using namespace std; 
 
int main() { 
    string sentence; 
    cout << "Enter a sentence: "; 
    getline(cin, sentence); 
    map<string, int> wordFrequency; 
    stringstream ss(sentence); 
    string word; 
    while (ss >> word) { 
        wordFrequency[word]++; 
    } 
    cout << "\nWord Frequencies:\n"; 
    for (const auto& entry : wordFrequency) { 
        cout << entry.first << ": " << entry.second << endl; 
    } 
}