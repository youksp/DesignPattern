#include <iostream>
using namespace std;


class Hero
{
	int level;
	int item;
public:
	// �������� ���¿� ���� �ٸ� �ൿ�� �ϰ� �ʹ�.
	// 1. �������� ������ �ٸ� ���� �б� �ڵ�
	//  ������: �ű� �������� �߰��ʿ� ���� ���� �б⹮�� �߰��Ǿ�� �Ѵ�.
	//    => OCP�� ������ �� ����.
	void run() 
	{
		if (item == 1)
		{
			cout << "Run" << endl;
		}
		else if (item == 2)
		{
			cout << "Fast Run" << endl;
		}
	}
	void attack() { cout << "Attack" << endl; }
};

int main()
{
	Hero h;
	h.run();
}

#if 0
class Hero
{
	int level;
	int item;
public:
	void run() { cout << "Run" << endl; }
	void attack() { cout << "Attack" << endl; }
};

int main()
{
	Hero h;
	h.run();
}
#endif