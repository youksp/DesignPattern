#include <iostream>
#include <vector>
using namespace std;

// �޸���: ��ü�� ���¸� ���������� �����ߴٰ� ������ �� ���·� ���� �����ϰ� �ϴ� ����

class Machine
{
	int stateA;
	int stateB;
	int temp;

	// �����ؾ� �ϴ� ���¸� ������ ĸ��ȭ �ϴ°��� �ٽ��Դϴ�.
	struct Memento
	{
		int stateA;
		int stateB;
		int temp;
		Memento(int a, int b, int c) : stateA(a), stateB(b), temp(c) {}
	};

	vector<Memento*> backup;
public:
	int CreateMemento()
	{
		Memento* m = new Memento(stateA, stateB, temp);
		backup.push_back(m);

		return backup.size() - 1;  // token
	}

	int RestoreMemento(int token)
	{
		Memento* m = backup[token];
		stateA = m->stateA;
		stateB = m->stateB;
		temp = m->temp;
	}

	void SetState(int a, int b, int c)
	{
		stateA = a;
		stateB = b;
		temp = c;
	}
};

int main()
{
	Machine m;
	m.SetState(10, 20, 30);

	int token = m.CreateMemento();
	m.SetState(101, 201, 301);

	m.RestoreMemento(token);
}