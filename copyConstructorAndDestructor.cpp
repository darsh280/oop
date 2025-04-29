#include<iostream>
using namespace std;

class Demo
{
	private :
		int *p;
		
	public :
		void getInfo()
		{
			cout<<*p<<endl;	
		}	
		void setInfo(int v)
		{
			*this->p = v;
		}
		Demo(int x)
		{
			p = new int(x);
		}
		Demo(const Demo &obj)
		{
			//p = obj.p;
			p = new int(*(obj.p));
		}
		~Demo()
		{
			cout<<"Destructor is called"<<endl;
			delete(p);
		}
};

int main()
{
	Demo d1(111);
	//Demo(111);   ANONYMOUS OBJECT	
	d1.getInfo();
	
	Demo d2(222);
	d2.getInfo();
	d2.setInfo(234);
	d2.getInfo();
	//d1.~Demo();
	d2.getInfo();
	d1.getInfo();
	
		
}
