#include<iostream>
using namespace std;
int main()
{
	int x,i,fact=1;
	
	cout<<"Enter number for factorial = ";
	cin>>x;
	
	for(i=1; i<=x; ++i)
	{
		fact = i*fact;
	}
	cout<<"Factorial of "<<x<<" = "<<fact<<endl;
	
	return 0;
}
