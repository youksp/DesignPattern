#include <iostream>
#include <algorithm> // sort

#include <functional>  // less<>, greater<>

using namespace std;

inline bool cmp1(int a, int b) { return a < b; }
inline bool cmp2(int a, int b) { return a > b; }

int main()
{
	int x[10] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };

	// 1. 정책으로 함수 객체를 사용할 때
	// 장점: 정책이 인라인화되기 때문에 빠르다!!
	// 단점: 정책을 교체한 횟수 만큼의 sort 함수가 생성된다.
	less<int> f1;
	greater<int> f2;
	sort(x, x + 10, f1);
	sort(x, x + 10, f2);

	// 2. 정책으로 일반 함수를 사용할 때
	// 장점: 정책을 여러번 교체해도 sort()의 기계어는 하나이다.
	// 단점: 정책이 인라인화되지 않기 때문에, 성능 저하가 있다.
	sort(x, x + 10, cmp1);
	sort(x, x + 10, cmp2);

	for (int i = 0; i < 10; ++i)
		cout << x[i] << endl;

}