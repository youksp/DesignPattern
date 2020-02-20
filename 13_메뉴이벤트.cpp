// 13_메뉴이벤트.cpp
#include <iostream>
using namespace std;

class MenuItem
{
	int id;
public:
	MenuItem(int n) : id(n) {}

	virtual void command()
	{
		// 메뉴가 선택된 사실을 다시 외부로 알려야 한다.
		// "객체가 외부로 이벤트를 발생한다" 라고 표현합니다.
	}
};

int main()
{
	MenuItem m1(10), m2(12);
	m1.command();
}