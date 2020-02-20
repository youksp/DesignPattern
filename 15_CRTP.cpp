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
//      => 부모 클래스가 템플릿인데 자식에서 템플릿 인자로 자신의 타입의 이름을 전달하는 기술
//      => 다양한 활용이 가능한데, 위 코드는 비가상함수를 가상함수처럼 동작하게 만드는 기법
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