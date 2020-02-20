#include <iostream>
#include <vector>
using namespace std;

// 1. ����� �߰��Ǿ ���� �ڵ�� �����Ǹ� �ȵȴ�.
// 2. �������� OCP�� �����Ѵ�.

// 3. Prototype Pattern
//   : ������ �����ϴ� ��ü�� �����Ͽ�, ���ο� ��ü�� ����� ����.
//     Clone()
//     �ߺ��� ���� ����

// 4. Replace type code with polymorphism => �����丵�� ��� �Դϴ�.
// 5. ���뼺�� �������� �и�
//     ��� �Լ�
//        : ������ �ʴ� ��ü �˰����� �θ��� �� �����Լ��� �����ϰ�,
//          ���ؾ� �ϴ� �κ��� �����Լ�ȭ�ؼ� �ڽ��� ������ �� �ֵ��� �ϴ� ����
//     => Template Method Pattern

// 6. �����Լ��� �ϳ��� ���ԵǾ� �ִ� Ŭ������ �ݵ�� �Ҹ��ڸ� ���� �Ҹ��ڷ� ������ �Ѵ�.

class Shape
{
public:
	virtual ~Shape() {}

	void Draw() {
		cout << "Lock" << endl;
		DrawImpl();
		cout << "Unlock" << endl;
	}

	virtual void DrawImpl() { cout << "Shape Draw" << endl;  }

	virtual Shape* Clone() { return new Shape(*this); }
};

class Rect : public Shape
{
public:
	void DrawImpl() {
		cout << "Rect Draw" << endl;
	}

	// ���� ��ȯ�� ��
	// : ��ȯ Ÿ���� ���� Ÿ������ ����ϴ°��� �����ϴ�.
	//   Template / Generic
	virtual Rect* Clone() { return new Rect(*this); }
};


class Circle : public Shape
{
public:
	void DrawImpl() {
		cout << "Circle Draw" << endl;
	}

	virtual Circle* Clone() { return new Circle(*this); }
};

int main()
{
	Rect* r = new Rect;
	Rect* r2 = r->Clone();

	vector<Shape*> shapes;

	while (1)
	{
		int cmd;
		cin >> cmd;

		if (cmd == 1) shapes.push_back(new Rect);
		else if (cmd == 2) shapes.push_back(new Circle);
		else if (cmd == 8) {
			cout << "���° ������ �����ұ��? >> ";
			int k;
			cin >> k;

			shapes.push_back(shapes[k]->Clone());
		}
		else if (cmd == 9) {
			for (int i = 0; i < shapes.size(); i++)
				shapes[i]->Draw();
		}
	}

}

#if 0
class Shape
{
public:
	virtual void Draw() {
		cout << "Lock" << endl;
		cout << "Shape Draw" << endl; 
		cout << "Unlock" << endl;
	}

	virtual Shape* Clone() { return new Shape(*this); }
};

class Rect : public Shape
{
public:
	void Draw() { 
		cout << "Lock" << endl;
		cout << "Rect Draw" << endl; 
		cout << "Unlock" << endl;
	}

	virtual Shape* Clone() { return new Rect(*this); }
};


class Circle : public Shape
{
public:
	void Draw() { 
		cout << "Lock" << endl;
		cout << "Circle Draw" << endl;
		cout << "Unlock" << endl;
	}

	virtual Shape* Clone() { return new Circle(*this); }
};

int main()
{
	vector<Shape*> shapes;

	while (1)
	{
		int cmd;
		cin >> cmd;

		if (cmd == 1) shapes.push_back(new Rect);
		else if (cmd == 2) shapes.push_back(new Circle);
		else if (cmd == 8) {
			cout << "���° ������ �����ұ��? >> ";
			int k;
			cin >> k;

			shapes.push_back(shapes[k]->Clone());

			// k��° ������ ���纻�� v�� �߰��Ѵ�.
			// k��° ������ ���� Ÿ������ �� �� ����....
			// shapes[k]
#if 0
			switch (shapes[k].type)
			{
			case 0: shapes.push_back(new Rect(*v[k])); break;
			case 1: shapes.push_back(new Circle(*v[k])); break;
			}
#endif
		}
		else if (cmd == 9) {
			for (int i = 0; i < shapes.size(); i++)
				shapes[i]->Draw();
		}
	}

}
#endif