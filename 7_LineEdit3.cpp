// 7_LineEdit.cpp
#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

// ���ϴ� ���� �и��ϴ� ��� 2����
// 1) �����Լ��� �и�
// 2) �������̽� ��� Ŭ������ �и� - ����(Strategy) ����
//  - ����ð��� ��å�� ��ü�ϴ� ���� �����ϴ�.
//  - ��å Ŭ������ ������ �� �ִ�.

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

// ��å Ŭ������ ���Ӱ� �����ϸ� �˴ϴ�.
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