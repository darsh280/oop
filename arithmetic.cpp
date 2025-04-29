#include<iostream>
using namespace std;

int add(int a, int b)
{
	return a+b;
}

int sub(int a, int b)
{
	return a-b;
}

int multi(int a, int b)
{
	return a*b;
}

int div(int a, int b)
{
	return a/b;
}

int mod(int a, int b)
{
	return a%b;
}

int main()
{
	cout<<"Additoin = "<<add(27,11)<<endl;
	cout<<"Substraction = "<<sub(19,8)<<endl;
	cout<<"Multiplication = "<<multi(34,5)<<endl;
	cout<<"Divistion = "<<div(34,7)<<endl;
	cout<<"Modulaus = "<<mod(46,3)<<endl;
	
	return 0;
}
