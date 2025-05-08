#include <iostream> 
#include <stdexcept> 
using namespace std; 
 
int main() { 
    try { 
        float a, b; 
        cout << "Enter two integers (numerator and denominator): "; 
        if (!(cin >> a >> b)) { 
            throw invalid_argument("Invalid input. Please enter integers only."); 
        } 
        if (b == 0) { 
            throw runtime_error("Division by zero is not allowed."); 
        } 
        cout << "Result: " << a / b << endl; 
    } catch (const exception& e) { 
        cerr << "Error: " << e.what() << endl; 
    } 
    return 0; 
} 