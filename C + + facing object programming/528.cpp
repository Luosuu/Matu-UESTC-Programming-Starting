//下列程序的功能是：输入数组下标和除数，从数组中取出下标对应的数组元素作为被除数，输出除法运算的结果。例如，
//输入：9 5
//输出：2
//
//捕获程序数组下标越界错误，给出相应的提示，例如，
//输入：10 5
//输出：10 out of bound
//
//输入： - 1 5
//输出： - 1 out of bound
//
//捕获程序数组下标除零错误，给出相应的提示，例如，
//输入：9 0
//输出：divide by 0
//
//部分代码已给出，请将代码补充完整

#include<iostream>

using namespace std;

#include<exception>

class A : public exception
{
public:
    int err;
    A(int index) :err(index) {}
};

class B : public exception
{
public:
    int err;
    B(int divisor) :err(divisor) {}
};

int main()
{
    int index, dividend, divisor, result;
    int array[10] = { 1,2,3,4,5,6,7,8,9,10 };

    try
    {
        cin >> index >> divisor;
        if (index < 0 || index >9)
            throw A(index);
        if (divisor == 0)
            throw B(divisor);
        dividend = array[index];
        result = dividend / divisor;
        cout << result << endl;
    }
    catch (A a)
    {
        cout << a.err << " out of bound" << endl;
    }
    catch (B b)
    {
        cout << "divide by " << b.err << endl;
    }
    return 0;
}