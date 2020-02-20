// 4_함수바인딩

#include <iostream>
using namespace std;


class Animal
{
public:
	virtual void Cry() { cout << "Animal Cry" << endl; }
};

class Dog : public Animal
{
public:
	void Cry() { cout << "Dog Cry" << endl; }
};

int main()
{
	Animal a; a.Cry();
	Dog d;    d.Cry();

	Animal* p = &d;

	int n;
	cin >> n;
	if (n == 0) p = &a;

	p->Cry();
}

// 함수 바인딩
// 1) static binding: 어떤 함수가 호출될지가 컴파일 타임에 결정되는 것
//  : 빠르다.
//  호출하는 객체의 타입에 의해서 함수가 결정된다.

// 2) dynamic binding: 어떤 함수가 호출될지가 런타임에 결정되는 것
//  : 실행 시간에 메모리 조사 후 호출
//   - 유연하게 동작한다.
//   - 상대적으로 느리다.