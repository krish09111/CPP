#include <iostream> 
#include <vector> 
using namespace std; 
 
class Calculator { 
public: 
    int add(int a, int b) { 
        return a + b; 
    } 
 
    double add(double a, double b) { 
        return a + b; 
    } 
 
    int add(int a, int b, int c) { 
        return a + b + c; 
    } 
 
    double add(double a, double b, double c) { 
        return a + b + c; 
    } 
}; 
 
class ResultManager { 
private: 
    vector<double> results; 
public: 
    void storeResult(double result) { 
        results.push_back(result); 
    } 
 
    void displayResults() const { 
 
        cout << "Stored Results:" << endl; 
        for (double res : results) { 
            cout << res << endl; 
        } 
    } 
}; 
 
int main() { 
    Calculator calc; 
    ResultManager manager; 
 
    double res1 = calc.add(5, 3); 
    double res2 = calc.add(4.2, 3.8); 
    double res3 = calc.add(2, 3, 4); 
    double res4 = calc.add(1.1, 2.2, 3.3); 
 
    manager.storeResult(res1); 
    manager.storeResult(res2); 
    manager.storeResult(res3); 
    manager.storeResult(res4); 
 
    manager.displayResults(); 
    return 0; 
} 