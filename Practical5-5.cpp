#include <iostream> 
#include <vector> 
#include <memory> 
using namespace std; 
 
class Shape { 
public: 
    virtual double Area() const = 0; 
    virtual ~Shape() {} 
}; 
class Rectangle : public Shape { 
    double length, width; 
public: 
    Rectangle(double l, double w) : length(l), width(w) {} 
 
    double Area() const override { 
        return length * width; 
    } 
}; 
class Circle : public Shape { 
    double radius; 
 

public: 
    Circle(double r) : radius(r) {} 
 
    double Area() const override { 
        return 3.14159 * radius * radius; 
    } 
}; 
 
int main() { 
    vector<shared_ptr<Shape>> shapes; 
    shapes.push_back(make_shared<Rectangle>(5.0, 3.0)); 
    shapes.push_back(make_shared<Circle>(4.0)); 
    cout << "Areas of shapes:\n"; 
    for (const auto& shape : shapes) { 
        cout << shape->Area() << endl; 
    } 
    return 0; 
} 