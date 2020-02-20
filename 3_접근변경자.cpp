// 3_접근변경자.cpp
class Base {
private:
	int a;
protected:
	int b;
public:
	int c;
};

// private 상속
// : 부모의 인터페이스를 물려 받지 않겠다.
class Derived : public Base {
};

int main()
{
	// public 상속일 때만 허용됩니다.
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