// 데코레이터 패턴
#include <iostream>
using namespace std;

// 개념: 재귀적 포함을 통한 동적인 기능의 확장이 가능하다.
//  => 포장지는 객체를 포장하지만, 포장된 객체를 다시 포장할 수 있어야 한다.
//  => 포장지와 객체는 동일 부모가 필요하다!

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
		cout << "작은 음악회 - 2020.12.25" << endl;
	}
};

class Ad1 : public Item
{
	Item& ticket; // 포함!
public:
	Ad1(Item& t) : ticket(t) {}

	void print()
	{
		ticket.print();
		cout << "자동차 광고" << endl;
	}
};

class Ad2 : public Item
{
	Item& ticket; // 포함!
public:
	Ad2(Item& t) : ticket(t) {}

	void print()
	{
		cout << "TV 광고" << endl;
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
		cout << "작은 음악회 - 2020.12.25" << endl;
	}
};

// 상속: 기존 클래스에 기능을 추가할 수 있는 문법
class Ad1 : public Ticket
{
public:
	void print()
	{
		Ticket::print(); // 원래 기능을 사용한 후에
		cout << "자동차 광고" << endl;
	}
};


class Ad2 : public Ad1
{
public:
	void print()
	{
		cout << "TV 광고" << endl;
		Ad1::print();
	}
};

// 상속: 정적인 기능의 확장
// 포함: 동적인 기능의 확장

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