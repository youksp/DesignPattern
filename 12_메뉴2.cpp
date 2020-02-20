// 12_메뉴2
// Composite Pattern 실습
#include <string>
#include <iostream>
#include <vector>
using namespace std;

// Item
// - File, Folder
// - getSize

class Item
{
	string name;
public:
	Item(string s) : name(s) {}
	virtual ~Item() {}

	virtual int getSize() = 0;
};

class File : public Item
{
	int size;
public:
	File(string s, int n) : Item(s), size(n) {}

	int getSize() 
	{
		return size;
	}
};

class Folder : public Item
{
	vector<Item *> v;
public:
	Folder(string s) : Item(s) {}

	// 자신이 포함한 객체에 대한 삭제의 책임이 있다.
	~Folder()
	{
		for (auto p : v)
			delete p;
	}

	void addItem(Item* p) { v.push_back(p); }

	int getSize()
	{
		int sum = 0;
		for (int i = 0; i < v.size(); ++i)
			sum += v[i]->getSize();
		return sum;
	}

};


int main()
{
	// 아래 코드가 실행되도록, Folder, File 클래스를 만들어 보세요
	Folder* fol1 = new Folder("C");
	Folder* fol2 = new Folder("A");
	
	File* f1 = new File("a.txt", 10); // 이름, 크기
	File* f2 = new File("b.txt", 20); 

	//  관계 설정
	fol2->addItem(f1);
	fol1->addItem(f2);
	fol1->addItem(fol2);

	cout << f2->getSize() << endl;
	cout << fol2->getSize() << endl;
	cout << fol1->getSize() << endl;
}