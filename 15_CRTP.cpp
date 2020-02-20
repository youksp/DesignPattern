// 15_CRTP
#include <iostream>
using namespace std;

template <typename T>
class Window
{
public:
	void msgLoop()  // msgLoop(Window* this)
	{
		static_cast<T*>(this)->onClick();  // this->onClick();
	}

	void onClick() {}
};

// CRTP: Mixin Template
//       Curiosly Recurring Template Pattern
//      => �θ� Ŭ������ ���ø��ε� �ڽĿ��� ���ø� ���ڷ� �ڽ��� Ÿ���� �̸��� �����ϴ� ���
//      => �پ��� Ȱ���� �����ѵ�, �� �ڵ�� �񰡻��Լ��� �����Լ�ó�� �����ϰ� ����� ���
//      => C++ Idioms

// WTL: Microsoft Windows Template Library

class MyWindow : public Window<MyWindow>
{
public:
	void onClick() { cout << "MyWindow onClick()" << endl; }
};

int main()
{
	MyWindow w;
	w.msgLoop();
}