// 12_�޴�.cpp
#include <string>
#include <iostream>
#include <vector>
#include <conio.h>
using namespace std;

#define clrscr() system("cls")


// Composite Pattern
// - ���� ��ü(PopupMenu)�� ���� ��ü(MenuItem)�� ���� ��ü�� ��� ������ �� �ִ�
//  => ������ �θ� �ʿ��ϴ�. 
//     ; ����� ����
// - ���� ��ü�� ���� ��ü�� ���Ͻõȴ�.
//  => ������ ����. 
//  => command()�� ȣ���ϸ� �ȴ�.
//  => �θ� Ŭ������ ���� ��ԵǾ�� �Ѵ�.


class BaseMenu
{
	string title;
public:
	BaseMenu(string s) : title(s) {}
	virtual ~BaseMenu() {}

	string getTitle() { return title; }

	// ��� �޴��� �����ϸ� command()�� ȣ��ȴ�.
	// �ݵ�� command()�� �θ��� BaseMenu �κ��� �;� �Ѵ�.
	// �θ� ���忡�� �������� ������ ����, �ڽ��� �ݵ�� ������ �Ѵٸ�
	// ���� ���� �Լ��� ����.
	virtual void command() = 0;
};


class MenuItem: public BaseMenu
{
	int id;
public:
	MenuItem(string s, int n) : BaseMenu(s), id(n) {}

	virtual void command() override
	{
		cout << getTitle() << "�޴��� ���õǾ���" << endl;
		getch();
	}
};

// PopupMenu�� MenuItem�� ���� �� ������, PopupMenu�� ���� �� �־�� �Ѵ�.
// => ����� ����
class PopupMenu: public BaseMenu
{
	vector<BaseMenu*> v;
public:
	PopupMenu(string s) : BaseMenu(s) {}

	void addMenu(BaseMenu* p) { v.push_back(p); }

	// �ڽ��� ���� �޴��� �����ش�.
	virtual void command() override
	{
		while (1)
		{
			clrscr(); // ȭ�� �����
			int sz = v.size();
			for (int i = 0; i < sz; ++i) 
			{
				cout << i + 1 << ". " << v[i]->getTitle() << endl;
			}
			cout << sz + 1 << ". ���� �޴���" << endl;

			cout << "�޴��� �����ϼ��� >> ";
			int cmd;
			cin >> cmd;

			if (cmd == sz + 1)
				break;

			if (cmd < 1 || cmd > sz + 1) // �߸��� ����
				continue;

			v[cmd - 1]->command(); 

		}
	}

};

int main()
{
	PopupMenu* menubar = new PopupMenu("MENUBAR");
	PopupMenu* p1 = new PopupMenu("ȭ�� ����");
	PopupMenu* p2 = new PopupMenu("�Ҹ� ����");

	menubar->addMenu(p1);
	p1->addMenu(p2);
	// menubar->addMenu(p2);

	p1->addMenu(new MenuItem("�ػ� ����", 10));
	p1->addMenu(new MenuItem("���� ����", 11));
	p1->addMenu(new MenuItem("��Ÿ ����", 12));

	p2->addMenu(new MenuItem("���� ����", 20));
	p2->addMenu(new MenuItem("���� ����", 21));

	menubar->command();
}