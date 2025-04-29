#include<iostream>
using namespace std;

class Shapes
{	
	public : 
	
		void area_of_rect(int len, int bred)
		{
			int rect = len*bred;
			cout<<"Area of Rectangle = "<<rect<<endl;	
		}
	
		void area_of_square(int side)
		{
			int square = side*side;
			cout<<"Area of Square = "<<square<<endl;	
		}
	
		void area_of_circle(float rd)
		{
			float circle = 3.14*rd*rd;
			cout<<"Area of Circle = "<<circle<<endl;	
		}
		
		void area_of_triangle(int hight, int breadth)
		{
			float triangle = 0.5*hight*breadth;
			cout<<"Area of Triangle = "<<triangle<<endl;	
		}				
};

int main()
{
	Shapes s;
	s.area_of_rect(19,8);
	s.area_of_square(11);
	s.area_of_circle(27.2);
	s.area_of_triangle(23.78,54);
	return 0;
}


