#include <iostream>
#include <vector>
using namespace std;

// 1. 기능이 추가되어도 기존 코드는 수정되면 안된다.
// 2. 다형성은 OCP를 만족한다.

// 3. Prototype Pattern
//   : 기존에 존재하는 객체를 복제하여, 새로운 객체를 만드는 패턴.
//     Clone()
//     견본에 의한 생성

// 4. Replace type code with polymorphism => 리팩토링의 용어 입니다.
// 5. 공통성과 가변성의 분리
//     멤버 함수
//        : 변하지 않는 전체 알고리즘은 부모의 비 가상함수가 제공하고,
//          변해야 하는 부분은 가상함수화해서 자식이 변경할 수 있도록 하는 설계
//     => Template Method Pattern

// 6. 가상함수가 하나라도 포함되어 있는 클래스는 반드시 소멸자를 가상 소멸자로 만들어야 한다.

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

	// 공변 반환의 룰
	// : 반환 타입을 하위 타입으로 명시하는것이 가능하다.
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
			cout << "몇번째 도형을 복제할까요? >> ";
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
			cout << "몇번째 도형을 복제할까요? >> ";
			int k;
			cin >> k;

			shapes.push_back(shapes[k]->Clone());

			// k번째 도형의 복사본을 v에 추가한다.
			// k번째 도형은 무슨 타입인지 알 수 없다....
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