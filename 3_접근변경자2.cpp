#include <iostream>
#include <list>
using namespace std;

// list가 이미 있습니다.


// client가 stack을 요구합니다.
// 1) stack을 다시 만들어준다.
// 2) list를 한쪽으로 사용하면 stack이다. list를 재사용하자.


// Adapter Pattern: 기존 클래스의 인터페이스(함수 이름)을 변경해서 클라이언트가 요구하는
//                  새로운 클래스처럼 보이게 하는 패턴!

#if 0
// private 상속
//  : 부모로부터 구현은 물려 받지만(자식이 내부적으로 사용하지만)
//    인터페이스는 물려 받지 않겠다(부모 함수를 외부로 노출하지 않겠다)

template <typename T>
class stack : private list<T>
{
public:
	inline void push(const T& a) { list<T>::push_back(a); }  // 부모 함수 재사용
	inline void pop() { list<T>::pop_back(); }
	inline T& top() {
		return list<T>::back();
	}
};
#endif

// S/W 재사용은 상속과 포함이 있다. => 포함이 좋을 때가 많다.
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
// 컨테이너도 선택할 수 있도록 설계되어 있습니다.
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