// 23_싱글톤.cpp
#include <iostream>
using namespace std;

// 개념: 오직 한개의 객체를 만들 수 있고, 동일한 방법으로
//       객체를 얻을 수 있게 하는 패턴
class Cursor
{
	// 규칙 1. private 생성자
private:
	Cursor() {}

	// 규칙 2. 복사와 대입을 금지해야 한다.
	// => 핵심! 선언만 한다. - C++98
	//    링크 오류가 나기 때문에 오류 찾기가 어렵다.
	//    C++11/14에서 복사/대입 금지를 위한 문법이 추가되었습니다.
	//    "delete function"
	Cursor(const Cursor&) = delete;
	void operator=(const Cursor&) = delete;

public:
	// 규칙 3. 오직 한개만 만드는 정적 멤버 함수
	static Cursor& getInstance()
	{
		static Cursor instance;
		return instance;
	}
};


int main()
{
	Cursor& c1 = Cursor::getInstance();
	Cursor& c2 = Cursor::getInstance();
	cout << &c1 << ", " << &c2 << endl;
}