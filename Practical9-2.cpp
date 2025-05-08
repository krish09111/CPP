#include <iostream> 
#include <stdexcept> 
#include <cmath> 
using namespace std; 
class NegativeNumberException : public exception { 
public: 
    const char* what() const noexcept override { 
        return "Square root of negative number is not complex."; 
    } 
}; 
double calculateSquareRoot(double number) { 
    if (number < 0) { 
        throw NegativeNumberException(); 
    } 
    return sqrt(number); 
} 
int main() { 
    try { 
        double number; 
        cout << "Enter number: "; 
        cin >> number; 
        double result = calculateSquareRoot(number); 
        cout << "Square root: " << result << endl; 
    } catch (const NegativeNumberException& e) { 
        cerr << "Error: " << e.what() << endl; 
    } catch (const exception& e) { 
        cerr << "Error: " << e.what() << endl; 
    } 
 
    return 0; 
} 