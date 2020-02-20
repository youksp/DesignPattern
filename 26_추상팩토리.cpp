// 26_추상팩토리
#include <iostream>
using namespace std;

// GUI Look and feel - Qt

// 가상 소멸자는 편의상 생략하였습니다.
struct IButton { virtual void draw() = 0; };
struct IEdit { virtual void draw() = 0; };

struct XPEdit : IEdit {
	virtual void draw()
	{
		cout << "XPEdit draw" << endl;
	}
};
struct GTKEdit : IEdit {
	virtual void draw()
	{
		cout << "GTKEdit draw" << endl;
	}
};

struct XPButton: IButton {
	void draw() { cout << "XPButton Draw" << endl; }
};
struct GTKButton: IButton {
	void draw() { cout << "GTKButton Draw" << endl; }
};

// --style=GTK
//  main(int argc, char** argv)

// Abstract Factory Pattern
// : 공장도 인터페이스 기반으로 만들어서 교체 가능하게 하자.

struct IFactory
{
	virtual IButton* CreateButton() = 0;
	virtual IEdit* CreateEdit() = 0;
};

struct XPFactory : IFactory
{
	virtual IButton* CreateButton() { return new XPButton; }
	virtual IEdit* CreateEdit() { return new XPEdit; }
};

struct GTKFactory : IFactory
{
	virtual IButton* CreateButton() { return new GTKButton; }
	virtual IEdit* CreateEdit() { return new GTKEdit; }
};


int main()
{
	IFactory* factory;
	// if (strcmp(argv[1], "--style=GTK") == 0)
	if (true)
	{
		factory = new GTKFactory();
	}
	else
	{
		factory = new XPFactory();
	}

	IButton* button = factory->CreateButton();
	button->draw();
}

#if 0
int main()
{
	IEdit* edit;
	IButton* button;
	//....
	if (strcmp(argv[1], "--style=GTK") == 0)
	{
		button = new GTKButton;
		edit = new GTKEdit;
		//...
	}
	else
	{
		button = new XPButton;
		edit = new XPEdit;
		//...
	}



	// XPButton* button = new XPButton;
	// button->draw();
}
#endif