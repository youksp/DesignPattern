// 4_�Լ����ε�

#include <iostream>
using namespace std;


class Animal
{
public:
	virtual void Cry() { cout << "Animal Cry" << endl; }
};

class Dog : public Animal
{
public:
	void Cry() { cout << "Dog Cry" << endl; }
};

int main()
{
	Animal a; a.Cry();
	Dog d;    d.Cry();

	Animal* p = &d;

	int n;
	cin >> n;
	if (n == 0) p = &a;

	p->Cry();
}

// �Լ� ���ε�
// 1) static binding: � �Լ��� ȣ������� ������ Ÿ�ӿ� �����Ǵ� ��
//  : ������.
//  ȣ���ϴ� ��ü�� Ÿ�Կ� ���ؼ� �Լ��� �����ȴ�.

// 2) dynamic binding: � �Լ��� ȣ������� ��Ÿ�ӿ� �����Ǵ� ��
//  : ���� �ð��� �޸� ���� �� ȣ��
//   - �����ϰ� �����Ѵ�.
//   - ��������� ������.