// 14_메세지맵

#include <vector>
#include <map>
#include <iostream>
using namespace std;

#include "ioacademy.h"
using namespace ioacademy;

// Chain of Responsibility(책임의 전가, 책임의 고리)
//  => 이벤트 발생시 처리되지 않을 경우 다음 객체에게 전달한다.
//     처리될 때까지 고리에 따라 이벤트를 전달한다.

//  => 이벤트와 이벤트 처리 객체의 결합도를 낮출 수 있다.

class Window
{
	int handle;
	static map<int, Window*> this_map;

	// 부모 윈도우는 1개 이다.
	Window* parent;
	vector<Window*> child_vector;
public:
	Window() : parent(0) {}

	// 윈도우를 자식 윈도우로 등록해주는 함수
	void AddChild(Window* p)
	{
		p->parent = this;
		child_vector.push_back(p);

		// 자식 윈도우로 붙인다.
		IoAddChild(this->handle, p->handle);
	}

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
			// self->OnLButtonDown();
			self->FireLButtonDown();
			break;
		case WM_KEYDOWN:
			self->OnKeyDown();
			break;
		}
		return 0;
	}

	// 아래코드가 핵심입니다.
	void FireLButtonDown()
	{
		// 1. 먼저 자신이 처리를 시도합니다.
		if (OnLButtonDown() == true)
			return;

		// 2. 이벤트가 처리되지 않은 경우
		if (parent != 0)
			parent->FireLButtonDown();
	}


	virtual bool OnLButtonDown() { return false; }


	virtual void OnKeyDown() {}
};

map<int, Window*> Window::this_map;

//----------------------------
class MyWindow : public Window
{
public:
	virtual bool OnLButtonDown() { cout << "LBUTTON" << endl; return false; }
};

class ImageView : public Window
{
public:
	virtual bool OnLButtonDown() { cout << "ImageView LBUTTON" << endl; return true; }
};


int main()
{
	MyWindow w;
	w.Create();  

	ImageView v;
	v.Create();

	w.AddChild(&v);


	IoProcessMessage();
}