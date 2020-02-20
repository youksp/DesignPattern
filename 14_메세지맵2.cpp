#include <map>
#include <iostream>
using namespace std;

#include "ioacademy.h"
using namespace ioacademy;

// 아래의 설계는 가상 함수가 많아질 수록 가상 함수 테이블의 크기가 늘어나는 문제가 발생한다.
// 윈도우가 정의하고 있는 이벤트의 개수는 수백개가 넘는다.
// => 메세지 맵이라는 설계를 통해서 해결

class Window;
struct AFX_MSG
{
	int message;					// 메세지 번호
	void (Window::*handler)();      // 처리할 함수 주소
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

	// 아래 가상함수에서 배열을 리턴합니다.
	virtual AFX_MSG* GetMessageMap() { return 0; }

	static int foo(int handle, int msg, int param1, int param2)
	{
		Window* self = this_map[handle];
		if (self == 0)
			return 0;

		// 1. 배열을 얻어온다.
		AFX_MSG* msgArray = self->GetMessageMap();
		if (msgArray == 0)
			return 0;

		// 2. 배열에 현재 메세지가 있는지 확인한다.
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
	// 이제 사용자는 아래 가상함수를 재정의해서 배열을 반환해야 합니다.
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
	// 이제 사용자는 아래 가상함수를 재정의해서 배열을 반환해야 합니다.
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
	w.Create();   // 이 순간 윈도우가 만들어집니다.
				  // 왼쪽 버튼을 누르면 "LBUTTON"이라고 출력되어야 합니다.

	IoProcessMessage();
}