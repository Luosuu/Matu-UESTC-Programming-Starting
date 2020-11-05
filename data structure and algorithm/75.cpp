#include <iostream>
#include<set>
#include<cstdlib>
#include<algorithm>
#include<ctime>
#include<fstream>
#include<list>
#include<string>

using namespace std;

int randMax;

list<int> L;

int main()
{
	int n, k, m;
	string K;
	cin >> n >> k >> m;
	if (cin.fail()||n < k || m < 0)
	{
		cout << "ERROR";
		return 0;
	}
	if (m == 0)
	{
		cout << 0;
		return 0;
	}


	for (int i = 1; i <= n; i++)
	{
		L.push_back(i);
	}

	list<int>::iterator iter = L.begin();
	while (n != k)
	{
		for (int i = 0; i < m; i++)
		{
			iter++;
			if (iter == L.end())
				iter = L.begin();
		}
		iter = L.erase(iter);
		if (iter == L.end())
			iter = L.begin();
		n--;
	}
	for (iter = L.begin(); iter != L.end(); iter++)
		cout << (iter == L.begin() ? "" : ",") << *iter;
}