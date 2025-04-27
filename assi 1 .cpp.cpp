#include<iostream>
#include<string>
using namespace std;

class Bank {
	
private:
	string name, address;
	char acc_type;
	float balance;

public:
	void open_account();
	void deposit_money();
	void withdraw_money();
	void display_account();
};


void Bank::open_account()
{
	
	cout << "Enter name: "<<endl;
	cin>>name;
	

	cout << "Enter your address: "<<endl;
	cin>>address;

	cout << "What type of account you want";
	cout<< " to open saving(S) or Current(C): ";
	cin>>acc_type;
	

	cout << "Enter How much money you want to deposit: ";
	cin>>balance;
	
}

void Bank::deposit_money()
{
	int amount;
	cout<<"\n Enter Deposit amount "<<endl;
	cin>>amount;
	
	balance=balance+amount;
}

void Bank::withdraw_money()
{
	int amount;
	cout<<"\n Enter withdrawal amount "<<endl;
	cin>>amount;
	
	balance=balance-amount;
}

void Bank::display_account()
{
	
	cout<<"\nAmount Available "<<balance<<" RS."<<endl;
	
}

int main()
{
	int choice;
	Bank customer;
	
	
	
	cout<<"\nOpen account: \n"<<endl;
	customer.open_account();
	
	cout<<"\nDeposit money";
	customer.deposit_money();
	
	cout<<"\nWithdraw Money";
	customer.withdraw_money();
	
	cout<<"\nDisplay account";
	customer.display_account();
}		

