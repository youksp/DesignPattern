#include <map>
#include <iostream>
using namespace std;

#include "ioacademy.h"
using namespace ioacademy;

// �Ʒ��� ����� ���� �Լ��� ������ ���� ���� �Լ� ���̺��� ũ�Ⱑ �þ�� ������ �߻��Ѵ�.
// �����찡 �����ϰ� �ִ� �̺�Ʈ�� ������ ���鰳�� �Ѵ´�.
// => �޼��� ���̶�� ���踦 ���ؼ� �ذ�

class Window;
struct AFX_MSG
{
	int message;					// �޼��� ��ȣ
	void (Window::*handler)();      // ó���� �Լ� �ּ�
};


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

	// �Ʒ� �����Լ����� �迭�� �����մϴ�.
	virtual AFX_MSG* GetMessageMap() { return 0; }

	static int foo(int handle, int msg, int param1, int param2)
	{
		Window* self = this_map[handle];
		if (self == 0)
			return 0;

		// 1. �迭�� ���´�.
		AFX_MSG* msgArray = self->GetMessageMap();
		if (msgArray == 0)
			return 0;

		// 2. �迭�� ���� �޼����� �ִ��� Ȯ���Ѵ�.
		for (; msgArray->message != 0; msgArray++)
		{
			if (msgArray->message == msg)
			{
				void(Window::*f)() = msgArray->handler;
				(self->*f)();
			}
		}
		
		
		return 0;
	}
};

map<int, Window*> Window::this_map;


#define BEGIN_MESSAGE_MAP()				\
virtual AFX_MSG* GetMessageMap()        \
{										\
	typedef void(Window::*HANDLER)();	\
	static AFX_MSG msgMap[] = {

#define END_MESSAGE_MAP()				\
{ 0, 0 },								\
};										\
return msgMap;							\
}

#define ADD_MAP(message, handler)		\
	{ message, static_cast<HANDLER>(handler) },


//----------------------------
class MyWindow : public Window
{
public:
	// ���� ����ڴ� �Ʒ� �����Լ��� �������ؼ� �迭�� ��ȯ�ؾ� �մϴ�.
	BEGIN_MESSAGE_MAP()
		ADD_MAP(WM_LBUTTONDOWN, &MyWindow::OnLButtonDown)
		ADD_MAP(WM_KEYDOWN, &MyWindow::OnKeyDown)
	END_MESSAGE_MAP()

	void OnLButtonDown() { cout << "LBUTTON" << endl; }
	void OnKeyDown() { cout << "KeyDown" << endl; }
};

#if 0
class MyWindow : public Window
{
public:
	// ���� ����ڴ� �Ʒ� �����Լ��� �������ؼ� �迭�� ��ȯ�ؾ� �մϴ�.
	virtual AFX_MSG* GetMessageMap()
	{
		typedef void(Window::*HANDLER)();
		
		static AFX_MSG msgMap[] = {
			{ WM_LBUTTONDOWN, static_cast<HANDLER>(&MyWindow::OnLButtonDown) },
			{ 0, 0 },
		};

		return msgMap;
	}


	void OnLButtonDown() { cout << "LBUTTON" << endl; }
	void OnKeyDown() { cout << "KeyDown" << endl; }
};
#endif

int main()
{
	MyWindow w;
	w.Create();   // �� ���� �����찡 ��������ϴ�.
				  // ���� ��ư�� ������ "LBUTTON"�̶�� ��µǾ�� �մϴ�.

	IoProcessMessage();
}