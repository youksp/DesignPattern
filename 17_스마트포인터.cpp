// 17_스마트포인터
#include <iostream>
using namespace std;

class Car
{
public:
	void Go() { cout << "Car go" << endl; }
	~Car() { cout << "Car 파괴" << endl; }
};

class Ptr
{
	Car* obj;
public:
	explicit Ptr(Car* p) : obj(p) {}
	~Ptr() { delete obj; }

	Car* operator->() { return obj; }
	Car& operator*() { return *obj; }
};

// 스마트 포인터 개념: 임의의 객체가 다른 클래스의 포인터 역활을 하는 것
// 구현 원리:  -> 와 * 연산자를 재정의해서 포인터처럼 보이게 한다.
// 장점: 진짜 포인터가 아니라 객체이다.
//       생성/복사/대입/소멸의 모든 과정을 제어할 수 있다.

// C++ 표준에는 여러개의 스마트 포인터가 있습니다.
// - shared_ptr / unique_ptr / weak_ptr
// - auto_ptr: 절대 사용하면 안됩니다.


int main()
{
	// Car* p = new Car;
	// Ptr p = new Car;
	Ptr p(new Car);
	
	p->Go();
	(*p).Go();
}



#if 0
int main()
{
	Car* p = new Car;
	p->Go();

	delete p;
}
#endif