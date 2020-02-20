// 12_메뉴.cpp
#include <string>
#include <iostream>
#include <vector>
#include <conio.h>
using namespace std;

#define clrscr() system("cls")


// Composite Pattern
// - 복합 객체(PopupMenu)는 단일 객체(MenuItem)와 복합 객체를 모두 보관할 수 있다
//  => 공통의 부모가 필요하다. 
//     ; 재귀적 포함
// - 복합 객체와 단일 객체가 동일시된다.
//  => 사용법이 같다. 
//  => command()를 호출하면 된다.
//  => 부모 클래스로 부터 비롯되어야 한다.


class BaseMenu
{
	string title;
public:
	BaseMenu(string s) : title(s) {}
	virtual ~BaseMenu() {}

	string getTitle() { return title; }

	// 모든 메뉴는 선택하면 command()가 호출된다.
	// 반드시 command()는 부모인 BaseMenu 로부터 와야 한다.
	// 부모 입장에서 구현해줄 내용이 없고, 자식이 반드시 만들어야 한다면
	// 순수 가상 함수가 좋다.
	virtual void command() = 0;
};


class MenuItem: public BaseMenu
{
	int id;
public:
	MenuItem(string s, int n) : BaseMenu(s), id(n) {}

	virtual void command() override
	{
		cout << getTitle() << "메뉴가 선택되었음" << endl;
		getch();
	}
};

// PopupMenu는 MenuItem도 가질 수 있지만, PopupMenu도 가질 수 있어야 한다.
// => 재귀적 포함
class PopupMenu: public BaseMenu
{
	vector<BaseMenu*> v;
public:
	PopupMenu(string s) : BaseMenu(s) {}

	void addMenu(BaseMenu* p) { v.push_back(p); }

	// 자신이 가진 메뉴를 보여준다.
	virtual void command() override
	{
		while (1)
		{
			clrscr(); // 화면 지우기
			int sz = v.size();
			for (int i = 0; i < sz; ++i) 
			{
				cout << i + 1 << ". " << v[i]->getTitle() << endl;
			}
			cout << sz + 1 << ". 상위 메뉴로" << endl;

			cout << "메뉴를 선택하세요 >> ";
			int cmd;
			cin >> cmd;

			if (cmd == sz + 1)
				break;

			if (cmd < 1 || cmd > sz + 1) // 잘못된 선택
				continue;

			v[cmd - 1]->command(); 

		}
	}

};

int main()
{
	PopupMenu* menubar = new PopupMenu("MENUBAR");
	PopupMenu* p1 = new PopupMenu("화면 설정");
	PopupMenu* p2 = new PopupMenu("소리 설정");

	menubar->addMenu(p1);
	p1->addMenu(p2);
	// menubar->addMenu(p2);

	p1->addMenu(new MenuItem("해상도 설정", 10));
	p1->addMenu(new MenuItem("색상 설정", 11));
	p1->addMenu(new MenuItem("기타 설정", 12));

	p2->addMenu(new MenuItem("볼륨 조절", 20));
	p2->addMenu(new MenuItem("음향 설정", 21));

	menubar->command();
}