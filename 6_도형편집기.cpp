#include <iostream>
#include <vector>
using namespace std;
// 6_����������
// ���������� ������ ���� ��ü ���� ������ ����

// 1. ��� ������ Ÿ��ȭ �ϸ� ���ϴ�.
// 2. OCP: Open Close Principle
//         ���� ����� ��Ģ
//         => �������� ���� �ְ�, Ȯ�忡�� ���� �־�� �Ѵ�.
//         => ���ο� ����� �߰��Ǿ, ���� �ڵ�� �����Ǹ� �ȵȴ�.
// 3. ��� ������ ������ �θ� �ִٸ�, ��� ������ ��� ������ �� �ִ�.
// 4. ��� �ڽ��� ������ Ư¡�� �ִٸ�, �ݵ�� �θ𿡵� �־�� �Ѵ�.
//    �׷��� �θ��� �����͸� ���� ��� ����� ��, �ش� Ư¡�� �̿��� �� �ִ�.
//     LSP(Liskov Substitution Principle)
//     : �ڽ� Ŭ������ �θ� Ŭ������ ��ü�� �� �־�� �Ѵ�.
// 5. �θ��� �Լ��� �ڽ��� �������ϴ� ��� �Լ��� �ݵ�� �����Լ��̾�� �Ѵ�.
//     Effectice C++ : �����Լ��� �ƴ� �Լ��� ���������� ����.

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