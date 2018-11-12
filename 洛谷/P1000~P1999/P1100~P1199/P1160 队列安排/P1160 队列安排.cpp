#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
bool flag[100001];
struct person
{
	int num;
	person *next,*prev; 
};
person *head=new person,*v,*tail=new person,*place[100001];
int main()
{
	memset(flag,0,sizeof(flag));
	place[1]=new person;
	head->prev=NULL;
	head->next=place[1];
	tail->next=NULL;
	tail->prev=place[1];
	place[1]->num=1;
	place[1]->prev=head;
	place[1]->next=tail;
	int m,n;
	cin>>n;
	for(int i=2;i<=n;++i)
	{
		int k,p;
		cin>>k>>p;
		if(p==0)
		{
			place[i]=new person;
			place[i]->num=i;
			place[i]->next=place[k];
			place[k]->prev->next=place[i];
			place[i]->prev=place[k]->prev;
			place[k]->prev=place[i];
		}
		if(p==1)
		{
			place[i]=new person;
			place[i]->num=i;
			place[i]->prev=place[k];
			place[k]->next->prev=place[i];
			place[i]->next=place[k]->next;
			place[k]->next=place[i];
		}
	}
	cin>>m;
	for(int i=0;i<m;++i)
	{
		int p;cin>>p;
		if(flag[p]) continue;
		flag[p]=1;
		place[p]->prev->next=place[p]->next;
		place[p]->next->prev=place[p]->prev;
	}
	for(v=head->next;v->next!=NULL;v=v->next)
		cout<<v->num<<" ";
	return 0;
}
