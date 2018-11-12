#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;
struct element
{
	int num,index;
}q[20000001];
int a[2000000];
int main()
{
	q[0].num=0;q[0].index=0;
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i)
		scanf("%d",&a[i]);
	printf("0\n"); 
	element *head=&q[1],*tail=&q[1];
	head->num=a[0];head->index=0;
	for(int i=1;i<n;++i)
	{
		while(a[i-1]<=tail->num&&tail>=head)
			--tail;
		++tail;
		tail->num=a[i-1];
		tail->index=i-1;
		if(i>=m&&head->index<i-m) ++head;
		printf("%d\n",head->num);
	}
	return 0;
}
