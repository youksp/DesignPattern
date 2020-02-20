#include <iostream>
#include <string>
using namespace std;

class my_traits : public char_traits<char>
{
public:
	static bool compare(const char* a, const char* b, size_t sz)
	{
		return strcmpi(a, b);
	}
};


typedef basic_string<char, my_traits> mystring;

int main()
{
	mystring s1 = "abcd";
	mystring s2 = "ABCD";

	if (s1 == s2)
		cout << "Same" << endl;
	else
		cout << "Diff" << endl;
}