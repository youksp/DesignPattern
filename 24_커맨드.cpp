// 24_커맨드
#include <iostream>
#include <vector>
using namespace std;

// Command 패턴
//  : 명령을 객체로 캡슐화 하면 된다.

class Shape
{
public:
	virtual void Draw() { cout << "Shape Draw" << endl; }
};

class Rect : public Shape
{
public:
	void Draw() { cout << "Rect Draw" << endl; }
};


class Circle : public Shape
{
public:
	void Draw() { cout << "Circle Draw" << endl; }
};

// 인터페이스를 먼저 설계합니다.
struct ICommand
{
	virtual void Execute() = 0;
	
	// virtual bool CanUndo() = 0;
	// virtual void Undo() = 0;

	virtual bool CanUndo() { return false; }
	virtual void Undo() {}

	virtual ~ICommand() {}
};

// 도형을 추가하는 명령의 부모 클래스

// Factory Method: Template Method Pattern의 모양과 동일한데
//                 자식이 재정의하는 가상함수가 하는 일이 알고리즘(정책)의 변경이 아닌
//                 객체 생성일 때

class AddCommand : public ICommand
{
	vector<Shape*>& v;
public:
	AddCommand(vector<Shape*>& p) : v(p) {}

	virtual bool CanUndo() { return true; }
	virtual void Undo()
	{
		Shape* p = v.back();
		v.pop_back();
		delete p;
	}

	virtual void Execute()
	{
		v.push_back(CreateShape());
	}

	virtual Shape* CreateShape() = 0;
};

// 사각형을 추가하는 명령
class AddRectCommand : public AddCommand
{
public:
	AddRectCommand(vector<Shape*>& p) : AddCommand(p) {}

	virtual Shape* CreateShape() { return new Rect; }
};

class AddCircleCommand : public AddCommand
{
public:
	AddCircleCommand(vector<Shape*>& p) : AddCommand(p) {}

	virtual Shape* CreateShape() { return new Circle; }
};

class DrawCommand : public ICommand
{
	vector<Shape*>& v;
public:
	DrawCommand(vector<Shape*>& p) : v(p) {}

	virtual void Execute()
	{
		for (auto e : v)
			e->Draw();
	}
};

class MacroCommand : public ICommand
{
	vector<ICommand*> v;
public:
	void AddCommand(ICommand* p) { v.push_back(p); }

	virtual void Execute()
	{
		for (auto e : v)
			e->Execute();
	}
};


#include <stack>

int main()
{
	vector<Shape*> shapes;

	MacroCommand m;
	m.AddCommand(new AddRectCommand(shapes));
	m.AddCommand(new AddCircleCommand(shapes));
	m.Execute();



	stack<ICommand*> undo_stack;
	stack<ICommand*> redo_stack;

	while (1)
	{
		ICommand* p = 0;
		int cmd;
		cin >> cmd;

		if (cmd == 1) p = new AddRectCommand(shapes);
		else if (cmd == 2) p = new AddCircleCommand(shapes);
		else if (cmd == 9) {
			p = new DrawCommand(shapes);
		}
		else if (cmd == 3) {
			p = redo_stack.top();
			redo_stack.pop();
		}
		else if (cmd == 0) {
			ICommand* undo = undo_stack.top();
			undo_stack.pop();

			undo->Undo();
			redo_stack.push(undo);
			continue;
		}

		if (p != 0)
		{
			p->Execute();
			if (p->CanUndo())
				undo_stack.push(p);
		}
	}

}


#if 0
int main()
{
	vector<Shape*> shapes;

	while (1)
	{
		int cmd;
		cin >> cmd;

		if (cmd == 1) shapes.push_back(new Rect);
		else if (cmd == 2) shapes.push_back(new Circle);
		else if (cmd == 9) {
			for (int i = 0; i < shapes.size(); i++)
				shapes[i]->Draw();
		}
	}

}
#endif