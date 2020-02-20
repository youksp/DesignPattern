// 10_함수와전략3.cpp
// 1. 함수는 자신만의 타입이 존재하지 않는다.
//    시그니처가 동일한 모든 함수는 같은 타입이다.

// 2. 함수 객체
//  - 함수 호출 연산자() 를 재정의 하는 것으로 만들 수 있다.
//  - 시그니처가 동일하더라도 모든 함수 객체는 다른 타입이다.

#include <iostream>
using namespace std;


// 성능저하 없이 정책 교체가 가능한 sort()
//  템플릿 + 함수객체를 사용한 기술!
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

// 람다: 코드 조각을 참조하는 기술
//  C++: 익명의 함수 객체를 생성하는 기술!

int main()
{
	int x[10] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };

	Less l; Greater g;
	// Sort(x, 10, l);

	// C++11부터 사용할 수 있습니다.
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