#include <iostream>
using namespace std;

// ��ü �ڽ��� ���� ���¿� ���� ������ ���ϵ��� �Ѵ�.
// => ��ġ Ŭ������ �ٲٴ� �� ó�� ���δ�.

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

// �پ��� Item�� ���� ������ �������̽� ��� Ŭ������ �����Ѵ�.
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

// �������� ȹ�濡 ���� ������ �����ϱ� ���ؼ� ����� �̿�����.
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
	// ������ ����

	FastHero fh;
	p = &fh;
	p->run();
}
#endif