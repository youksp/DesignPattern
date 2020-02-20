// ����Լ��� �Լ� ������ �̾߱�
#include <iostream>
using namespace std;
// 13_�޴��̺�Ʈ.cpp
#include <iostream>
using namespace std;

// �Լ� ������ ����� �̺�Ʈ ó�� ���
//  : ������ Objectice C - Target / Action
//    MFC �޼��� ��
//    Qt  �ñ׳� ����

class Dialog;

class MenuItem
{
	int id;
public:
	MenuItem(int n) : id(n) {}

	// C++���� ��� �Լ��� �ּҸ� ���� �� �ִ� �Լ� �����Ͱ� �����ϴ�.
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
	
	// ��� �Լ� ������ Ÿ���� ǥ���ϴ� ���
	void(Dialog::*p2)() = &Dialog::open;
	
	Dialog dialog;
	(dialog.*p2)();
}
*/