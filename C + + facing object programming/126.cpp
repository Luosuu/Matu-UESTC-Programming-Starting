#include <iostream>

int main()
{
	int n;
	long long ans = 1;
	std::cin >> n;
	if (n >= 13)
	{
		std::cout << "12!=479001600";
		return 0;
	}
	for (int i = 1; i <= n; i++)
	{
		ans *= i;
	}
	std::cout << n << "!=" << ans;
}