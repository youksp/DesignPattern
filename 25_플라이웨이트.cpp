// 25_플라이웨이트
//  의도: 속성이 동일한 객체가 다수 존재한다면, 하나의 객체를 공유해서 사용하자.

#include <iostream>
#include <string>

#include <Windows.h>  // Sleep
using namespace std;

#include <map>

// 공유되는 객체는 불변 객체가 좋다.
class Image
{
	string url;
	static map<string, Image*> image_map;
private:
	Image(string s) : url(s)
	{
		// 서버로부터 이미지를 다운로드 받아야 합니다.
		cout << "Loading from " << url << endl;
		Sleep(5000);
	}

public:
	// 정적 팩토리 함수
	// 1. 생성자를 직접 사용할 경우, 객체 생성의 정책을 변경하는 것이 어렵다.
	// 2. 생성자는 클래스의 이름과 동일합니다.
	//    가독성이 좋지 않다.
	static Image* imageWithURL(string url)
	{
		if (image_map[url] == 0)
			image_map[url] = new Image(url);
		return image_map[url];
	}

	void draw()
	{
		cout << "Draw Image" << endl;
	}
};

map<string, Image*> Image::image_map;


#include <map>

int main()
{
	// ImageFactory factory;

	Image* img1 = Image::imageWithURL("https://www.a.com/a.png");
	// Image* img1 = new Image("https://www.a.com/a.png");
	img1->draw();

	Image* img2 = Image::imageWithURL("https://www.a.com/a.png");
	// Image* img2 = new Image("https://www.a.com/a.png");
	img2->draw();
}



#if 0
class ImageFactory
{
	map<string, Image*> image_map;
public:
	Image * CreateImage(string url)
	{
		if (image_map[url] == 0)
			image_map[url] = new Image(url);
		return image_map[url];
	}
};


int main()
{
	ImageFactory factory;

	Image* img1 = factory.CreateImage("https://www.a.com/a.png");
	// Image* img1 = new Image("https://www.a.com/a.png");
	img1->draw();

	Image* img2 = factory.CreateImage("https://www.a.com/a.png");
	// Image* img2 = new Image("https://www.a.com/a.png");
	img2->draw();
}
#endif