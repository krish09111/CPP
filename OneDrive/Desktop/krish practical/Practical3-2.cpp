#include<iostream>
#include<chrono>
using namespace std;

int iteration(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

int recursion(int arr[], int x) {
    if (x < 0)
        return 0;
    else
        return arr[x] + recursion(arr, x - 1);
}

int main() {
    int n;
    cout << "Enter size of array: " << endl;
    cin >> n;

    int arr[1000];

    if (n > 1000) {
        cout << "Array size too large!" << endl;
        return 1;
    }

    cout << "Enter elements of the array: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    auto s1 = chrono::high_resolution_clock::now();
    cout << "Sum of elements using iteration: " << iteration(arr, n) << endl;
    auto e1 = chrono::high_resolution_clock::now();
    auto v = e1 - s1;
    cout << "Iteration time (ns): " << v.count() << endl;

    auto s2 = chrono::high_resolution_clock::now();
    cout << "Sum of elements using recursion: " << recursion(arr, n - 1) << endl;
    auto e2 = chrono::high_resolution_clock::now();
    auto y = e2 - s2;
    cout << "Recursion time (ns): " << y.count() << endl;

    return 0;
}

