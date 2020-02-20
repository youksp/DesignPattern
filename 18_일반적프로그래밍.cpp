#include <iostream>
using namespace std;

// 일반화 프로그래밍(Generic Programming)
//  = C++ 라이브러리의 설계 철학을 이해하기 위해서는 반드시 일반화를 이해해야 합니다.
//  = C++: 객체지향 + 일반화(Generic) + 함수형

// C의 문자열 검색
#if 0
char* xstrchr(char* s, int c)
{
	while (*s != '\0' && *s != c)
		++s;
	return *s == c ? s : 0;
}
#endif
// 1. 검색 구간의 일반화
//  [first, last): 반개구간!!
#if 0
char* xstrchr(char* first, char* last, int c)
{
	while (first != last && *first != c)
		++first;

	return first; // == last ? 0 : first;
}
#endif

// 2. 검색 대상 타입에 대한 일반화: template 도입
// template <typename T>
//  위처럼 만들면 안되는 이유
// 1) 구간의 타입과 찾는 요소의 타입이 연관되어 있다.
//     double 배열 안에서 int 타입을 찾을 수 없다.
// 2) T* 라고 하면 진짜 포인터만 사용할 수 있다.
//    스마트포인터는 사용할 수 없다.
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