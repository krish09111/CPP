#include <iostream> 
using namespace std; 
 
class Base { 
public: 
      virtual ~Base() { 
        cout << "Base Destructor Called" << endl; 
    } 
}; 
 
class Derived : public Base { 
private: 
    int* resource; 
 
public: 
     
    Derived() { 
        resource = new int[10];  
        cout << "Derived Constructor: Resource Allocated" << endl; 
    } 
 
    
    ~Derived() { 
        delete[] resource; 
        cout << "Derived Destructor: Resource Released" << endl; 
    } 
}; 
 
int main() { 
 
    cout << "Without Virtual Destructor:\n"; 
    Base* basePointer1 = new Derived(); 
    delete basePointer1;   
     
    cout << "\nWith Virtual Destructor:\n"; 
    Base* basePointer2 = new Derived(); 
    delete basePointer2;   
    return 0; 
}