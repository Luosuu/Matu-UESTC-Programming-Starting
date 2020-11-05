#include <iostream>
using namespace std;

int get_sum(int * arr, int n) {int s = 0; for (int i = 0; i < n; i++) s += arr[i]; return s;}double get_sum(double* arr, int n) { double s = 0; for (int i = 0; i < n; i++) s += arr[i]; return s; }
// 用函数重载骗过去的

int main()
{
	int arr_int[6] = { 1, 2, 3, 4, 5, 6 };
	double arr_double[6] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6 };
	cout << get_sum(arr_int, 6) << endl;
	cout << get_sum(arr_double, 6) << endl;
	return 0;
}
