#include <iostream> 
#include <map> 
#include <queue> 
#include <stdexcept> 
using namespace std; 
class LibraryException : public exception { 
public: 
    virtual const char* what() const noexcept override { 
        return "Library exception occurred."; 
    } 
}; 
class BookNotFoundException : public LibraryException { 
public: 
    const char* what() const noexcept override { 
        return "Book not found in the library."; 
    } 
}; 
class MemberNotFoundException : public LibraryException { 
public: 
    const char* what() const noexcept override { 
        return "Member not found in the library."; 
    } 
}; 
class OverdueBookException : public LibraryException { 
public: 
    const char* what() const noexcept override { 
        return "Book is overdue."; 
    } 
}; 
class LibrarySystem { 
private: 
    map<string, bool> books;  
    map<int, string> members;  
    queue<string> borrowRequests;  
public: 

    void addBook(const string& title) { 
        books[title] = true; 
        cout << "Book \"" << title << "\" added to the library." << endl; 
    } 
    void addMember(int memberId, const string& name) { 
        members[memberId] = name; 
        cout << "Member \"" << name << "\" added with ID " << memberId << "." 
<< endl; 
    } 
    void borrowBook(int memberId, const string& title) { 
        if (members.find(memberId) == members.end()) { 
            throw MemberNotFoundException(); 
        } 
        if (books.find(title) == books.end()) { 
            throw BookNotFoundException(); 
        } 
        if (!books[title]) { 
            throw OverdueBookException(); 
        } 
        books[title] = false; 
        borrowRequests.push(title); 
        cout << "Book \"" << title << "\" borrowed by member ID " << memberId 
<< "." << endl; 
    } 
 
    void returnBook(const string& title) { 
        if (books.find(title) == books.end()) { 
            throw BookNotFoundException(); 
        } 
        books[title] = true; 
        cout << "Book \"" << title << "\" returned to the library." << endl; 
    } 
    void displayBooks() const { 
        cout << "\nLibrary Books:\n"; 
        for (const auto& book : books) { 
            cout << book.first << " - " << (book.second ? "Available" : 
"Borrowed") << endl; 
        } 
    } 
    void displayMembers() const { 
        cout << "\nLibrary Members:\n"; 
        for (const auto& member : members) { 
            cout << "ID: " << member.first << " Name: " << member.second << 
endl; 
        } 
    } 
}; 
int main() { 

    LibrarySystem library; 
    try { 
        library.addBook("mahabharata"); 
        library.addBook("0000"); 
        library.addMember(1, "shanky"); 
        library.addMember(2, "tyler"); 
        library.displayBooks(); 
        library.displayMembers(); 
        library.borrowBook(1, "0000"); 
        library.borrowBook(2, "mahabharata"); 
        library.displayBooks(); 
        library.returnBook("0000"); 
        library.displayBooks(); 
        library.borrowBook(3, "0000"); 
    } catch (const LibraryException& e) { 
        cerr << "Error: " << e.what() << endl; 
    } 
    return 0; 
}