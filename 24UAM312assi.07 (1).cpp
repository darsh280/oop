#include <iostream>
#include <string>
#include <exception>
using namespace std;

// Custom Exception Classes
class InsufficientFundsException : public exception {
public:
    const char* what() const throw() {
        return "Error: Insufficient funds!";
    }
};

class DivideByZeroException : public exception {
public:
    const char* what() const throw() {
        return "Error: Cannot divide by zero!";
    }
};

// BankAccount class
class BankAccount {
private:
    string ownerName;
    double balance;

public:
    BankAccount(string name, double initialDeposit) {
        ownerName = name;
        balance = initialDeposit;
        cout << "\nCreating Account for " << ownerName << " with Initial Deposit: ?" << balance << endl;
    }

    void deposit(double amount) {
        if (amount >= 0) {
            balance += amount;
            cout << "Depositing ?" << amount << " into " << ownerName << "'s Account" << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > balance) {
            throw InsufficientFundsException();
        }
        balance -= amount;
        cout << "Withdrawing ?" << amount << " from " << ownerName << "'s Account" << endl;
    }

    void transfer(BankAccount &to, double amount) {
        if (amount > balance) {
            throw InsufficientFundsException();
        }
        balance -= amount;
        to.balance += amount;
        cout << "Transferring ?" << amount << " from " << ownerName << " to " << to.ownerName << endl;
    }

    void divideBalance(double divisor) {
        if (divisor == 0) {
            throw DivideByZeroException();
        }
        balance /= divisor;
        cout << "Dividing balance by " << divisor << " for " << ownerName << endl;
    }

    void display() {
        cout << ownerName << "'s Current Balance: ?" << balance << endl;
    }
};

// Main function
int main() {
    string name1, name2;
    double init1, init2;

    // Input for Account 1
    cout << "Enter name for Account 1: ";
    getline(cin >> ws, name1);
    cout << "Enter initial deposit for " << name1 << ": ?";
    cin >> init1;

    // Input for Account 2
    cout << "\nEnter name for Account 2: ";
    getline(cin >> ws, name2);
    cout << "Enter initial deposit for " << name2 << ": ?";
    cin >> init2;

    BankAccount acc1(name1, init1);
    BankAccount acc2(name2, init2);

    // Deposit
    double dep;
    cout << "\nEnter amount to deposit into " << name1 << "'s account: ?";
    cin >> dep;
    acc1.deposit(dep);

    // Withdraw
    double wdraw;
    cout << "\nEnter amount to withdraw from " << name1 << "'s account: ?";
    cin >> wdraw;
    try {
        acc1.withdraw(wdraw);
    } catch (exception &e) {
        cout << e.what() << endl;
    }

    // Transfer
    double transferAmt;
    cout << "\nEnter amount to transfer from " << name1 << " to " << name2 << ": ?";
    cin >> transferAmt;
    try {
        acc1.transfer(acc2, transferAmt);
        acc1.display();
        acc2.display();
    } catch (exception &e) {
        cout << e.what() << endl;
    }

    // Divide Balance
    double divisor;
    cout << "\nEnter number to divide " << name1 << "'s balance: ";
    cin >> divisor;
    try {
        acc1.divideBalance(divisor);
    } catch (exception &e) {
        cout << e.what() << endl;
    }

    return 0;
}

