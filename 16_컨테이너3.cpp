// 16_컨테이너
// 중요합니다!
#include <iostream>
using namespace std;

// 2. 템플릿 기반 컨테이너
//  장점: 타입안정성이 뛰어나고, 객체 뿐 아니라 표준 타입도 저장가능하다.
//        꺼낼 때 캐스팅도 필요없다.
//  단점: 템플릿 이므로 여러가지 타입에 사용하면 list의 기계어코드가
//        많아진다. 코드 메모리 오버헤드가 있다.

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