#include <iostream> 
#include <queue> 
using namespace std; 
class Fahrenheit; 
class Celsius { 
    float temp; 
public: 
    Celsius(float t = 0) : temp(t) {} 
    operator Fahrenheit(); 
    bool operator==(const Celsius& other) const { 
        return temp == other.temp; 
    } 
    void display() const { 
        cout << temp << " C"; 
    } 
}; 
class Fahrenheit { 
    float temp; 
public: 
    Fahrenheit(float t = 0) : temp(t) {} 
    operator Celsius() { 
        return Celsius((temp - 32) * 5 / 9); 
    } 
 
    bool operator==(const Fahrenheit& other) const { 
        return temp == other.temp; 
    } 
 
    void display() const { 
        cout << temp << " F"; 
 
    } 
}; 
Celsius::operator Fahrenheit() { 
    return Fahrenheit((temp * 9 / 5) + 32); 
} 
 
int main() { 
    Celsius c1(25); 
    Fahrenheit f1 = c1;  
    Celsius c2 = f1;    
 
    cout << "Celsius to Fahrenheit: "; 
    c1.display(); 
    cout << " = "; 
    f1.display(); 
    cout << endl; 
 
    cout << "Fahrenheit to Celsius: "; 
    f1.display(); 
    cout << " = "; 
    c2.display(); 
    cout << endl; 
    if (c1 == c2) { 
        cout << "Temperatures are equal." << endl; 
    } else { 
        cout << "Temperatures are not equal." << endl; 
    } 
 
    
    queue<Fahrenheit> tempQueue; 
    tempQueue.push(f1); 
    tempQueue.push(Fahrenheit(98.6)); 
 
    cout << "\nTemperatures in queue (FIFO):" << endl; 
    while (!tempQueue.empty()) { 
        Fahrenheit temp = tempQueue.front(); 
        temp.display(); 
        cout << endl; 
        tempQueue.pop(); 
    } 
    return 0; 
} 