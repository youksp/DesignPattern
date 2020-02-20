// 2_thiscall2.cpp
#include <iostream>
using namespace std;

class Sample
{
	int data;
public:
	void f1() { cout << "f1" << endl;             }
	int f2() { cout << "f2" << endl; return 0; }
	
#if 0
	int f3() { 
		cout << "f3" << endl; 
		if (this == NULL)
			return NULL;

		return this->data; 
	}
#endif
	static int f3(Sample* self) {
		cout << "f3" << endl;
		if (self == NULL)
			return NULL;

		return self->data;
	}

};

int main()
{
	// Sample *p = new Sample; // 메모리 할당을 하다가 실패해서 NULL이 나왔다고 가정합니다.
	Sample* p = NULL;

	p->f1();  // f1(p);
	p->f3();
}