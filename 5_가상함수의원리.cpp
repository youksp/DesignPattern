// 5_�����Լ��ǿ���
#include <iostream>
using namespace std;

class A
{
	int a;
public:
	virtual void foo() {
		cout << "A foo" << endl;
	}
};

class B
{
	int b;
public:
	virtual void goo() {
		cout << "B goo" << endl;
	}
};

int main()
{
	A aaa;
	B* p = reinterpret_cast<B*>(&aaa);

	p->goo();
}


#if 0
class Animal
{
	int age;
public:
	virtual void Cry() {}
};

class Dog : public Animal
{
	int color;
public:
	// virtual void Cry() {}
};

int main()
{
	Animal a;  cout << sizeof(a) << endl;      // 4 
	Dog d;     cout << sizeof(d) << endl;      // 8

	Animal* p = &d;
	p->Cry();
	// �̼����� ��Ȯ�� ������ �����غ��ô�.
	// (*p)[0](p)
}
#endif