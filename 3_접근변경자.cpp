// 3_���ٺ�����.cpp
class Base {
private:
	int a;
protected:
	int b;
public:
	int c;
};

// private ���
// : �θ��� �������̽��� ���� ���� �ʰڴ�.
class Derived : public Base {
};

int main()
{
	// public ����� ���� ���˴ϴ�.
	Base* p = new Derived;
}

#if 0
int main()
{
	Base b;
	b.c = 42;

	Derived d;
	d.c = 42;
}
#endif