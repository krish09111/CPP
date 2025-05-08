#include <map> 
#include <vector> 
#include <string> 
#include <algorithm> 

using namespace std; 
 
void addFolder(map<string, vector<string>>& directory) { 
    string folderName; 
    cout << "Enter folder name: "; 
    cin >> folderName; 
    if (directory.find(folderName) == directory.end()) { 
        directory[folderName] = {}; 
        cout << "Folder added successfully!" << endl; 
    } else { 
        cout << "Folder already exists!" << endl; 
    } 
} 
 
void addFileToFolder(map<string, vector<string>>& directory) { 
    string folderName, fileName; 
    cout << "Enter folder name: "; 
    cin >> folderName; 
    if (directory.find(folderName) != directory.end()) { 
        cout << "Enter file name: "; 
        cin >> fileName; 
        directory[folderName].push_back(fileName); 
        cout << "File added successfully!" << endl; 
    } else { 
        cout << "Folder does not exist!" << endl; 
    } 
} 
 
void displayDirectory(const map<string, vector<string>>& directory) { 
    cout << "\nDirectory Structure:\n"; 
    for (const auto& folder : directory) { 
        cout << "Folder: " << folder.first << endl; 
        cout << "Files: "; 
        for (const auto& file : folder.second) { 
            cout << file << " "; 
        } 
        cout << endl; 
    } 
} 
 
int main() { 
    map<string, vector<string>> directory; 
    int choice; 
 
    do { 
        cout << "Directory Management System"; 
        cout << "1. Add Folder\n"; 
        cout << "2. Add File to Folder\n"; 
        cout << "3. Display Directory\n"; 
        cout << "4. Exit\n"; 
        cout << "Enter your choice: "; 
        cin  >>choice; 
 
        switch (choice) { 
            case 1: 
                addFolder(directory); 
                break; 
            case 2: 
                addFileToFolder(directory); 
                break; 
            case 3: 
                displayDirectory(directory); 
                break; 
            case 4: 
                cout << "Exiting program." ; 
                break; 
            default: 
                cout << "Invalid choice. Please try again." ;
        } 
    } while (choice != 4); 
    return 0;
}