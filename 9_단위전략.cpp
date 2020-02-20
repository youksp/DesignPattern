// 9_단위전략
#include <iostream>
using namespace std;

// Template 기반의 정책 교체!!!
// 단위전략(Policy base design) - Modern C++ Design
//  => 정책을 담은 코드를 컴파일 시간에 생성하는 기술
// - 단위 전략은 인터페이스 함수에 대한 부분을 암묵적으로 약속한다.
//   : 잘못 사용할 경우, 컴파일 오류가 발생한다.
// 장점: 가상함수가 아닌 인라인 함수이다. 호출에 따른 성능의 저하가 존재하지 않는다.
// 단점: Template 인자 이므로, 실행시간에 전략 교체는 불가능하다.
//       컴파일할 때 정책이 결정된다.

class SingleThread
{
public:
	inline void Lock() {}
	inline void Unlock() {}
};

class MultiThread
{
public:
	inline void Lock() { cout << "Lock" << endl; }
	inline void Unlock() { cout << "Unlock" << endl; }
};

template <typename T, typename ThreadModel = SingleThread>
class List
{
	ThreadModel t;
public:
	void push_front(const T& a)
	{
		t.Lock();
		// ....
		t.Unlock();
	}
};


#if 0
template <typename T, typename ThreadModel = SingleThread>
class List: public ThreadModel
{
public:
	void push_front(const T& a)
	{
		ThreadModel::Lock();
		// ....
		ThreadModel::Unlock();
	}
};
#endif

List<int, MultiThread> st;

int main()
{
	st.push_front(10);
}


#if 0
// 동기화 여부를 인터페이스 기반의 다른 클래스로 분리한다. - 전략 패턴
//  장점: 정책을 실행시간에 교체할 수 있다.
//  단점: 가상함수 기반이므로 느리다.

struct ISync
{
	virtual void Lock() = 0;
	virtual void Unlock() = 0;
	virtual ~ISync() {}
};

template <typename T>
class List
{
	ISync* pSync;
public:
	public SetSync(ISync* p) { pSync = p; }

	void push_front(const T& a)
	{
		pSync->Lock();
		// ....
		pSync->Unlock();
	}
};

class SingleThread : public ISync {
public:
	virtual void Lock() {}
	virtual void Unlock() {}
};

class MultiThread : public ISync {
public:
	virtual void Lock() { cout << "lock" << endl;  }
	virtual void Unlock() { cout << "unlock" << endl; }
};

List<int> st;

int main()
{
	st.SetSync(new MultiThread);
	st.push_front(10);
}
#endif