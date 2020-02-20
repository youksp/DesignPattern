#include <iostream>
#include <vector>
using namespace std;

// 메멘토: 객체의 상태를 내부적으로 저장했다고 언제라도 그 상태로 복구 가능하게 하는 패턴

class Machine
{
	int stateA;
	int stateB;
	int temp;

	// 복구해야 하는 상태를 별도로 캡슐화 하는것이 핵심입니다.
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