#include <iostream> 
using namespace std; 
 
class DynamicArray { 
private: 
    int* array; 
    int capacity; 
    int size; 
 
public: 
    DynamicArray() : capacity(1), size(0) { 
        array = new int[capacity]; 
    } 
 
    ~DynamicArray() { 
        delete[] array; 
    } 
 
    void insert(int value) { 
        if (size == capacity) { 
            // Double the capacity 
            capacity *= 2; 
            int* newArray = new int[capacity]; 
 
            // Copy old elements to new array 
            for (int i = 0; i < size; i++) { 
                newArray[i] = array[i]; 
            } 
 
            delete[] array;  // Free old array memory 
            array = newArray; 
        } 
 
        array[size++] = value; 
    } 
 
    void remove(int position) { 
        if (position < 0 || position >= size) { 
 
            cout << "Invalid position!\n"; 
            return; 
        } 
 
        for (int i = position; i < size - 1; i++) { 
            array[i] = array[i + 1]; 
        } 
 
        size--; 
    } 
 
    void print() const { 
        for (int i = 0; i < size; i++) { 
            cout << array[i] << " "; 
        } 
        cout << endl; 
    } 
}; 
 
int main() { 
    DynamicArray arr; 
 
    arr.insert(10); 
    arr.insert(20); 
    arr.insert(30); 
    arr.print();   
    arr.remove(1);  
    arr.print();   
    arr.insert(40); 
    arr.print();  
}