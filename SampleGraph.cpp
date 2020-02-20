// SampleGraph.cpp
#include "IObserver.h"
#include <iostream>
using namespace std;

class SampleGraph : public IObserver
{
public:
	void OnUpdate(void* p)
	{
		int* data = static_cast<int*>(p);
		cout << "*************** Sample Graph *************" << endl;
		for (int i = 0; i < 5; ++i)
			cout << i << ": " << data[i] << endl;
	}
};


// SampleGraph 라는 이름은 현재 DLL을 만드는 사람만 알 수 있습니다.
// .exe 프로그램 안에서는 절대 알 수 없습니다.
// .DLL 내부에서 자신이 만든 클래스의 객체를 생성하는 함수를 제공해야 합니다.
// => 함수 하나를 약속합니다.

extern "C"
__declspec(dllexport)
IObserver* CreateGraph()
{
	return new SampleGraph;
}

// cl SampleGraph.cpp /LD