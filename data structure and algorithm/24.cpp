#include<iostream>
#include<cstdlib>
//#define LOCAL

using namespace std;

#ifdef LOCAL
int RandInt(int i, int j)
{
	return rand() % (j - i + 1) + i;
}
#else
extern int RandInt(int i, int j);
#endif // LOCAL

void RandomPermutation1(int n)
{
	if (n <= 0)
	{
		cout << "error";
		return;
	}
	int * A = new int[n];

	for (int i = 0; i < n; i++)
	{
		bool flag;
		do
		{
			flag = false;
			A[i] = RandInt(1, n);
			for (int j = 0; j < i; j++)
			{
				if (A[i] == A[j])
				{
					flag = true;
					break;
				}
			}
		} while (flag);
	}

	for (int i = 0; i < n; i++)
		cout << A[i] << ",";
	cout << "0";
}

void RandomPermutation2(int n)
{
	if (n <= 0)
	{
		cout << "error";
		return;
	}
	int * A = new int[n];

	bool * used = new bool[n + 1];
	for (int i = 1; i <= n; i++)
		used[i] = false;
	for (int i = 0; i < n; i++)
	{
		A[i] = RandInt(1, n);
		while (used[A[i]])
			A[i] = RandInt(1, n);
		used[A[i]] = true;
	}

	for (int i = 0; i < n; i++)
		cout << A[i] << ",";
	cout << "0";
}

void swap(int * a, int * b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

void RandomPermutation3(int n)
{
	if (n <= 0)
	{
		cout << "error";
		return;
	}
	int * A = new int[n];

	for (int i = 1; i <= n; i++)
		A[i - 1] = i;
	for (int i = 1; i < n; i++)
		swap(&A[i], &A[RandInt(0, i)]);

	for (int i = 0; i < n; i++)
		cout << A[i] << ",";
	cout << "0";
}

#ifdef LOCAL
int main()
{
	RandomPermutation3(10);
}
#endif // LOCAL
