// 힙에 생성하는 싱글톤
#include <iostream>
using namespace std;

#include <mutex>

class Mutex
{
public:
	void Lock()   { cout << "Mutex Lock" << endl; }
	void Unlock() { cout << "Mutex Unlock" << endl; }

	class AutoLock
	{
		Mutex& mLock;
	public:
		AutoLock(Mutex& m) : mLock(m) { mLock.Lock(); }
		~AutoLock() { mLock.Unlock(); }
	};

};

class Cursor
{
private:
	Cursor() {}
	Cursor(const Cursor&) = delete;
	void operator=(const Cursor&) = delete;

	static Cursor* sInstance;
	// static Mutex sLock;
	static mutex sLock;
public:


#if 0
	// DCLP: Double Checked Locking Pattern
	//  => 싱글 코어에서는 제대로 동작하지만,
	//     멀티 코어에서는 문제가 생길 수 있습니다.
	static Cursor& getInstance()
	{
		if (sInstance == 0)
		{
			sLock.Lock();
			if (sInstance == 0)
				sInstance = new Cursor;
			sLock.Unlock();
		}
		return *sInstance;
	}
#endif

#if 0
	// 동기화 객체(Mutex)를 사용할 때 예외가 발생하면, 데드락의 확률이 있습니다.
	// => 생성자/소멸자를 통해 관리하면 좋습니다.
	// RAII(Resource Acqusion is Initialize) 라는 기술
	static Cursor& getInstance()
	{
		// Mutex::AutoLock al(sLock);
		lock_guard<mutex> al(sLock);

		// sLock.Lock();
		if (sInstance == 0)
			sInstance = new Cursor;
		// sLock.Unlock();
		return *sInstance;
	}
#endif

	static Cursor& getInstance()
	{
		static Cursor* sInstance = new Cursor;
		return *sInstance;
	}
};

Cursor* Cursor::sInstance = 0;

#if 0
class Cursor
{
private:
	Cursor() {}
	Cursor(const Cursor&) = delete;
	void operator=(const Cursor&) = delete;

	static Cursor* sInstance;
public:
	static Cursor& getInstance()
	{
		if (sInstance == 0)
			sInstance = new Cursor;
		return *sInstance;
	}
};

Cursor* Cursor::sInstance = 0;
#endif
int main()
{
	Cursor& c1 = Cursor::getInstance();
	Cursor& c2 = Cursor::getInstance();
	cout << &c1 << ", " << &c2 << endl;
}

// Modern Language
// C               ->     Go
// C++             ->     Rust
// Java            ->     Kotlin
// Objective-C     ->     Swift