#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

int main(int data[],int n)
{
	struct node *header=NULL,*p,*q;
	int i;
	header=(struct node*)malloc(1*sizeof(struct node));
	header->next=NULL;
	q=header;
	for(i=0;i<n;++i)
	{
		p=(struct node*)malloc(1*sizeof(struct node));
		p->data=data[i];
		p->next=NULL;
		q->next=p;
		q=p;
	}
	return (int)header;
}