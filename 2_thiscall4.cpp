// 2_thiscall4.cpp
// Clock
#include <iostream>
#include <string>
#include <map>
#include "ioacademy.h"
using namespace std;
using namespace ioacademy;

class Clock
{
	string name;
	static map<int, Clock*> this_map;
	static int a;
public:
	Clock(string s) : name(s) {}

	void Start(int ms)
	{
		int id = IoSetTimer(ms, timerHandler);
		this_map[id] = this;
	}

	static void timerHandler(int id)
	{
		Clock* self = this_map[id];
		cout << self->name << endl;
	}
};

// static 멤버 변수는 반드시 외부 정의가 필요합니다.
map<int, Clock*> Clock::this_map;
int Clock::a = 42;


int main()
{
	Clock c1("AAA");
	Clock c2("\tBBB");

	c1.Start(1000);  // 1초에 한번씩 이름을 출력해야 합니다.
	c2.Start(500);

	IoProcessMessage();
}


#if 0
void foo(int id)
{
	cout << "foo: " << id << endl;
}

int main()
{
	int n1 = IoSetTimer(1000, foo);
	int n2 = IoSetTimer(500, foo);

	IoProcessMessage();
}
#endif