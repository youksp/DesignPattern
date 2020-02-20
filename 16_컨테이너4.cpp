// 16_�����̳�

// �����̳� ���� ��� 3.  Thin Template

#include <iostream>
using namespace std;

struct Node
{
	void* data;
	Node* next;

	Node(void* a, Node* n) : data(a), next(n) {}
};

class slistImpl
{
	Node* head;
public:
	slistImpl() : head(0) {}

	void push_front(void* a)
	{
		head = new Node(a, head);
	}

	void* front() { return head->data; }
};

// slistImpl�� ���� ����ϸ� �����ϴ�. ����ڰ� ���ϰ� ����� �� �ֵ���
// template���� �ڽ� Ŭ������ ��������.
template <typename T> class slist: private slistImpl
{
public:
	inline void push_front(const T& a)
	{
		slistImpl::push_front(const_cast<T*>(&a));
	}

	inline T& front()
	{
		return *(static_cast<T*>(slistImpl::front()));
	}
};

int main()
{
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);

	cout << s.front() << endl;

}