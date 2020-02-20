#include <iostream>
using namespace std;

// �Ϲ�ȭ ���α׷���(Generic Programming)
//  = C++ ���̺귯���� ���� ö���� �����ϱ� ���ؼ��� �ݵ�� �Ϲ�ȭ�� �����ؾ� �մϴ�.
//  = C++: ��ü���� + �Ϲ�ȭ(Generic) + �Լ���

// C�� ���ڿ� �˻�
#if 0
char* xstrchr(char* s, int c)
{
	while (*s != '\0' && *s != c)
		++s;
	return *s == c ? s : 0;
}
#endif
// 1. �˻� ������ �Ϲ�ȭ
//  [first, last): �ݰ�����!!
#if 0
char* xstrchr(char* first, char* last, int c)
{
	while (first != last && *first != c)
		++first;

	return first; // == last ? 0 : first;
}
#endif

// 2. �˻� ��� Ÿ�Կ� ���� �Ϲ�ȭ: template ����
// template <typename T>
//  ��ó�� ����� �ȵǴ� ����
// 1) ������ Ÿ�԰� ã�� ����� Ÿ���� �����Ǿ� �ִ�.
//     double �迭 �ȿ��� int Ÿ���� ã�� �� ����.
// 2) T* ��� �ϸ� ��¥ �����͸� ����� �� �ִ�.
//    ����Ʈ�����ʹ� ����� �� ����.
template <typename T1, typename T2>
T1 xfind(T1 first, T1 last, T2 c)
{
	while (first != last && *first != c)
		++first;

	return first; // == last ? 0 : first;
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5 };
	int* p2 = xfind(arr, arr + 5, 3);
	if (p2 != arr + 5)
		cout << *p2 << endl;

	char s[] = "abcdefg";
	char* p = xfind(s, s+4, 'c');
	if (p != s + 4)
	{
		cout << *p << endl;
	}
}