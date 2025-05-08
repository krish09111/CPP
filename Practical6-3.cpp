#include <iostream> 
using namespace std; 
 
void mergeArrays(int* arr1, int n, int* arr2, int m, int* merged) { 
    int i = 0, j = 0, k = 0; 
 
    while (i < n && j < m) { 
        if (arr1[i] <= arr2[j]) { 
            merged[k++] = arr1[i++]; 
        } else { 
            merged[k++] = arr2[j++]; 
        } 
    } 
 
    while (i < n) { 
        merged[k++] = arr1[i++]; 
    } 
 
    while (j < m) { 
        merged[k++] = arr2[j++]; 
    } 
} 
 
int main() { 
    int n, m; 
     
    cout << "Enter sizes of the two arrays (n m): "; 
    cin >> n >> m; 
 
    int* arr1 = new int[n]; 
    int* arr2 = new int[m]; 
    int* merged = new int[n + m]; 
 
    cout << "Enter elements of the first sorted array: "; 
    for (int i = 0; i < n; i++) { 
                                                               
        cin >> arr1[i]; 
    } 
 
    cout << "Enter elements of the second sorted array: "; 
    for (int i = 0; i < m; i++) { 
        cin >> arr2[i]; 
    } 
 
    mergeArrays(arr1, n, arr2, m, merged); 
 
    cout << "Merged sorted array: "; 
    for (int i = 0; i < n + m; i++) { 
        cout << merged[i] << " "; 
    } 
    cout << endl; 
 
    delete[] arr1; 
    delete[] arr2; 
    delete[] merged; 
    return 0; 
} 