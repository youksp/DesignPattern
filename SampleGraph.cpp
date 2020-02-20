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


// SampleGraph ��� �̸��� ���� DLL�� ����� ����� �� �� �ֽ��ϴ�.
// .exe ���α׷� �ȿ����� ���� �� �� �����ϴ�.
// .DLL ���ο��� �ڽ��� ���� Ŭ������ ��ü�� �����ϴ� �Լ��� �����ؾ� �մϴ�.
// => �Լ� �ϳ��� ����մϴ�.

extern "C"
__declspec(dllexport)
IObserver* CreateGraph()
{
	return new SampleGraph;
}

// cl SampleGraph.cpp /LD