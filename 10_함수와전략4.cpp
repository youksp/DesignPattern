#include <iostream>
#include <algorithm> // sort

#include <functional>  // less<>, greater<>

using namespace std;

inline bool cmp1(int a, int b) { return a < b; }
inline bool cmp2(int a, int b) { return a > b; }

int main()
{
	int x[10] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };

	// 1. ��å���� �Լ� ��ü�� ����� ��
	// ����: ��å�� �ζ���ȭ�Ǳ� ������ ������!!
	// ����: ��å�� ��ü�� Ƚ�� ��ŭ�� sort �Լ��� �����ȴ�.
	less<int> f1;
	greater<int> f2;
	sort(x, x + 10, f1);
	sort(x, x + 10, f2);

	// 2. ��å���� �Ϲ� �Լ��� ����� ��
	// ����: ��å�� ������ ��ü�ص� sort()�� ����� �ϳ��̴�.
	// ����: ��å�� �ζ���ȭ���� �ʱ� ������, ���� ���ϰ� �ִ�.
	sort(x, x + 10, cmp1);
	sort(x, x + 10, cmp2);

	for (int i = 0; i < 10; ++i)
		cout << x[i] << endl;

}