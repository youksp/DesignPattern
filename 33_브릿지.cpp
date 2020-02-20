// 33_�긴��

struct IMP3
{
	virtual void Play() = 0;
	virtual void Stop() = 0;

	virtual void PlayOneMinute()
	{
		// �긴���� �����ϴ� �ͺ���, �������̽��� �⺻ ������ �����ϴ� ���� ����.
	}

	virtual ~IMP3() {}
};

class Player : public IMP3
{
public:
	virtual void Play() { cout << "Play" << endl; }
	virtual void Stop() { cout << "Stop" << endl; }
};

// �������� �������̽��� �и��ؼ�
// ��ȣ �������� ������Ʈ�� ���ϰ� �Ѵ� - �긴�� ����
// => �������� ��ȭ ���� �������̽��� �����ϰ�
//    �������̽��� ��ȭ���� �����θ� ������ �� �ִ�.
// => ������ �߰��� �̿��� �������� ����!

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


// => ����ڰ� IMP3�� ���� ����ϰ� ���� ����,
// �߰���(�긴��)�� �����ϸ� ��ȭ�� ���� ������ �� �ִ�.
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