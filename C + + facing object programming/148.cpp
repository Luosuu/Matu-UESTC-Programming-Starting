#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
class User
{
private:
	char *name, *name1, *pass, *pass1;
public:
	User(char *a, char *b);
	int login(char *c, char *d);
	void AddUser(char *e,char*f);
};
User::User(char *a, char *b)
{
	name = a; pass = b;
}
void User::AddUser(char *e, char*f)
{
	name1 = e; pass1 = f;
}
int User::login(char *c, char *d)
{
	int judge1 =1, judge2 = 1;
	int l1 = strlen(c);
	int l2 = strlen(name1);
	int l3 = strlen(d);
	int l4 = strlen(pass1);
	if (l1 == l2 && l3 == l4)
	{
		for (int i = 0; i < l1; i++)
		{
			if (c[i] == name1[i]) judge1 *= 1;
			else judge1 *= 0;
		}
		for (int i = 0; i < l3; i++)
		{
			if (d[i] == pass1[i]) judge2 *= 1;
			else judge2 *= 0;
		}
		if (judge1 == 1 && judge2 == 1) return 0;
		else return -1;
	}
	else return - 1;
}
int main() 
{
	char name[10], name1[10], pass[10], pass1[10];
	cin >> name >> pass >> name1 >> pass1;
	User user("q","1");
	user.AddUser(name, pass);
	if (user.login(name1, pass1) >= 0)
	{
		cout << "Success Login!" << endl;
	}
	else {
		cout << "Login failed!" << endl;
	}
	return 0;
}