// 8_�������̽�

#include <iostream>
using namespace std;

// C++�� �������̽� ������ �������� �ʽ��ϴ�.
// C++���� �������̽��� ����� ���

// 1. Person Ŭ������ Camera Ŭ������ ���ϰ� ���յǾ� �ִ�.
// ���� ����: ��ü���� Ŭ���� Ÿ�Կ� �����ϴ� ���.
// ���� ����
//  : �ϳ��� Ŭ������ �ٸ� Ŭ������ �̿��� �� �θ��� �߻� Ŭ������ �������̽��� �̿��ϴ� ���
//   => ��ü ������ ������ ������

// ī�޶�� ī�޶� ������ ������ ��Ģ�� ���� �����Ѵ�.
//  (�������̽�, ��������)

struct ICamera
{
	virtual void Take() = 0;
	virtual ~ICamera() {}
};

// ��Ģ: ��� ī�޶�� ���� Ŭ�����κ��� �Ļ��Ǿ�� �ȴ�. ��� ���� ����,
//       ��� ī�޶�� ���� �������̽��� �����ؾ� �Ѵ�. ��� �ؾ� �Ѵ�.
class Phone: public ICamera
{
public:
	void Take() { cout << "Take picture with CameraPhone" << endl; }
};

class Camera: public ICamera
{
public:
	void Take() { cout << "Take picture with Camera" << endl; }
};

class Person
{
public:
	void TakePicture(ICamera* c) { c->Take(); }
};


int main()
{
	Person p;
	Camera c;
	Phone c2;
	p.TakePicture(&c2);
}

#if 0
// �߻� Ŭ����: ���� ���� �Լ��� �ϳ��� ������ �ִ� Ŭ����
//  -> �ν��Ͻ�ȭ�� �Ұ����ϴ�.
class Shape
{
public:
	virtual ~Shape() {}
	virtual void Draw() = 0; // ���� ���� �Լ�
};

class Rect : public Shape
{
public:
	virtual void Draw() { cout << "Rect Draw" << endl;  }
};

int main() 
{
	// Shape s;
	Rect r;
}
#endif