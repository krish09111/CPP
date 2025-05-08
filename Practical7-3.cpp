#include <iostream> 
#include <fstream> 
#include <vector> 
#include <string> 
#include <algorithm> 
using namespace std; 
 
struct Item { 
    string name; 
    int quantity; 
    double price; 
}; 
 
void addItem(const string& filename) { 
    ofstream outputFile(filename, ios::app); 
    if (!outputFile) { 
        cerr << "Error: Unable to open file." << endl; 
        return; 
    } 
    Item item; 
    cout << "Enter item name: "; 
    cin >> item.name; 
    cout << "Enter item quantity: "; 
 
    cin >> item.quantity; 
    cout << "Enter item price: "; 
    cin >> item.price; 
    outputFile << item.name << " " << item.quantity << " " << item.price << 
endl; 
    outputFile.close(); 
    cout << "Item added successfully!" << endl; 
} 
 
void viewItems(const string& filename) { 
    ifstream inputFile(filename); 
    if (!inputFile) { 
        cerr << "Error: Unable to open file." << endl; 
        return; 
    } 
    cout << "\nInventory Items:\n"; 
    cout << "Name\tQuantity\tPrice\n"; 
    Item item; 
    while (inputFile >> item.name >> item.quantity >> item.price) { 
        cout << item.name << "\t" << item.quantity << "\t\t" << item.price << 
endl; 
    } 
    inputFile.close(); 
} 
 
void searchItem(const string& filename, const string& itemName) { 
    ifstream inputFile(filename); 
    if (!inputFile) { 
        cerr << "Error: Unable to open file." << endl; 
        return; 
    } 
    Item item; 
    bool found = false; 
    while (inputFile >> item.name >> item.quantity >> item.price) { 
        if (item.name == itemName) { 
            cout << "\nItem Found:\n"; 
            cout << "Name: " << item.name << "\nQuantity: " << item.quantity 
<< "\nPrice: " << item.price << endl; 
            found = true; 
            break; 
        } 
    } 
    if (!found) { 
        cout << "Item not found in inventory." << endl; 
    } 
    inputFile.close(); 
} 
int main() { 
 
    string filename = "inventory.txt"; 
    int choice; 
    do { 
        cout << "\nInventory Management System\n"; 
        cout << "1. Add Item\n"; 
        cout << "2. View All Items\n"; 
        cout << "3. Search Item by Name\n"; 
        cout << "4. Exit\n"; 
        cout << "Enter your choice: "; 
        cin >> choice; 
        switch (choice) { 
            case 1: 
                addItem(filename); 
                break; 
            case 2: 
                viewItems(filename); 
                break; 
            case 3: { 
                string itemName; 
                cout << "Enter item name to search: "; 
                cin >> itemName; 
                searchItem(filename, itemName); 
                break; 
            } 
            case 4: 
                cout << "Exiting program." << endl; 
                break; 
            default: 
                cout << "Invalid choice. Please try again." << endl; 
        } 
    } while (choice != 4); 
    return 0;
}

