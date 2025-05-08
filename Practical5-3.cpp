#include <iostream> 
#include <stack> 
using namespace std; 
 
class Point { 
    int x, y; 
 
public: 
    Point(int x = 0, int y = 0) : x(x), y(y) {} 
    Point operator-() const { 
        return Point(-x, -y); 
    } 
 
    Point operator+(const Point& other) const { 
        return Point(x + other.x, y + other.y); 
    } 
    bool operator==(const Point& other) const { 
        return x == other.x && y == other.y; 
    } 
    void display() const { 
        std::cout << "(" << x << ", " << y << ")"; 
    } 
}; 
 
class PointStack { 
    std::stack<Point> stack; 
public: 
    void push(const Point& point) { 
        stack.push(point); 
    } 
    Point pop() { 

        if (stack.empty()) { 
            throw std::out_of_range("Stack is empty"); 
        } 
        Point top = stack.top(); 
        stack.pop(); 
        return top; 
    } 
    bool isEmpty() const { 
        return stack.empty(); 
    } 
}; 
 
int main() { 
    Point p1(3, 4), p2(1, 2); 
    
    Point p3 = p1 + p2; 
    Point p4 = -p1; 
    std::cout << "Point p1: "; 
    p1.display(); 
    std::cout << "\nPoint p2: "; 
    p2.display(); 
    std::cout << "\nPoint p3 (p1 + p2): "; 
    p3.display(); 
    std::cout << "\nPoint p4 (-p1): "; 
    p4.display(); 
     
    PointStack stack; 
    stack.push(p1); 
    stack.push(p2); 
 
    std::cout << "\n\nPopped points from stack:\n"; 
    while (!stack.isEmpty()) { 
        Point p = stack.pop(); 
        p.display(); 
        std::cout << "\n"; 
    } 
    return 0; 
} 