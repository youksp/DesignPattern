// 7_LineEdit.cpp
#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

// 변하는 것을 분리하는 방법 2가지
// 1) 가상함수로 분리
// 2) 인터페이스 기반 클래스로 분리 - 전략(Strategy) 패턴
//  - 실행시간에 정책을 교체하는 것이 가능하다.
//  - 정책 클래스를 재사용할 수 있다.

struct IValidator
{
	virtual bool validate(string s, char c) = 0;
	virtual ~IValidator() {}
};

class LineEdit
{
	string data;
	IValidator* pValidator;
public:
	LineEdit() : pValidator(0) {}
	
	void SetValidator(IValidator* p) { pValidator = p; }

	string GetData()
	{
		data.clear();
		while (1)
		{
			char c = getch();
			if (c == 13)  // enter
				break;

			if (pValidator == 0 || pValidator->validate(data, c))
			{
				data.push_back(c);
				cout << c;
			}
		}
		cout << endl;
		return data;
	}
};

// 정책 클래스를 새롭게 제공하면 됩니다.
class DigitValidator : public IValidator
{
public:
	virtual bool validate(string s, char c)
	{
		return isdigit(c);
	}
};

int main()
{
	LineEdit edit;
	DigitValidator v;
	edit.SetValidator(&v);

	while (1)
	{
		string s = edit.GetData();
		cout << s << endl;
	}
}