// 27_�������
#include <iostream>
using namespace std;

// ��ü�� ������ ���� ����� �����ϴ� ��찡 ����.
class Image
{
	int mCount;
public:
	Image(): mCount(0) {}
	~Image() { cout << "Image �ı�" << endl; }

	void addRef() { ++mCount; }
	void release()
	{
		if (--mCount == 0)
			delete this;
	}

	void draw() { cout << "Draw" << endl; }
};

// ���� ����� �ڵ����� �����ϴ� Ŭ�����Դϴ�.
class ImageProxy
{
	Image* obj;
public:
	ImageProxy(Image* p) : obj(p) { obj->addRef(); }
	ImageProxy(const ImageProxy& p) : obj(p.obj)
	{
		obj->addRef();
	}
	~ImageProxy()
	{
		obj->release();
	}

	Image* operator->() { return obj; }
	Image& operator*() { return *obj; }
};

int main()
{
	ImageProxy p1 = new Image;
	// Image* p1 = new Image;
	// p1->addRef();

	ImageProxy p2 = p1;
	
	p1->draw();


	// Image* p2 = p1;
	// p2->addRef();

	// p1->release();
	// p2->release();
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