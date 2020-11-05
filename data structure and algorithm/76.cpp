#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>

using namespace std;

//输入先序、中序，输出后序

int preposi[128] = { 0 }, inposi[128] = { 0 };
string preString, inString;

void getPostOrder(int pre_x, int pre_y, int in_x, int in_y)
{
	if (pre_x > pre_y)
		return;
	char root = preString[pre_x];
	int rootInInOrder = inposi[root];
	int length1 = rootInInOrder - in_x;
	int length2 = in_y - rootInInOrder;
	getPostOrder(pre_x + 1, pre_x + length1, in_x, rootInInOrder - 1);
	getPostOrder(pre_y - length2 + 1, pre_y, rootInInOrder + 1, in_y);
	cout << root;
}

int main()
{
	cin >> preString >> inString;
	string a = preString, b = inString;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	if (a != b)
	{
		cout << "error";
		return 0;
	}

	for (int i = 0; i < 128; i++)
		preposi[i] = inposi[i] = -1;
	for (int i = 0; i < preString.length(); i++)
	{
		if (preposi[preString[i]] > -1 || inposi[inString[i]] > -1)
		{
			cout << "error";
			return 0;
		}
		preposi[preString[i]] = i;
		inposi[inString[i]] = i;
	}

	getPostOrder(0, preString.length() - 1, 0, preString.length() - 1);
	return 0;
}
