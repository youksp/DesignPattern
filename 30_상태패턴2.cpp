#include <iostream>
using namespace std;

// 객체 자신의 내부 상태에 따라 행위가 변하도록 한다.
// => 마치 클래스를 바꾸는 것 처럼 보인다.

struct IState
{
	virtual void run() = 0;
	virtual void attack() = 0;
	virtual ~IState() {}
};

class Hero
{
	int level;
	int item;

	IState* state;
public:
	void setState(IState* p) { state = p; }

	void run()    { state->run();  }
	void attack() { state->attack(); }
};

// 다양한 Item에 따른 동작을 인터페이스 기반 클래스로 정의한다.
class NormalState : public IState
{
public:
	virtual void run() { cout << "Run" << endl; }
	virtual void attack() { cout << "Attack" << endl; }
};

class FastState : public IState
{
public:
	virtual void run() { cout << "Fast Run" << endl; }
	virtual void attack() { cout << "Fast Attack" << endl; }
};

int main()
{
	NormalState ns;
	FastState fs;

	Hero h;
	h.setState(&ns);
	h.run();

	h.setState(&fs);
	h.run();

}


#if 1
class Hero
{
	int level;
	int item;
public:
	virtual void run() { cout << "Run" << endl; }
	virtual void attack() { cout << "Attack" << endl; }
};

// 아이템의 획득에 따라 동작을 변경하기 위해서 상속을 이용하자.
class FastHero : public Hero
{
public:
	virtual void run() { cout << "Fast run" << endl; }
};

int main()
{
	Hero h;
	Hero* p = &h;
	p->run();
	// 아이템 먹음

	FastHero fh;
	p = &fh;
	p->run();
}
#endif