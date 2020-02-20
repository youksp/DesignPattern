// 14_�޼�����

#include <map>
#include <iostream>
using namespace std;

#include "ioacademy.h"
using namespace ioacademy;

class Window
{
	int handle;
	static map<int, Window*> this_map;
public:
	void Create()
	{
		handle = IoMakeWindow(foo);
		this_map[handle] = this;
	}

	static int foo(int handle, int msg, int param1, int param2)
	{
		Window* self = this_map[handle];
		switch (msg)
		{
		case WM_LBUTTONDOWN:
			self->OnLButtonDown();
			break;
		case WM_KEYDOWN:
			self->OnKeyDown();
			break;
		}
		return 0;
	}

	virtual void OnLButtonDown() {}
	virtual void OnKeyDown() {}
};

map<int, Window*> Window::this_map;

//----------------------------
class MyWindow : public Window
{
public:
	virtual void OnLButtonDown() { cout << "LBUTTON" << endl; }
	virtual void OnKeyDown() { cout << "KeyDown" << endl; }
};

int main()
{
	MyWindow w;
	w.Create();   // �� ���� �����찡 ��������ϴ�.
				  // ���� ��ư�� ������ "LBUTTON"�̶�� ��µǾ�� �մϴ�.

	IoProcessMessage();
}



#if 0
int foo(int handler, int msg, int param1, int param2)
{
	switch (msg)
	{
	case WM_LBUTTONDOWN:
		cout << "LBUTTONDOWN" << endl;
		break;
	}
	return 0;
}

int main()
{
	int h1 = IoMakeWindow(foo);

	IoProcessMessage();
}
#endif