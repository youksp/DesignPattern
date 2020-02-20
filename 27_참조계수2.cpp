// 27_�������
#include <iostream>
using namespace std;

// ��ü�� ������ ���� ����� �����ϴ� ��찡 ����.
class RefCountedObject
{
	int mCount;
public:
	RefCountedObject() : mCount(0) {}
	virtual ~RefCountedObject() {}

	void addRef() { ++mCount; }
	void release()
	{
		if (--mCount == 0)
			delete this;
	}
};


class Image : public RefCountedObject
{
public:
	~Image() { cout << "Image �ı�" << endl; }
	void draw() { cout << "Draw" << endl; }
};

// ���� ����� �ڵ����� �����ϴ� Ŭ�����Դϴ�.
template <typename T>
class sp
{
	T* obj;
public:
	sp(T* p) : obj(p) { obj->addRef(); }
	sp(const sp& p) : obj(p.obj)
	{
		obj->addRef();
	}
	~sp()
	{
		obj->release();
	}

	T* operator->() { return obj; }
	T& operator*() { return *obj; }
};

class Car : public RefCountedObject {
public:
	~Car() { cout << "Car �ı�" << endl; }
};

int main()
{
	sp<Car> p3 = new Car;

	sp<Image> p1 = new Image;
	sp<Image> p2 = p1;

	p1->draw();
}

#if 0
int main()
{
	Image* p1 = new Image;
	// ��Ģ 1. ��ü�� ����� ���� ��� ����
	p1->addRef();

	Image* p2 = p1;
	p2->addRef();
	// ��Ģ 2. ��ü �����͸� �����ϸ� ���� ��� ����

	// ��Ģ 3. ��ü �����͸� �� �̻� ������� ������ ���� ��� ����
	p1->release();
	p2->release();
}
#endif