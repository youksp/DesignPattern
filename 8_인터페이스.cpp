// 8_인터페이스

#include <iostream>
using namespace std;

// C++은 인터페이스 문법이 존재하지 않습니다.
// C++에서 인터페이스를 만드는 방법

// 1. Person 클래스는 Camera 클래스와 강하게 결합되어 있다.
// 강한 결합: 구체적인 클래스 타입에 의존하는 경우.
// 약한 결합
//  : 하나의 클래스가 다른 클래스를 이용할 때 부모인 추상 클래스나 인터페이스를 이용하는 방식
//   => 교체 가능한 유연한 디자인

// 카메라와 카메라 제작자 사이의 규칙을 먼저 설계한다.
//  (인터페이스, 프로토콜)

struct ICamera
{
	virtual void Take() = 0;
	virtual ~ICamera() {}
};

// 규칙: 모든 카메라는 위의 클래스로부터 파생되어야 된다. 라고 하지 말고,
//       모든 카메라는 위의 인터페이스를 구현해야 한다. 라고 해야 한다.
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
// 추상 클래스: 순수 가상 함수를 하나라도 가지고 있는 클래스
//  -> 인스턴스화가 불가능하다.
class Shape
{
public:
	virtual ~Shape() {}
	virtual void Draw() = 0; // 순수 가상 함수
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