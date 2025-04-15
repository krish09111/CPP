#include<iostream>
using namespace std;


template <typename T>
void display(T arr[], int size) {
    for (int i = 0; i < size; ++i)
        cout << arr[i] << endl;
}


template <typename T>
T max1(T arr[], int size) {
    T maxVal = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > maxVal)
            maxVal = arr[i];
    }
    return maxVal;
}


template <typename T>
void rev(T arr[], int size) {
    for (int i = 0; i < size / 2; ++i) {
        T temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
    display(arr, size);
}

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;


    int intArr[100];
    cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; ++i)
        cin >> intArr[i];

    display(intArr, n);
    cout << "Max element: " << max1(intArr, n) << endl;
    rev(intArr, n);


    float floatArr[100];
    cout << "Enter " << n << " floats:\n";
    for (int i = 0; i < n; ++i)
        cin >> floatArr[i];

    display(floatArr, n);
    cout << "Max element: " << max1(floatArr, n) << endl;
    rev(floatArr, n);


    char charArr[100];
    cout << "Enter " << n << " characters:\n";
    for (int i = 0; i < n; ++i)
        cin >> charArr[i];

    display(charArr, n);
    cout << "Max element: " << max1(charArr, n) << endl;
    rev(charArr, n);

    return 0;
}

