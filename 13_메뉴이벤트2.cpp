// 13_메뉴이벤트2.cpp
#include <iostream>
using namespace std;

// 1. 인터페이스 기반 리스너 개념
//   :  Java, Android, 타이젠(C++)

// 메뉴를 처리하고 싶은 모든 클래스는 아래 인터페이스를 구현해야 한다.
struct IMenuListener
{
	// 어떤 객체로부터 이벤트가 발생했는지 알 수 없다.
	// id를 통한 분기문이 발생한다.
	virtual void onCommand(int id) = 0;
	virtual ~IMenuListener() {}
};


class MenuItem
{
	int id;
	IMenuListener* listener;
public:
	MenuItem(int n) : id(n) {}
	void setListener(IMenuListener* p) { listener = p; }

	virtual void command()
	{
		// 메뉴가 선택된 사실을 다시 외부로 알려야 한다.
		// "객체가 외부로 이벤트를 발생한다" 라고 표현합니다.
		if (listener)
			listener->onCommand(id);
	}
};

class Dialog : public IMenuListener
{
public:
	void open() { cout << "Dialog open" << endl; }
	void close() { cout << "Dialog close" << endl; }

	virtual void onCommand(int id)
	{
		switch (id)
		{
		case 10:
			open();
			break;
		case 12:
			close();
			break;
		}
	}
};


int main()
{
	MenuItem m1(10), m2(12);
	Dialog dialog;

	m1.setListener(&dialog);
	m2.setListener(&dialog);

	m1.command();
	m2.command();
}