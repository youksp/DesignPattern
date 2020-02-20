#include <iostream>
#include <string>
using namespace std;

// ������ ���Ͽ��� ���ϴ� ���� �������̽� ��� Ŭ������ ���� ��ü�ϴ� ������ 3���� �Դϴ�.
// "Strategy": �˰����� ĸ��ȭ�ؼ� ����ð��� ��ü �����ϰ� �ϴ� ��
// "State": ��ü�� ���¿� ���� ������ ������ Ŭ������ ���� ��ü �ϴ� ��
// "Builder": ������ ���� �������� ��ü�� ��������, �� ������ ���� ǥ���� �޶����� ��ü�� ���鶧

// �౸ ���ӿ��� ĳ���͸� ����� ������ ������ �ʽ��ϴ�.
struct IBuilder
{
	virtual void makeHat() = 0;
	virtual void makeUniform() = 0;
	virtual void makeShoes() = 0;

	virtual string getResult() = 0;
};

class Director
{
	IBuilder* builder;
public:
	void setBuilder(IBuilder* p) { builder = p; }

	string Consturct()
	{
		// 1. �Ӹ�
		builder->makeHat();
		// 2. ������
		builder->makeUniform();
		// 3. �Ź�
		builder->makeShoes();
		return builder->getResult();
	}
};

class Korean : public IBuilder
{
	string s;
public:
	virtual void makeHat() { s += "��"; }
	virtual void makeUniform() { s += "�Ѻ�"; }
	virtual void makeShoes() { s += "¤��"; }

	virtual string getResult()
	{
		return s;
	}
};

class English : public IBuilder
{
	string s;
public:
	virtual void makeHat() { s += "����Ӹ�"; }
	virtual void makeUniform() { s += "�纹"; }
	virtual void makeShoes() { s += "����"; }

	virtual string getResult()
	{
		return s;
	}
};

int main()
{
	Korean k;
	English e;

	Director d;
	d.setBuilder(&e);
	cout << d.Consturct() << endl;

}