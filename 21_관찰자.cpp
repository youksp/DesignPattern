// 21_관찰자
#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include "ioacademy.h"
using namespace ioacademy;

// 1. 개념: 하나의 이벤트를 여러 객체에 전달
// 2. Subject의 data를 전달하는 방식
//   1) Subject가 Observer에게 전달 - push
//   2) Observer가 Subject로 부터 꺼내가는 방식 - pull

struct IObserver
{
	virtual void OnUpdate(void* data) = 0;
	virtual ~IObserver() {}
};

// 관찰의 대상
// 모든 Table의 공통의 특징(관찰자 패턴의 기본로직)은 항상 동일하다.
// 부모 클래스로 뽑아내자.
// - 달라지는 것은 자식 클래스를 통해 변경, 공통적인 것은 부모 클래스를 통해 제공하자.
class Subject
{
	vector<IObserver*> v;
public:
	Subject()
	{
		// 약속된 디렉토리의 모든 DLL을 열거한다.
		IoEnumFiles("D:\\Plugin", "*.dll", LoadModule, this);
	}

	static int LoadModule(string name, void* param)
	{
		cout << name << endl;
		// 1. DLL Load
		void* addr = IoLoadModule(name);

		// 2. 약속된 함수 CreateGraph를 찾습니다.
		// IObserver* CreateGraph()
		typedef IObserver* (*FP)();

		FP f = (FP)IoGetFunctionAddress(addr, "CreateGraph");

		// 3. 그래프 생성
		IObserver* p = f();
		Subject* self = static_cast<Subject*>(param);
		self->Attach(p);

		return 1;
	}


	void Attach(IObserver* p) { v.push_back(p); }
	void Detach(IObserver* p) {}

	void Notify(void *data)
	{
		for (int i = 0; i < v.size(); ++i)
			v[i]->OnUpdate(data);
	}
};

class Table: public Subject
{
	int data[5];
public:
	Table() { memset(data, 0, sizeof(data)); }

	void Edit()
	{
		while (1)
		{
			int index;
			cout << "index: "; cin >> index;
			cout << "data: "; cin >> data[index];

			Notify(data);
		}
	}
};

class BarGarch : public IObserver
{
public:
	void OnUpdate(void* p)
	{
		int* data = static_cast<int*>(p);
		cout << "*************** Bar Graph *************" << endl;
		for (int i = 0; i < 5; ++i)
			cout << i << ": " << data[i] << endl;
	}
};

class PieGraph : public IObserver
{
public:
	void OnUpdate(void* p)
	{
		int* data = static_cast<int*>(p);
		cout << "*************** Pie Graph *************" << endl;
		for (int i = 0; i < 5; ++i)
			cout << i << ": " << data[i] << endl;
	}
};

int main()
{
	Table table;
	PieGraph pg;
	BarGarch bg;

	table.Attach(&pg);
	table.Attach(&bg);

	table.Edit();
}