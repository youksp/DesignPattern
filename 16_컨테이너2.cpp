// 16_컨테이너2
#include <iostream>
using namespace std;

// 1. Object* 기반의 컨테이너

class Object
{
public:
	virtual ~Object() {}
};

struct Node
{
	Object* data;
	Node* next;

	Node(Object* a, Node* n) : data(a), next(n) {}
};

class slist
{
	Node* head;
public:
	slist() : head(0) {}

	void push_front(Object* a)
	{
		head = new Node(a, head);
	}

	Object* front() { return head->data; }
};

// 라이브러리 내의 모든 클래스는 Object의 자식이어야 한다.
class Dialog : public Object {};
class Point : public Object {};

// 문제점
//  1) 타입 안정성 떨어진다.
//    : 잘못된 타입이 컨테이너에 들어가도, 컴파일 타임에 알 수 없다.
//    : 꺼낼 때마다 캐스팅이 필요하다.
//  2) 기본 타입을 저장하는 것이 불가능하다.
//    : 래퍼클래스가 필요하다.

// 장점: 템플릿을 사용하지 않기 때문에 코드 메모리 사용량은 존재하지 않는다.

class Integer
{
	int n;
public:
	Integer(int a) : n(a) {}
};



int main()
{
	slist s;
	// s.push_front(10);
	s.push_front(new Integer(10));
	// int a = s.front();

#if 0
	s.push_front(new Dialog);
	// s.push_front(new Point);
	
	Point* p = static_cast<Point*>(s.front());
	// Point* p = dynamic_cast<Point*>(s.front());
	cout << p << endl;
#endif
	

}