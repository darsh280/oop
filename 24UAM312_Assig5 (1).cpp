#include <iostream>
#include <string>
using namespace std;

// Class to handle deposit operations with function overloading
class Bank 
{
    public:
        void deposit(int amount)
        {
            cout << "Depositing RS" << amount << " in cash." << endl;
        }
        void deposit(float amount) 
        {
            cout << "Depositing RS" << amount << " via digital payment." << endl;
        }
    
        void deposit(string upiID, int amount) 
        {
            cout << "Depositing RS" << amount << " using UPI (" << upiID << ")." << endl;
        }
};

class Account 
{
    private:
        string accountNumber;
        float balance;

    public:
        Account(string accNo, float initialBalance) 
        {
            accountNumber = accNo;
            balance = initialBalance;
        }
    
        void operator+(Account& otherAccount) {
            float transferAmount = 3000;
            if (balance >= transferAmount) {
                balance -= transferAmount;
                otherAccount.balance += transferAmount;
                cout << "Transferring RS" << transferAmount << " from Account " << accountNumber 
                 << " to Account " << otherAccount.accountNumber << "..." << endl;
            } 
            else 
            {
                cout << "Insufficient funds for transfer!" << endl;
            }
        }
    
        void operator-(float amount) 
        {
            if (balance >= amount) {
                balance -= amount;
                cout << "Withdrawing RS" << amount << " from Account " << accountNumber << "..." << endl;
            } 
            else 
            {
                cout << "Insufficient balance for withdrawal!" << endl;
            }
        }
    
        // Function to display account details
        void displayDetails() 
        {
            cout << "Account " << accountNumber << " Balance: RS" << balance << endl;
        }
};

int main() {
    // Creating Bank object for deposit demonstrations
    Bank bank;
    bank.deposit(50000);        
    bank.deposit(1500.75f);    
    bank.deposit("gpay@upi", 2500);  
    
    cout << "\n----- Account Operations -----\n" << endl;
    
    // Creating Account objects
    Account acc1("1001", 10000);
    Account acc2("2002", 5000);
    
    // Displaying initial balances
    cout << "Initial Balances:" << endl;
    acc1.displayDetails();
    acc2.displayDetails();
    cout << endl;
    
    // Transferring funds from acc1 to acc2
    acc1 + acc2;
    cout << endl;
    
    // Displaying new balances after transfer
    cout << "Balances after transfer:" << endl;
    acc1.displayDetails();
    acc2.displayDetails();
    cout << endl;
    
    // Withdrawing funds from acc1
    acc1 - 2000;  // Using overloaded - operator
    cout << endl;
    
    // Displaying final balance of acc1
    cout << "Final balance after withdrawal:" << endl;
    acc1.displayDetails();
    
    return 0;
}
