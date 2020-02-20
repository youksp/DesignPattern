// 7_LineEdit.cpp
#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

// 1. Validation 정책은 변경이 가능해야 한다.
// 방법 1.
//  : 변하는 정책을 가상함수화 한다. - Template Method Pattern
//   -> 변하지 않는 코드(공통성)에서 변해야 하는 것(가변성)이 있다면,
//      변해야 하는 것을 가상함수로 뽑아낸다.

// 한계점
//  1) 실행 시간에 정책을 변경할 수 없다.
//  2) 정책의 재사용성이 나쁘다.


class LineEdit
{
	string data;
public:
	virtual bool validate(char c) { return isdigit(c); }
	
	string GetData()
	{
		data.clear();
		while (1)
		{
			char c = getch();
			if (c == 13)  // enter
				break;

			if (validate(c))
			{
				data.push_back(c);
				cout << c;
			}
		}
		cout << endl;
		return data;
	}
};

class AddressEdit : public LineEdit
{
public:
	virtual bool validate(char c) {
		return true;
	}
};


int main()
{
	// LineEdit edit;
	AddressEdit edit;
	
	while (1)
	{
		string s = edit.GetData();
		cout << s << endl;
	}
}