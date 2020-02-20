// 23_�̱���.cpp
#include <iostream>
using namespace std;

// ����: ���� �Ѱ��� ��ü�� ���� �� �ְ�, ������ �������
//       ��ü�� ���� �� �ְ� �ϴ� ����
class Cursor
{
	// ��Ģ 1. private ������
private:
	Cursor() {}

	// ��Ģ 2. ����� ������ �����ؾ� �Ѵ�.
	// => �ٽ�! ���� �Ѵ�. - C++98
	//    ��ũ ������ ���� ������ ���� ã�Ⱑ ��ƴ�.
	//    C++11/14���� ����/���� ������ ���� ������ �߰��Ǿ����ϴ�.
	//    "delete function"
	Cursor(const Cursor&) = delete;
	void operator=(const Cursor&) = delete;

public:
	// ��Ģ 3. ���� �Ѱ��� ����� ���� ��� �Լ�
	static Cursor& getInstance()
	{
		static Cursor instance;
		return instance;
	}
};


int main()
{
	Cursor& c1 = Cursor::getInstance();
	Cursor& c2 = Cursor::getInstance();
	cout << &c1 << ", " << &c2 << endl;
}