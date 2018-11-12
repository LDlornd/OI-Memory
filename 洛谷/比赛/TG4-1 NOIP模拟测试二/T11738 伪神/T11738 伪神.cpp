#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;
struct child
{
	int num;
	child *next;
	child(int num=0,child *next=NULL) {num=num;next=next;}
};
struct point
{
	int father,data;
	child firstchild;
	point(int father=0,int data=0) {father=father;data=data;}
};
child *p,*v;
point jiedian[100001];
inline void preorderbianli(int x)
{
	printf("x==%d data==%d\n",x,jiedian[x].data);
	if(jiedian[x].firstchild.next==NULL) return;
	for(p=&jiedian[x].firstchild;p!=NULL;p=p->next)
		preorderbianli(p->num);
	return;
}
int main()
{
	int n,m,x,y;
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;++i)
	{
		scanf("%d%d",&x,&y);
		if(x>y) swap(x,y);
		jiedian[y].father=x;
		for(p=&jiedian[x].firstchild;p!=NULL;p=p->next)
		{
			if(p->next==NULL) {p->num=y;v=new(child);p->next=v;break;}
		}
	}
	for(int i=1;i<=n;++i)
	{
		printf("\njiedian%d:\nsons: ",i);
		for(p=&jiedian[i].firstchild;p->next!=NULL;p=p->next)
			printf("%d ",p->num);
	}
	preorderbianli(1);
	return 0;
}
