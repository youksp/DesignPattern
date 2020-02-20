// ���� �����ϴ� �̱���
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
	//  => �̱� �ھ���� ����� ����������,
	//     ��Ƽ �ھ���� ������ ���� �� �ֽ��ϴ�.
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
	// ����ȭ ��ü(Mutex)�� ����� �� ���ܰ� �߻��ϸ�, ������� Ȯ���� �ֽ��ϴ�.
	// => ������/�Ҹ��ڸ� ���� �����ϸ� �����ϴ�.
	// RAII(Resource Acqusion is Initialize) ��� ���
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