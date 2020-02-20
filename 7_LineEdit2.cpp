// 7_LineEdit.cpp
#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

// 1. Validation ��å�� ������ �����ؾ� �Ѵ�.
// ��� 1.
//  : ���ϴ� ��å�� �����Լ�ȭ �Ѵ�. - Template Method Pattern
//   -> ������ �ʴ� �ڵ�(���뼺)���� ���ؾ� �ϴ� ��(������)�� �ִٸ�,
//      ���ؾ� �ϴ� ���� �����Լ��� �̾Ƴ���.

// �Ѱ���
//  1) ���� �ð��� ��å�� ������ �� ����.
//  2) ��å�� ���뼺�� ���ڴ�.


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