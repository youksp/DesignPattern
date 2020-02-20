// 9_��������
#include <iostream>
using namespace std;

// Template ����� ��å ��ü!!!
// ��������(Policy base design) - Modern C++ Design
//  => ��å�� ���� �ڵ带 ������ �ð��� �����ϴ� ���
// - ���� ������ �������̽� �Լ��� ���� �κ��� �Ϲ������� ����Ѵ�.
//   : �߸� ����� ���, ������ ������ �߻��Ѵ�.
// ����: �����Լ��� �ƴ� �ζ��� �Լ��̴�. ȣ�⿡ ���� ������ ���ϰ� �������� �ʴ´�.
// ����: Template ���� �̹Ƿ�, ����ð��� ���� ��ü�� �Ұ����ϴ�.
//       �������� �� ��å�� �����ȴ�.

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
// ����ȭ ���θ� �������̽� ����� �ٸ� Ŭ������ �и��Ѵ�. - ���� ����
//  ����: ��å�� ����ð��� ��ü�� �� �ִ�.
//  ����: �����Լ� ����̹Ƿ� ������.

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