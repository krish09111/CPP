#include <iostream> 
#include <stdexcept> 
#include <string> 
using namespace std; 
class BankAccount { 
private: 
    string accountHolder; 
    double balance; 
    string transactionLogs[20]; 
    int logIndex; 
public: 
    BankAccount(string name, double initialBalance) : accountHolder(name), 
balance(initialBalance), logIndex(0) {} 
    void deposit(double amount) { 
        if (amount <= 0) { 
            throw invalid_argument("Deposit amount must be positive."); 
        } 
        balance += amount; 
        logTransaction("Deposit: " + to_string(amount)); 
        cout << "Deposited " << amount << ". New balance: " << balance << 
endl; 
    } 
    void withdraw(double amount) { 
        if (amount <= 0) { 
            throw invalid_argument("Withdrawal amount must be positive."); 
        } 
        if (amount > balance) { 
            throw runtime_error("Insufficient balance."); 
        } 
        balance -= amount; 
        logTransaction("Withdraw: " + to_string(amount)); 
        cout << "Withdrew " << amount << ". New balance: " << balance << endl; 
    } 

    void displayBalance() const { 
        cout << "Current balance: " << balance << endl; 
    } 
    void displayTransactionLogs() const { 
        cout << "\nTransaction Logs:\n"; 
        for (int i = 0; i < logIndex; ++i) { 
            cout << transactionLogs[i] << endl; 
        } 
    } 
private: 
    void logTransaction(const string& log) { 
        if (logIndex < 100) { 
            transactionLogs[logIndex++] = log; 
        } 
    } 
}; 
void performBankingOperations(BankAccount& account) { 
    try { 
        account.deposit(500); 
        account.withdraw(200); 
        account.withdraw(1000); 
    } catch (const exception& e) { 
        cerr << "Error: " << e.what() << endl; 
        throw;  
    } 
} 
int main() { 
    try { 
        BankAccount account("John Doe", 1000); 
        account.displayBalance(); 
        performBankingOperations(account); 
    } catch (const exception& e) { 
        cerr << "Exception caught in main: " << e.what() << endl; 
    } 
    return 0; 
} 