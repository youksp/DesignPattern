#include <iostream>
using namespace std;

#include <functional>  // 이 안에 범용적 함수 포인터가 존재합니다.
using namespace std::placeholders;

void foo() { cout << "foo" << endl; }

void goo(int a) { cout << "goo:" << a << endl; }

class Dialog
{
public:
	void open() { cout << "open" << endl; }
};

void hoo(int a, int b) { cout << "hoo: " << a << ", " << b << endl; }
void koo(int a, int b, int c, int d) { cout << "koo: " << a << b << c << d << endl; }

int main()
{
	function<void(int, int)> f3;
	f3 = bind(&koo, _2, _1, 10, 20);
	f3(30, 40);

	function<void(int)> f2;
	f2 = &goo;
	f2(10);

	f2 = bind(&hoo, 100, _1);
	f2(42);

	// boost에서 처음 만들어서,  C++11 에서 공식 표준으로 지정된 클래스
	function<void()> f = [] { cout << "hello" << endl; };
	f();
	
	Dialog dlg;
	f = bind(&Dialog::open, &dlg);
	f();


	f = &foo;
	f();

	f = bind(&goo, 42);
	f();

	f = bind(&hoo, 10, 20);
	f();
	
}