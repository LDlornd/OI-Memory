#include<cstdio>
#include<iostream>
#include<cstdlib> 
using namespace std;
struct person
{
	int num;
	person *next;
};
person *head=new person,*tail=head,*p,*v=head;
int main()
{
	int m,n,k=0;
	cin>>n>>m;
	head->num=n;
	if(n==0) return 0;
	for(int i=0;i<n;++i)
	{
		p=new person;
		p->num=i+1;p->next=head->next;
		tail->next=p;tail=p;
	}
	for(p=head->next;n!=1;p=p->next)
	{
		++k;
		if(k%m==0)
		{
			cout<<p->num<<" ";
			v->next=p->next;
			--n;
			continue;
		}
		v=v->next;
	}
	cout<<p->num;
	return 0;
}
