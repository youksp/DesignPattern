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
// 인터페이스 기반 반복자를 사용합니다.
template <typename T>
struct IEnumerator
{
	virtual bool MoveNext() = 0;  // ++역활
	virtual T& GetObject() = 0;   // *역활
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

// 컨테이너에서 반복자 꺼내기
// 1. STL: begin/end() => 암시적 약속
// 2. Java,Tizen: 인터페이스 기반의 함수를 약속한다. => 명시적 약속
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
// : 컨테이너의 내부 구조에 상관없이 요소를 열거할 수 있다.