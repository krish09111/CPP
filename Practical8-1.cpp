#include <iostream> 
#include <vector> 
#include <algorithm> 
using namespace std; 
 
int main() { 
    vector<int> numbers; 
    int n, value; 
    cout << "Enter the number of integers: "; 
    cin >> n; 
    cout << "Enter the integers: "; 
    for (int i = 0; i < n; ++i) { 
        cin >> value; 
        numbers.push_back(value); 
    } 
    cout << "\nOriginal Vector: "; 
    for (const auto& num : numbers) { 
        cout << num << " "; 
    } 
    
    vector<int> reversedNumbers = numbers; 
    reverse(reversedNumbers.begin(), reversedNumbers.end()); 
    cout << "\nReversed Vector (using std::reverse): "; 
    for (const auto& num : reversedNumbers) { 
        cout << num << " "; 
    } 
    
    cout << "\nReversed Vector (manual iterator-based): "; 
    for (auto it = numbers.rbegin(); it != numbers.rend(); ++it) { 
        cout << *it << " "; 
    } 
    return 0; 
} 