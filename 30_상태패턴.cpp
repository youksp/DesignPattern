#include <iostream>
using namespace std;


class Hero
{
	int level;
	int item;
public:
	// 아이템의 상태에 따라서 다른 행동을 하고 싶다.
	// 1. 아이템의 종류에 다른 조건 분기 코드
	//  문제점: 신규 아이템이 추가됨에 따라 조건 분기문이 추가되어야 한다.
	//    => OCP를 만족할 수 없다.
	void run() 
	{
		if (item == 1)
		{
			cout << "Run" << endl;
		}
		else if (item == 2)
		{
			cout << "Fast Run" << endl;
		}
	}
	void attack() { cout << "Attack" << endl; }
};

int main()
{
	Hero h;
	h.run();
}

#if 0
class Hero
{
	int level;
	int item;
public:
	void run() { cout << "Run" << endl; }
	void attack() { cout << "Attack" << endl; }
};

int main()
{
	Hero h;
	h.run();
}
#endif