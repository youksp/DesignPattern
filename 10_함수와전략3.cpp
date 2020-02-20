// 10_�Լ�������3.cpp
// 1. �Լ��� �ڽŸ��� Ÿ���� �������� �ʴ´�.
//    �ñ״�ó�� ������ ��� �Լ��� ���� Ÿ���̴�.

// 2. �Լ� ��ü
//  - �Լ� ȣ�� ������() �� ������ �ϴ� ������ ���� �� �ִ�.
//  - �ñ״�ó�� �����ϴ��� ��� �Լ� ��ü�� �ٸ� Ÿ���̴�.

#include <iostream>
using namespace std;


// �������� ���� ��å ��ü�� ������ sort()
//  ���ø� + �Լ���ü�� ����� ���!
template <typename T>
void Sort(int* x, int n, T cmp)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; ++j)
		{
			if (cmp(x[i], x[j]))
				// if (x[i] < x[j])
				swap(x[i], x[j]);
		}
	}
}

struct Less
{
	inline bool operator()(int a, int b) { return a > b; }
};

struct Greater
{
	bool operator()(int a, int b) { return a < b; }
};

inline bool cmp1(int a, int b) { return a < b; }
inline bool cmp2(int a, int b) { return a > b; }

// ����: �ڵ� ������ �����ϴ� ���
//  C++: �͸��� �Լ� ��ü�� �����ϴ� ���!

int main()
{
	int x[10] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };

	Less l; Greater g;
	// Sort(x, 10, l);

	// C++11���� ����� �� �ֽ��ϴ�.
	Sort(x, 10, [](int a, int b) { return a > b; });


	for (int i = 0; i < 10; ++i)
	{
		cout << x[i] << endl;
	}
}

#if 0
struct Plus
{
	int operator()(int a, int b)
	{
		return a + b;
	}
};

int main()
{
	Plus p;

	cout << p(10, 20) << endl;
}
#endif