// 13_�޴��̺�Ʈ.cpp
#include <iostream>
using namespace std;

class MenuItem
{
	int id;
public:
	MenuItem(int n) : id(n) {}

	virtual void command()
	{
		// �޴��� ���õ� ����� �ٽ� �ܺη� �˷��� �Ѵ�.
		// "��ü�� �ܺη� �̺�Ʈ�� �߻��Ѵ�" ��� ǥ���մϴ�.
	}
};

int main()
{
	MenuItem m1(10), m2(12);
	m1.command();
}