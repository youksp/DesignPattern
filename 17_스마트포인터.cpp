// 17_����Ʈ������
#include <iostream>
using namespace std;

class Car
{
public:
	void Go() { cout << "Car go" << endl; }
	~Car() { cout << "Car �ı�" << endl; }
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

// ����Ʈ ������ ����: ������ ��ü�� �ٸ� Ŭ������ ������ ��Ȱ�� �ϴ� ��
// ���� ����:  -> �� * �����ڸ� �������ؼ� ������ó�� ���̰� �Ѵ�.
// ����: ��¥ �����Ͱ� �ƴ϶� ��ü�̴�.
//       ����/����/����/�Ҹ��� ��� ������ ������ �� �ִ�.

// C++ ǥ�ؿ��� �������� ����Ʈ �����Ͱ� �ֽ��ϴ�.
// - shared_ptr / unique_ptr / weak_ptr
// - auto_ptr: ���� ����ϸ� �ȵ˴ϴ�.


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