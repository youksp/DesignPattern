// 28_���Ͻ�
#include <iostream>
#include <conio.h>
#include "ioacademy.h"

using namespace std;
using namespace ioacademy;


// ���� ��Ҹ� ����� Ŭ������ ����� ����ϴ� �� - Proxy Pattern
// 1. Smart Proxy: ���� ��ҿ� �߰����� �۾��� �����ϴ� �� ex)Smart Pointer
// 2. Remote Proxy: IPC, Network ������ ����ϴ� Ŭ����

class Calc
{
	int handle;
public:
	Calc() { handle = IoFindServer("CalcServer"); }

	int Add(int a, int b)
	{
		return IoSendServer(handle, 1, a, b);
	}

	int Sub(int a, int b)
	{
		return IoSendServer(handle, 2, a, b);
	}
};


#if 1
int main()
{
	Calc* calc = new Calc;

	while (1)
	{
		getch();
		cout << calc->Add(10, 20) << endl;
		getch();
		cout << calc->Sub(20, 2) << endl;
	}
}
#endif


#if 0
int main()
{
	int handle = IoFindServer("CalcServer");
	cout << "���� ��ȣ: " << handle << endl;

	while (1)
	{
		getch();
		cout << IoSendServer(handle, 1, 10, 20) << endl;
		getch();
		cout << IoSendServer(handle, 2, 30, 8) << endl;
	}
}
#endif

// �� 23���� - GoF's Design Pattern
// ���� ����(5) Prototype, Singleton, Abstract Factory, Factory Method
// ���� ����(7) Adapter, Proxy, Bridge, Facade, Composite, Decorator, Flyweight
// ���� ����(11)

// 0. Interpreter
// 1. Adapter
// 2. Prototype
// 3. Strategy
// 4. Template Method
// 5. Singleton
// 6. Abstract Factory
// 7. Factory Method
// 8. Composite
// 9. Command
// 10. Observer
// 11. Flyweight
// 12. Visitor
// 13. Iterator
// 14. Proxy
// 15. Builder
// 16. Chain of Responsiblity

// 16. State - *
// 17. Facade
// 18. Memento
// 19. Bridge
// 20. Mediator
// 21. Decorator - *
// 22. Builder - *
