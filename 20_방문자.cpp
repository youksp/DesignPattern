// 16_�����̳�
// �߿��մϴ�!
#include <iostream>
using namespace std;

// �湮��(Visitor) ����: �����̳��� ���� ������ ������� ��ҿ� ������ �����ϴ� ��ü

template <typename T>
struct Node
{
	T data;
	Node* next;

	Node(const T& a, Node* n) : data(a), next(n) {}
};

template <typename T>
struct IVisitor
{
	virtual void visit(T& a) = 0;
	virtual ~IVisitor() {}
};

template <typename T>
struct IAcceptor
{
	virtual void accept(IVisitor<T>* visitor) = 0;
	virtual ~IAcceptor() {}
};


template <typename T>
class slist : public IAcceptor<T>
{
	Node<T>* head;
public:
	slist() : head(0) {}

	//----------
	virtual void accept(IVisitor<T>* visitor)
	{
		Node<T>* current = head;
		while (current)
		{
			visitor->visit(current->data);
			current = current->next;
		}
	}
	//---------


	void push_front(const T& a)
	{
		head = new Node<T>(a, head);
	}

	T& front() { return head->data; }
};

// ��� ��Ҹ� 2��� �ϰ� �ʹ�.
class TwiceVisitor : public IVisitor<int>
{
	virtual void visit(int& a)
	{
		a *= 2;
	}
};

int main()
{
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);

	TwiceVisitor v;
	s.accept(&v);

	cout << s.front() << endl;

}