#include <iostream>
using namespace std;

// �Ϲ� �Լ��� ��� Ŭ������ ��� �Լ� �����͸� ������ �� �ִ� ������ �Լ� ������
// Ÿ���� �����غ��ô�.

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

// Ŭ���� ���ø��� �Ͻ��� �߷��� �Ұ����ؼ� �׻� ������ ���Դϴ�.
// �Ͻ��� �߷��� ������ �Լ� ���ø����� ���� �Լ��� �����սô�.
template <typename T>
MemberCommand<T>* cmd(void(T::*handler)(), T* object)
{
	return new MemberCommand<T>(handler, object);
}

// ���̺귯���� �ϰ����� ���� Function Command�� ����� �Լ��� �����մϴ�.
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