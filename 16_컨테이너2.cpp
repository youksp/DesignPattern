// 16_�����̳�2
#include <iostream>
using namespace std;

// 1. Object* ����� �����̳�

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

// ���̺귯�� ���� ��� Ŭ������ Object�� �ڽ��̾�� �Ѵ�.
class Dialog : public Object {};
class Point : public Object {};

// ������
//  1) Ÿ�� ������ ��������.
//    : �߸��� Ÿ���� �����̳ʿ� ����, ������ Ÿ�ӿ� �� �� ����.
//    : ���� ������ ĳ������ �ʿ��ϴ�.
//  2) �⺻ Ÿ���� �����ϴ� ���� �Ұ����ϴ�.
//    : ����Ŭ������ �ʿ��ϴ�.

// ����: ���ø��� ������� �ʱ� ������ �ڵ� �޸� ��뷮�� �������� �ʴ´�.

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