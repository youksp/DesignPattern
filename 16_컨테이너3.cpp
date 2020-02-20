// 16_�����̳�
// �߿��մϴ�!
#include <iostream>
using namespace std;

// 2. ���ø� ��� �����̳�
//  ����: Ÿ�Ծ������� �پ��, ��ü �� �ƴ϶� ǥ�� Ÿ�Ե� ���尡���ϴ�.
//        ���� �� ĳ���õ� �ʿ����.
//  ����: ���ø� �̹Ƿ� �������� Ÿ�Կ� ����ϸ� list�� �����ڵ尡
//        ��������. �ڵ� �޸� ������尡 �ִ�.

template <typename T>
struct Node
{
	T data;
	Node* next;

	Node(const T& a, Node* n) : data(a), next(n) {}
};

template <typename T>
class slist
{
	Node<T>* head;
public:
	slist() : head(0) {}

	void push_front(const T& a)
	{
		head = new Node<T>(a, head);
	}

	T& front() { return head->data; }
};

int main()
{
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);

	cout << s.front() << endl;

}