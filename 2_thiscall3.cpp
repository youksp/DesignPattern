// 2_thiscall3.cpp
// Thread�� Ŭ������ �����غ��ô�.
#include <Windows.h>
#include <iostream>
using namespace std;

// https://d.pr/f/Po3PHI+

class Thread
{
public:
	void run()
	{
		CreateThread(0, 0, _threadLoop, this, 0, 0);
	}

	// 1. �Ʒ� �Լ��� static ��� �Լ� �� �� �ۿ� ���� ������ ��Ȯ�� �˾ƾ� �մϴ�.
	// 2. this�� �����Ƿ� ������ �Լ��� ���ڸ� ���� this�� �����ϴ� ������ �˾ƾ� �մϴ�.
	static DWORD __stdcall _threadLoop(void* p)
	{
		Thread* const self = static_cast<Thread*>(p);
		self->threadLoop();
		return 0;
	}

	virtual bool threadLoop() { return false; }
};


//-----------------------------
class MyThread : public Thread
{
public:
	virtual bool threadLoop()
	{
		cout << "MyThread threadLoop" << endl;
		return true;
	}
};

int main()
{
	MyThread t;
	t.run();        // �� ���� �����尡 �����Ǿ, �����Լ��� threadLoop�� �����ؾ� �մϴ�.

	getchar();
}


#if 1
DWORD __stdcall foo(void* p)
{
	cout << "foo" << endl;
	return 0;
}

int main()
{
	CreateThread(0, 0, foo, (void*)"A", 0, 0);
	getchar();
}
#endif