// 27_참조계수
#include <iostream>
using namespace std;

// 객체의 수명을 참조 계수로 관리하는 경우가 많다.
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
	~Image() { cout << "Image 파괴" << endl; }
	void draw() { cout << "Draw" << endl; }
};

// 참조 계수를 자동으로 관리하는 클래스입니다.
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
	~Car() { cout << "Car 파괴" << endl; }
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
	// 규칙 1. 객체를 만들면 참조 계수 증가
	p1->addRef();

	Image* p2 = p1;
	p2->addRef();
	// 규칙 2. 객체 포인터를 복사하면 참조 계수 증가

	// 규칙 3. 객체 포인터를 더 이상 사용하지 않으면 참조 계수 감소
	p1->release();
	p2->release();
}
#endif