// 멤버함수와 함수 포인터 이야기
#include <iostream>
using namespace std;
// 13_메뉴이벤트.cpp
#include <iostream>
using namespace std;

// 함수 포인터 기반의 이벤트 처리 방법
//  : 아이폰 Objectice C - Target / Action
//    MFC 메세지 맵
//    Qt  시그널 슬롯

class Dialog;

class MenuItem
{
	int id;
public:
	MenuItem(int n) : id(n) {}

	// C++에는 모든 함수의 주소를 담을 수 있는 함수 포인터가 없습니다.
	Dialog* object;
	void (Dialog::*handler)();

	void setHandler(Dialog* p, void (Dialog::*h)())
	{
		object = p;
		handler = h;
	}

	virtual void command()
	{
		(object->*handler)();
	}
};

class Dialog
{
public:
	void open() { cout << "open" << endl; }
	void close() { cout << "close" << endl; }
};


int main()
{
	MenuItem m1(10), m2(12);

	Dialog dialog;

	m1.setHandler(&dialog, &Dialog::open);
	m2.setHandler(&dialog, &Dialog::close);

	m1.command();
	m2.command();
}

/*
class Dialog
{
public:
	void open() { cout << "open" << endl; }
	void close() { cout << "close" << endl; }
};

void foo() { cout << "foo" << endl; }

int main()
{
	void(*p)() = &foo;
	p();
	
	// 멤버 함수 포인터 타입을 표현하는 방법
	void(Dialog::*p2)() = &Dialog::open;
	
	Dialog dialog;
	(dialog.*p2)();
}
*/