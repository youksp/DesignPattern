// 33_브릿지

struct IMP3
{
	virtual void Play() = 0;
	virtual void Stop() = 0;

	virtual void PlayOneMinute()
	{
		// 브릿지를 도입하는 것보다, 인터페이스에 기본 구현을 제공하는 것이 좋다.
	}

	virtual ~IMP3() {}
};

class Player : public IMP3
{
public:
	virtual void Play() { cout << "Play" << endl; }
	virtual void Stop() { cout << "Stop" << endl; }
};

// 구현부의 인터페이스를 분리해서
// 상호 독립적인 업데이트를 편리하게 한다 - 브릿지 패턴
// => 구현부의 변화 없이 인터페이스를 변경하고
//    인터페이스의 변화없이 구현부를 변경할 수 있다.
// => 계층의 추가를 이용한 유연성의 증대!

#if 0
class MP3
{
	IMP3* pImpl;
public:
	MP3(IMP3* p = 0) : pImpl(p) {}

	void Play() { pImpl->Play(); }
	void Stop() { pImpl->Stop(); }

	void PlayOneMinute()
	{
		//....
	}
};
#endif


// => 사용자가 IMP3를 직접 사용하게 하지 말고,
// 중간층(브릿지)을 도입하면 변화에 쉽게 대응할 수 있다.
class Person
{
public:
	void PlayMusic(IMP3* p) { p->PlayOneMinute(); }
};

int main()
{

}


#if 0
struct IMP3
{
	virtual void Play() = 0;
	virtual void Stop() = 0;

	virtual ~IMP3() {}
};

class Player : public IMP3
{
public:
	virtual void Play() { cout << "Play" << endl; }
	virtual void Stop() { cout << "Stop" << endl; }
};

class Person
{
public:
	void PlayMusic(IMP3* p) { p->Play(); }
};

int main()
{

}
#endif