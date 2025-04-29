#include<iostream>
using namespace std;

class Student
{
	private:
		char name[25];
		int id;
		char add[25];
		int cont_no;
	
	public:	
		void getstudInfo()
		{
			cout<<"Enter the name of student = ";
			cin>>name;
			cout<<"Enter the id of student = ";
			cin>>id;
			cout<<"Enter the address of student = ";
			cin>>add;
			cout<<"Enter the contact number of student = ";
			cin>>cont_no;
		}
		
		void setstudInfo()
		{
			cout<<"---------------Student Information---------------"<<endl;
			cout<<"Name = "<<name<<endl;
			cout<<"ID = "<<id<<endl;
			cout<<"Address = "<<add<<endl;
			cout<<"Contact No. = "<<cont_no<<endl;	
		}			
};

int main()
{
	Student s;
	s.getstudInfo();
	s.setstudInfo();
	return 0;
}


