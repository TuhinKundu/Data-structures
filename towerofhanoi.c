#include<stdio.h>
int tower(char s,char t,char d,int n)
{
	if(n>0)
	{
		tower(s,d,t,n-1);
		printf("Disk %d is moved %c to %c\n",n,s,d);
		tower(t,s,d,n-1);
	}
}
int main()
{
	int n;
	printf("Enter no of rings:");
	scanf("%d",&n);
	tower('A','B','C',n);
	return 0;
}
