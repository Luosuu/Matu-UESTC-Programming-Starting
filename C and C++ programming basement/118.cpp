#include <stdio.h>
#include <stdlib.h>
int find(int n);
int main() {
	int a,b;
	scanf("%d",&a);
	b=find(a);
	printf("%d",b);

	return 0;
}
int find(int n) {
	int a,b,c,d=0,e;
	int i=100;
	a=i%100;
	if	(n>999)
		return 0;
		
 for(i; i<=n; i++) {
		a=i%10;
		b=((i%100)-a)/10;
		c=(i-i%100)/100;
		e=c*c*c+b*b*b+a*a*a;
		if(e==i)
			d++;
	}
	return d;

}