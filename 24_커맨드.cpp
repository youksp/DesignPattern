// 24_Ŀ�ǵ�
#include <iostream>
#include <vector>
using namespace std;

// Command ����
//  : ����� ��ü�� ĸ��ȭ �ϸ� �ȴ�.

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

// �������̽��� ���� �����մϴ�.
struct ICommand
{
	virtual void Execute() = 0;
	
	// virtual bool CanUndo() = 0;
	// virtual void Undo() = 0;

	virtual bool CanUndo() { return false; }
	virtual void Undo() {}

	virtual ~ICommand() {}
};

// ������ �߰��ϴ� ����� �θ� Ŭ����

// Factory Method: Template Method Pattern�� ���� �����ѵ�
//                 �ڽ��� �������ϴ� �����Լ��� �ϴ� ���� �˰���(��å)�� ������ �ƴ�
//                 ��ü ������ ��

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

// �簢���� �߰��ϴ� ���
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