// 2_thiscall.cpp
#include <iostream>
using namespace std;

class Point 
{
	int x, y;
public:
	void set(int a, int b) // set(Point* this, int a, int b)
	{
		x = a;             // this->x = a;
		y = b;             // this->y = b;
	}
};

int main() 
{
	Point p1, p2;
	p1.set(10, 20);  // set(&p1, 10, 20);
	p2.set(20, 30);  // set(&p2, 20, 30);
	                 // push 20
					 // push 10
	                 // mov ecx, &p1  // 객체의 주소는 레지스터 사용하는 경우가 많다.
					 // call set
}