// 13_�޴��̺�Ʈ2.cpp
#include <iostream>
using namespace std;

// 1. �������̽� ��� ������ ����
//   :  Java, Android, Ÿ����(C++)

// �޴��� ó���ϰ� ���� ��� Ŭ������ �Ʒ� �������̽��� �����ؾ� �Ѵ�.
struct IMenuListener
{
	// � ��ü�κ��� �̺�Ʈ�� �߻��ߴ��� �� �� ����.
	// id�� ���� �б⹮�� �߻��Ѵ�.
	virtual void onCommand(int id) = 0;
	virtual ~IMenuListener() {}
};


class MenuItem
{
	int id;
	IMenuListener* listener;
public:
	MenuItem(int n) : id(n) {}
	void setListener(IMenuListener* p) { listener = p; }

	virtual void command()
	{
		// �޴��� ���õ� ����� �ٽ� �ܺη� �˷��� �Ѵ�.
		// "��ü�� �ܺη� �̺�Ʈ�� �߻��Ѵ�" ��� ǥ���մϴ�.
		if (listener)
			listener->onCommand(id);
	}
};

class Dialog : public IMenuListener
{
public:
	void open() { cout << "Dialog open" << endl; }
	void close() { cout << "Dialog close" << endl; }

	virtual void onCommand(int id)
	{
		switch (id)
		{
		case 10:
			open();
			break;
		case 12:
			close();
			break;
		}
	}
};


int main()
{
	MenuItem m1(10), m2(12);
	Dialog dialog;

	m1.setListener(&dialog);
	m2.setListener(&dialog);

	m1.command();
	m2.command();
}