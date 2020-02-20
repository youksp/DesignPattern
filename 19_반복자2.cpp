#include <iostream>
using namespace std;

template <typename T>
struct Node
{
	T data;
	Node* next;

	Node(const T& a, Node* n) : data(a), next(n) {}
};

// Java, C#, Swift ...
// �������̽� ��� �ݺ��ڸ� ����մϴ�.
template <typename T>
struct IEnumerator
{
	virtual bool MoveNext() = 0;  // ++��Ȱ
	virtual T& GetObject() = 0;   // *��Ȱ
	virtual ~IEnumerator() {}
};

template <typename T>
class slist_enumerator : public IEnumerator<T>
{
	Node<T>* current;
public:
	slist_enumerator(Node<T>* p = 0) : current(p) {}
	virtual bool MoveNext()
	{
		current = current->next;
		return current;
	}

	virtual T& GetObject()
	{
		return current->data;
	}
};

// �����̳ʿ��� �ݺ��� ������
// 1. STL: begin/end() => �Ͻ��� ���
// 2. Java,Tizen: �������̽� ����� �Լ��� ����Ѵ�. => ����� ���
template <typename T>
struct IEnumerable
{
	virtual IEnumerator<T>* GetEnumerator() = 0;
	virtual ~IEnumerable() {}
};

template <typename T>
class slist : public IEnumerable<T>
{
	Node<T>* head;
public:
	virtual IEnumerator<T>* GetEnumerator()
	{
		return new slist_enumerator<T>(head);
	}

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

	IEnumerator<int>* p = s.GetEnumerator();
	do {
		cout << p->GetObject() << endl;
	} while (p->MoveNext());
}

// Iterator Pattern
// : �����̳��� ���� ������ ������� ��Ҹ� ������ �� �ִ�.