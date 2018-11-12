#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
int num=0,place=0;
struct ans
{
	int a[10];
	ans *next;
};
ans *head=new(ans),*tail=new(ans),*p=new(ans),*v=p;
void search(int k,int depth)
{
	if(depth==0)
	{
		if(k==0)
		{
			p=new(ans);
			v->next=p;
			p->next=tail;
			for(int i=0;i<10;++i)
				p->a[i]=v->a[i];
			v=p;
			++num;
			return;
		}
	}
	for(int i=1;i<=3;++i)
	{
		k-=i;
		if(k>=0)
		{
			p->a[place++]=i;
			search(k,depth-1);
			--place;k+=i;
		}
		else return;
	}
}
int main()
{
	head->next=p;
	p->next=tail;
	tail->next=NULL;
	int n;
	scanf("%d",&n);
	if(n<10||n>30) {printf("0");return 0;}
	search(n,10);
	printf("%d\n",num);
	for(p=head->next;p->next!=tail;p=p->next)
	{
		printf("%d",p->a[0]);
		for(int i=1;i<10;++i)
			printf(" %d",p->a[i]);
		printf("\n");
	}
	return 0;
}
