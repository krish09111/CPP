#include<iostream> 
using namespace std; 
 
class point 
{ 
    int x,y; 
    public: 
    point(int x,int y){ 
        this->x=x; 
        this->y=y; 
    } 
    point &move(int dx,int dy){ 
        this->x+=dx; 
        this->y+=dy; 
        return *this; 
    } 
    void display(){ 
        cout<<"x:"<<x<<"\t"<<"y:"<<y<<endl; 
    } 
    void update(point* p) { 
        if (p) { 
            x = p->x; 
            y = p->y; 
        } 
    } 
  
}; 
 
int main() 
{ 
    point p(1,2); 
    p.move(2, 3).move(-1, 4).display(); 
 
    point p2(10, 20); 
    p.update(&p2); 
    p.display(); 
  return 0; 
} 