#include<iostream>
using namespace std;

class shape {
protected:
    float radius;
public:
    shape() {}
    shape(float a) {
        radius = a;
    }
};

class circle : public shape {
public:
    circle() {}
    circle(float r) : shape(r) {}

    float calculatearea() {
        return (3.14 * radius * radius);
    }
};

int main() {
    int n;
    cout << "enter size : " << endl;
    cin >> n;

    circle circles[50];
    if (n > 50) {
        cout << " Many circles." << endl;
        return 1;
    }

    for (int i = 0; i < n; i++) {
        float x;
        cin >> x;
        circles[i] = circle(x);
    }

    for (int i = 0; i < n; i++) {
        cout << circles[i].calculatearea() << endl;
    }

    return 0;
}
