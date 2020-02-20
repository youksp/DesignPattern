#include <iostream>
using namespace std;

template <typename T>
struct Node
{
	T data;
	Node* next;

	Node(const T& a, Node* n) : data(a), next(n) {}
};

template <typename T>
class slist_iterator
{
	Node<T>* current;
public:
	slist_iterator(Node<T>* p = 0) : current(p) {}

	// !=, *, ++
	T& operator*() { return current->data; }
	slist_iterator& operator++() { current = current->next; return *this; }

	bool operator!=(const slist_iterator& t)
	{
		return t.current != current;
	}
	bool operator==(const slist_iterator& t)
	{
		return t.current == current;
	}

};

// 모든 컨테이너는 자신의 처음과 끝 다음을 가르키는 반복자를 꺼낼 수 있는 함수를 제공해야 한다.
template <typename T>
class slist
{
	Node<T>* head;
public:
	// typedef를 통해서 구체적인 반복자의 타입을 몰라도 사용할 수 있도록 해야 합니다.
	typedef slist_iterator<T> iterator;

	slist() : head(0) {}

	iterator begin() { return iterator(head); }
	iterator end()   { return iterator(0); }

	void push_front(const T& a)
	{
		head = new Node<T>(a, head);
	}

	T& front() { return head->data; }
};

template <typename T1, typename T2>
T1 xfind(T1 first, T1 last, T2 c)
{
	while (first != last && *first != c)
		++first;

	return first; // == last ? 0 : first;
}

#if 1
#include <list>
#include <vector>
#include <algorithm>

// 반복자 패턴: 컨테이너의 내부 구조에 상관없이 요소를 열거한다.

int main()
{
	vector<int> s = { 10, 20, 30 };
	// s.push_front(10);
	// s.push_front(20);
	// s.push_front(30);

	// slist_iterator<int> p = xfind(s.begin(), s.end(), 20);
	vector<int>::iterator p = find(s.begin(), s.end(), 20);
	if (p != s.end())
		cout << *p << endl;

}
#endif