// 14_�޼�����

#include <vector>
#include <map>
#include <iostream>
using namespace std;

#include "ioacademy.h"
using namespace ioacademy;

// Chain of Responsibility(å���� ����, å���� ��)
//  => �̺�Ʈ �߻��� ó������ ���� ��� ���� ��ü���� �����Ѵ�.
//     ó���� ������ ���� ���� �̺�Ʈ�� �����Ѵ�.

//  => �̺�Ʈ�� �̺�Ʈ ó�� ��ü�� ���յ��� ���� �� �ִ�.

class Window
{
	int handle;
	static map<int, Window*> this_map;

	// �θ� ������� 1�� �̴�.
	Window* parent;
	vector<Window*> child_vector;
public:
	Window() : parent(0) {}

	// �����츦 �ڽ� ������� ������ִ� �Լ�
	void AddChild(Window* p)
	{
		p->parent = this;
		child_vector.push_back(p);

		// �ڽ� ������� ���δ�.
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

	// �Ʒ��ڵ尡 �ٽ��Դϴ�.
	void FireLButtonDown()
	{
		// 1. ���� �ڽ��� ó���� �õ��մϴ�.
		if (OnLButtonDown() == true)
			return;

		// 2. �̺�Ʈ�� ó������ ���� ���
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