#include <iostream>
#include <vector>
using namespace std;
// 6_도형편집기
// 도형편집기 예제로 배우는 객체 지향 설계의 개념

// 1. 모든 도형을 타입화 하면 편리하다.
// 2. OCP: Open Close Principle
//         개방 폐쇄의 원칙
//         => 수정에는 닫혀 있고, 확장에는 열려 있어야 한다.
//         => 새로운 기능이 추가되어도, 기존 코드는 수정되면 안된다.
// 3. 모든 도형의 공통의 부모가 있다면, 모든 도형을 묶어서 관리할 수 있다.
// 4. 모든 자식의 공통의 특징이 있다면, 반드시 부모에도 있어야 한다.
//    그래야 부모의 포인터를 통해 묶어서 사용할 때, 해당 특징을 이용할 수 있다.
//     LSP(Liskov Substitution Principle)
//     : 자식 클래스는 부모 클래스로 대체할 수 있어야 한다.
// 5. 부모의 함수중 자식의 재정의하는 모든 함수는 반드시 가상함수이어야 한다.
//     Effectice C++ : 가상함수가 아닌 함수는 재정의하지 말라.

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