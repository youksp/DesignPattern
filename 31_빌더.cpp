#include <iostream>
#include <string>
using namespace std;

// 디자인 패턴에서 변하는 것을 인터페이스 기반 클래스로 만들어서 교체하는 패턴은 3가지 입니다.
// "Strategy": 알고리즘을 캡슐화해서 실행시간에 교체 가능하게 하는 것
// "State": 객체의 상태에 따라 동작을 정의한 클래스를 만들어서 교체 하는 것
// "Builder": 동일한 구축 공정으로 객체를 만들지만, 각 공정에 따른 표현이 달라지는 객체를 만들때

// 축구 게임에서 캐릭터를 만드는 공정은 변하지 않습니다.
struct IBuilder
{
	virtual void makeHat() = 0;
	virtual void makeUniform() = 0;
	virtual void makeShoes() = 0;

	virtual string getResult() = 0;
};

class Director
{
	IBuilder* builder;
public:
	void setBuilder(IBuilder* p) { builder = p; }

	string Consturct()
	{
		// 1. 머리
		builder->makeHat();
		// 2. 유니폼
		builder->makeUniform();
		// 3. 신발
		builder->makeShoes();
		return builder->getResult();
	}
};

class Korean : public IBuilder
{
	string s;
public:
	virtual void makeHat() { s += "삿갓"; }
	virtual void makeUniform() { s += "한복"; }
	virtual void makeShoes() { s += "짚신"; }

	virtual string getResult()
	{
		return s;
	}
};

class English : public IBuilder
{
	string s;
public:
	virtual void makeHat() { s += "노란머리"; }
	virtual void makeUniform() { s += "양복"; }
	virtual void makeShoes() { s += "구두"; }

	virtual string getResult()
	{
		return s;
	}
};

int main()
{
	Korean k;
	English e;

	Director d;
	d.setBuilder(&e);
	cout << d.Consturct() << endl;

}