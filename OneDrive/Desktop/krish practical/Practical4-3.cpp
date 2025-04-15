#include<iostream>
using namespace std;

class fuel {
protected:
    string fueltype;
public:
    fuel() {}
    fuel(string a) {
        fueltype = a;
    }
};

class brand {
protected:
    string brandname;
public:
    brand() {}
    brand(string a) {
        brandname = a;
    }
};

class car : public fuel, public brand {
public:
    car() {}
    car(string a, string b) : fuel(a), brand(b) {}

    void display() {
        cout << "Brand Name Of Car : " << brandname << endl;
        cout << "Fuel Type Of Car : " << fueltype << endl;
    }
};

int main() {
    int n;
    cin >> n;


    car cars[n];


    for (int i = 0; i < n; i++) {
        string a, b;
        cin >> a >> b;
        cars[i] = car(a, b);
    }


    for (int i = 0; i < n; i++) {
        cars[i].display();
    }

    return 0;
}

