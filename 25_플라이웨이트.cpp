// 25_�ö��̿���Ʈ
//  �ǵ�: �Ӽ��� ������ ��ü�� �ټ� �����Ѵٸ�, �ϳ��� ��ü�� �����ؼ� �������.

#include <iostream>
#include <string>

#include <Windows.h>  // Sleep
using namespace std;

#include <map>

// �����Ǵ� ��ü�� �Һ� ��ü�� ����.
class Image
{
	string url;
	static map<string, Image*> image_map;
private:
	Image(string s) : url(s)
	{
		// �����κ��� �̹����� �ٿ�ε� �޾ƾ� �մϴ�.
		cout << "Loading from " << url << endl;
		Sleep(5000);
	}

public:
	// ���� ���丮 �Լ�
	// 1. �����ڸ� ���� ����� ���, ��ü ������ ��å�� �����ϴ� ���� ��ƴ�.
	// 2. �����ڴ� Ŭ������ �̸��� �����մϴ�.
	//    �������� ���� �ʴ�.
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