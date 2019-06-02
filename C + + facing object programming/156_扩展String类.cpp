#include<stdio.h>
#include <iostream>
#include<cstring> 
#include<string>
using namespace std;
class String{
protected:
	char *mystr;
	int len;
public:
	String(const char *p){
		len = strlen(p);
		mystr = new char[len+1];
		strcpy(mystr,p);
	}
	~String(){
		if (mystr !=NULL)
		{
			delete []mystr;
			mystr = NULL;
			len = 0;
		}
	}
	void showStr(){cout <<mystr;}
	char * GetStr(){return mystr;}
	virtual bool IsSubString(const char *str){
		int i,j;
		for (i =0;i<len;i++)
		{
			int k = i;
			for (j =0;str[j] !='0\0';j++,k++)
			{
				if (str[j]!= mystr[k]) break;//�ڵ�һ����ĸ��ͬ������±ȽϺ������ĸ 
			}
			if(str[j] =='\0') return true;
		}
		return false;
	}
};

class EditString:public String{
public:
	EditString(const char *p):String(p){}
	int IsSubString(int start, const char *str);
	void EditChar(char s, char d); 
	void EditSub(char * subs,char *subd); 

	void DeleteChar(char ch);  
	void DeleteSub(char * sub); 

};
int EditString::IsSubString(int start, const char *str)
{
	int i,j;
	for(i=start;i<len;i++)
	{
		int k=i;
		for(j=0;str[j];j++,k++)
		{
			if(str[j]!=mystr[k])break;
		}
		if(str[j]=='\0')return i;
	}
	return -1;
}
void EditString::EditChar(char s, char d)
{
	for(int i=0;i<len;i++)
	{
		if(mystr[i]==s)//����д's' 
		mystr[i]=d;
	}
}
void EditString::EditSub(char * subs,char *subd)
{ 
	int start=EditString::IsSubString(0,subs);
	if(start<0)return;
	else
	{
		int i=0,j=0;
		int l1=strlen(subs);//�����е��Ӵ� 
	    int l2=strlen(subd);//�滻�� 
	    char newstr[25];
	    for(;i<25;i++)
	    {
	    	newstr[i]='\0';//��ʼ������˵�������õı��ϰ��... 
	    }
	    while(start!=-1)
	    {
	    	for(i=0;j<start;j++,i++)
	    	{
	    		newstr[i]=mystr[j];
	    	}
	    	for(int k=0;k<l2;k++,i++)
	    	{
	    		newstr[i]=subd[k];
	    	}
	    	start=EditString::IsSubString(start+l1,subs);
	    	j=j+l1;
	    	if(start==-1)
		    	for(;j<len;j++,i++)
		    	{
		    		newstr[i]=mystr[j];
		    	}
	    }
	    for(i=0;i<len;i++)
	    { 
	    	mystr[i]='\0';
	    } 
	    strcpy(mystr,newstr);
//	    int L=strlen(mystr);
//	    for(int i=0;i<L;i++)
//	    cout<<mystr[i]<<endl;
	    return;
	} 
} 
void EditString::DeleteChar(char ch)
{
	for(int i=0;mystr[i];i++)
	{
		if(mystr[i]==ch)
		{
			for(int j=i;mystr[j];j++)
			{
				mystr[j]=mystr[j+1];
			}
			i--;
		}
	}
//	for(int k=0;k<len;k++)
//	cout<<mystr[k];
//	cout<<endl;
}
void EditString::DeleteSub(char * sub)
{
	int start=EditString::IsSubString(0,sub);
	if(start<0)return;
	else
	{
		int L=strlen(sub);
		char newstr[25];
		for(int i=0;i<25;i++)
		{
			newstr[i]='\0';
		}
		int i=0,j=0;
		while(start>=0)
		{
		for(;j<start;i++,j++)
		{
			newstr[i]=mystr[j];
		}	
		j=j+L;
		start=EditString::IsSubString(j,sub);
		if(start==-1)
		{
			for(;j<len;i++,j++)
			newstr[i]=mystr[j];
		}
		}
		for(i=0;mystr[i];i++)
		{
		mystr[i]='\0';	
		}	
		strcpy(mystr,newstr);
		for(i=0;mystr[i];i++)
		{
			cout<<mystr[i];
		}
		cout<<endl;
	}
}