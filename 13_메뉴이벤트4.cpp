#include <iostream>
using namespace std;

// 일반 함수와 모든 클래스의 멤버 함수 포인터를 저장할 수 있는 범용적 함수 포인터
// 타입을 설계해봅시다.

void foo() { cout << "foo" << endl; }

class Dialog
{
public:
	void open() { cout << "open" << endl; }
};

struct ICommand
{
	virtual void execute() = 0;
	virtual ~ICommand() {}
};

template <typename T>
class MemberCommand : public ICommand
{
	typedef void(T::*HANDLER)();
	
	HANDLER handler;
	T* object;
public:
	MemberCommand(HANDLER h, T* p) : handler(h), object(p) {}

	void execute() { (object->*handler)(); }
};


class FunctionCommand : public ICommand
{
	typedef void(*HANDLER)();
	HANDLER handler;
public:
	FunctionCommand(HANDLER h) : handler(h) {}

	void execute() { handler(); }
};

// 클래스 템플릿은 암시적 추론이 불가능해서 항상 복잡해 보입니다.
// 암시적 추론이 가능한 함수 템플릿으로 헬퍼 함수를 제공합시다.
template <typename T>
MemberCommand<T>* cmd(void(T::*handler)(), T* object)
{
	return new MemberCommand<T>(handler, object);
}

// 라이브러리의 일관성을 위해 Function Command를 만드는 함수도 제공합니다.
FunctionCommand* cmd(void(*f)())
{
	return new FunctionCommand(f);
}

class MenuItem
{
	int id;
	ICommand* handler;
public:
	MenuItem(int n) : id(n) {}
	
	void setHandler(ICommand* p) { handler = p; }

	virtual void command()
	{
		handler->execute();
	}
};

int main()
{
	MenuItem m1(10), m2(12);
	Dialog dialog;

	m1.setHandler(cmd(&foo));
	m2.setHandler(cmd(&Dialog::open, &dialog));

	m1.command();
	m2.command();
}

#if 0
int main()
{
	Dialog dlg;
	// MemberCommand<Dialog> mfp(&Dialog::open, &dlg);

	ICommand* mfp = cmd(&Dialog::open, &dlg);
	mfp->execute();

	// FunctionCommand fp(&foo);
	ICommand* fp = cmd(&foo);
	fp->execute();
}
#endif