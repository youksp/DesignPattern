#include <iostream>
using namespace std;

#include <functional>  // �� �ȿ� ������ �Լ� �����Ͱ� �����մϴ�.
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

	// boost���� ó�� ����,  C++11 ���� ���� ǥ������ ������ Ŭ����
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