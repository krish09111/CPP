#include <iostream> 
using namespace std; 
 
class Complex { 
private: 
    double real, imag; 
 
public: 
    Complex(double r = 0, double i = 0) : real(r), imag(i) {} 
 
    Complex operator+(const Complex& other) const { 
        return Complex(real + other.real, imag + other.imag); 
    } 
 
    Complex operator-(const Complex& other) const { 
        return Complex(real - other.real, imag - other.imag); 
    } 
 
    friend ostream& operator<<(ostream& os, const Complex& c) { 
        os << c.real << " + " << c.imag << "i"; 
        return os; 
    } 
 
    friend istream& operator>>(istream& is, Complex& c) { 
        is >> c.real >> c.imag; 
        return is; 
    } 
}; 
 
int main() { 
    Complex c1, c2; 
    cin >> c1 >> c2; 
 
    cout << "Sum: " << c1 + c2 << endl; 
    cout << "Difference: " << c1 - c2 << endl; 
    return 0; 
} 