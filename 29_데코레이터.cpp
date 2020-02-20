// ���ڷ����� ����
#include <iostream>
using namespace std;

// ����: ����� ������ ���� ������ ����� Ȯ���� �����ϴ�.
//  => �������� ��ü�� ����������, ����� ��ü�� �ٽ� ������ �� �־�� �Ѵ�.
//  => �������� ��ü�� ���� �θ� �ʿ��ϴ�!

struct Item
{
	virtual void print() = 0;
	virtual ~Item() {}
};

class Ticket : public Item
{
public:
	void print()
	{
		cout << "���� ����ȸ - 2020.12.25" << endl;
	}
};

class Ad1 : public Item
{
	Item& ticket; // ����!
public:
	Ad1(Item& t) : ticket(t) {}

	void print()
	{
		ticket.print();
		cout << "�ڵ��� ����" << endl;
	}
};

class Ad2 : public Item
{
	Item& ticket; // ����!
public:
	Ad2(Item& t) : ticket(t) {}

	void print()
	{
		cout << "TV ����" << endl;
		ticket.print();
	}
};

int main()
{
	Ticket ticket;
	Ad1 ad1(ticket);
	Ad2 ad2(ad1);

	ad2.print();
}


#if 1
class Ticket
{
public:
	void print()
	{
		cout << "���� ����ȸ - 2020.12.25" << endl;
	}
};

// ���: ���� Ŭ������ ����� �߰��� �� �ִ� ����
class Ad1 : public Ticket
{
public:
	void print()
	{
		Ticket::print(); // ���� ����� ����� �Ŀ�
		cout << "�ڵ��� ����" << endl;
	}
};


class Ad2 : public Ad1
{
public:
	void print()
	{
		cout << "TV ����" << endl;
		Ad1::print();
	}
};

// ���: ������ ����� Ȯ��
// ����: ������ ����� Ȯ��

int main()
{
	Ad2 ticket;
	ticket.print();
}

#endif

#if 0
FileInputStream fs = new FileInputStream("a.txt");
BufferedInputStream bis = new BufferedInputStream(fs);
ZipInputStream zis = new ZipInputStream(bis);
zis.read();



#endif