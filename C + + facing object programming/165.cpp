//#include"CSet.h"
#include<algorithm>
#include<set>
#include<cassert>
#include<iostream>

using namespace std;

class Set
{
private:
	int n;
	int* pS; //集合元素
public:
	Set() { n = 0; pS = NULL; }
	Set(Set& s)
	{
		n = s.n;
		if (n != 0)
		{
			pS = new  int[n + 1];
			for (int i = 1; i <= n; i++) //集合的下标从1开始，集合中不能有重复元素
				pS[i] = s.pS[i];
		}
	}
	~Set()
	{
		if (pS)
		{
			delete[]pS;
			pS = NULL;
			n = 0;
		}
	}
	bool operator <=(const Set& s)const;

	bool operator==(const Set& s) const;

	Set& operator+=(int e);

	Set& operator-=(int e);

	Set operator|(const Set& s) const;

	Set operator&(const Set& s) const;

	Set operator-(const Set& s) const;

	void ShowElement()const { //输出集合的元素
		int temp = 0;
		for (int i = 1; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (pS[i] > pS[j])
				{
					temp = pS[i];
					pS[i] = pS[j];
					pS[j] = temp;
				}
			}
		}
		cout << "{";
		for (int i = 1; i < n; i++)
			cout << pS[i] << ",";
		if (IsEmpty())
			cout << "}" << endl;
		else cout << pS[n] << "}" << endl;
	}
	bool IsEmpty()const { return n ? false : true; } //判断集合是否为空
	int size() { return n; }
	bool IsElement(int e)const {
		for (int i = 1; i <= n; i++)
			if (pS[i] == e)
				return true;
		return  false;
	}
};

bool Set::operator <=(const Set& s)const
{

	if (n > s.n)
		return false;
	sort(pS + 1, pS + n + 1);
	sort(s.pS + 1, s.pS + n + 1);
	for (int i = 1, j = 1; i <= n; j++)
	{
		if (pS[i] == s.pS[i])
			i++;
		else if (pS[i] < s.pS[i])
			return false;
		else if (j > s.n)
			return false;
		else;
	}
	return true;
};//this <= s判断当前集合是否包于集合s

bool Set::operator ==(const Set& s)const //判断集合是否相等
{
	if (n != s.n)
		return false;
	sort(pS + 1, pS + n + 1);
	sort(s.pS + 1, s.pS + n + 1);
	for (int i = 1; i <= n; i++)
		if (pS[i] != s.pS[i])
			return false;
	return true;
}

Set& Set::operator+=(int e) {
	if (!this->IsElement(e))
	{
		Set set;
		set.n = this->n + 1;
		set.pS = new int[set.n + 1];
		for (int i = 1; i < this->n + 1; i++)
		{
			set.pS[i] = this->pS[i];
		};
		set.pS[set.n] = e; //现在的脚标有问题

		delete[]this->pS;
		this->pS = NULL;
		this->n++;
		this->pS = new int[set.n + 1];
		for (int i = 1; i < set.n + 1; i++)//应该从i=1开始赋值
		{
			this->pS[i] = set.pS[i];
		}
	}

	return *this;
}
Set& Set::operator-=(int e) {
	Set set(*this);
	if (set.IsElement(e)) {
		delete[]pS;
		pS = NULL;
		pS = new int[n];
		for (int i = 1, j = 1; i <= n + 1; ++i)
		{
			if (set.pS[i] != e)
			{
				pS[j++] = set.pS[i];//
			}
		}
		--n;

	}
	return *this;
}

Set Set::operator|(const Set& s) const {
	Set set;
	for (int i = 1; i <= n; ++i) {
		set += this->pS[i];
	}
	for (int i = 1; i <= s.n; ++i) {
		set += s.pS[i];
	}
	return set;
}
Set Set::operator&(const Set& s) const {
	Set set;
	set.n = n;
	set.pS = new int[n + 1];
	for (int i = 1; i <= n; ++i)
	{
		set.pS[i] = pS[i];
	}
	for (int i = 1; i <= n; i++)
	{
		if (!s.IsElement(this->pS[i])) {
			set -= this->pS[i];
		}
	}
	return set;
}

Set Set::operator-(const Set& s) const {
	Set set;
	set.n = n;
	set.pS = new int[n + 1];
	for (int i = 1; i <= n; ++i)
	{
		set.pS[i] = this->pS[i];
	}
	for (int i = 1; i <= s.n; ++i)
	{
		if (this->IsElement(s.pS[i]))
		{
			set -= s.pS[i];
		}
	}
	return set;
}


//int main()
//{
//	Set s;
//	s += 1;
//	s.ShowElement();//{1}
//
//	s += 2;
//	s.ShowElement();//{1,2}
//	s -= 1;
//	s.ShowElement();//{2}
//
//	Set s1, s2, s3;
//	s1 += 1; s2 += 1; s2 += 3; s3 += 2;
//	assert(s1 <= s2);//true
//	assert(!(s3 <= s2));//false
//
//	Set s1, s2;
//	s1 += 1; s1 += 3; s2 += 2; s2 += 1;
//	(s1 - s2).ShowElement();//{1,2}
//}
