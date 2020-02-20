// 2_thiscall3.cpp
// Thread를 클래스로 설계해봅시다.
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

	// 1. 아래 함수가 static 멤버 함수 일 수 밖에 없는 이유를 정확히 알아야 합니다.
	// 2. this가 없으므로 스레드 함수의 인자를 통해 this를 전달하는 이유를 알아야 합니다.
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
	t.run();        // 이 순간 스레드가 생성되어서, 가상함수인 threadLoop를 수행해야 합니다.

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