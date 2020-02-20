// 16_컨테이너
// 중요합니다!
#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;

	Node(int a, Node* n) : data(a), next(n) {}
};

class slist
{
	Node* head;
public:
	slist() : head(0) {}

	void push_front(int a)
	{
		head = new Node(a, head);
	}

	int front() { return head->data; }
};

int main()
{
	slist s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);

	cout << s.front() << endl;

}