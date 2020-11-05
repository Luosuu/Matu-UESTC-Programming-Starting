#include <iostream>

using namespace std;

namespace ns1
{
	int x = 1, y = 2;
	namespace ns2
	{
		int add_one(int x)
		{
			return x + 1;
		}
		char x = 'a', y = 'b';
	}
}

int main()
{
	using namespace ns1::ns2;
	cout << ns1::x << "," << ns1::y << endl;
	cout << x << "," << y << endl;
	cout << add_one(10) << endl;
	return 0;
}