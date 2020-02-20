#include <iostream>
#include <list>
using namespace std;

// list�� �̹� �ֽ��ϴ�.


// client�� stack�� �䱸�մϴ�.
// 1) stack�� �ٽ� ������ش�.
// 2) list�� �������� ����ϸ� stack�̴�. list�� ��������.


// Adapter Pattern: ���� Ŭ������ �������̽�(�Լ� �̸�)�� �����ؼ� Ŭ���̾�Ʈ�� �䱸�ϴ�
//                  ���ο� Ŭ����ó�� ���̰� �ϴ� ����!

#if 0
// private ���
//  : �θ�κ��� ������ ���� ������(�ڽ��� ���������� ���������)
//    �������̽��� ���� ���� �ʰڴ�(�θ� �Լ��� �ܺη� �������� �ʰڴ�)

template <typename T>
class stack : private list<T>
{
public:
	inline void push(const T& a) { list<T>::push_back(a); }  // �θ� �Լ� ����
	inline void pop() { list<T>::pop_back(); }
	inline T& top() {
		return list<T>::back();
	}
};
#endif

// S/W ������ ��Ӱ� ������ �ִ�. => ������ ���� ���� ����.
#if 0
template <typename T>
class stack
{
	list<T> st;
public:
	inline void push(const T& a) { st.push_back(a); }
	inline void pop() { st.pop_back(); }
	inline T& top() {
		return st.back();
	}
};
#endif
#include <deque>
#include <vector>
#include <stack>

#if 0
// �����̳ʵ� ������ �� �ֵ��� ����Ǿ� �ֽ��ϴ�.
template <typename T, typename C = deque<T>>
class stack
{
	C st;
public:
	inline void push(const T& a) { st.push_back(a); }
	inline void pop() { st.pop_back(); }
	inline T& top() {
		return st.back();
	}
};
#endif


int main()
{
	stack<int, vector<int>> s2;

	stack<int, list<int>> s;
	s.push(10);
	s.push(20);

	cout << s.top() << endl;
}