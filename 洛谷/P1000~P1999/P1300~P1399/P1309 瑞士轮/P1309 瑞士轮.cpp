#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
struct player
{
	int id,mark,power;
};
player p[200000],win[100000],lose[100000];
int n,r,q;
int CMP(const player &a,const player &b)
{
	if(a.mark==b.mark) return a.id<b.id;
	return a.mark>b.mark;
}
void Merge()
{
	int x=0,y=0,h=n/2,k=0;
	while(x<h&&y<h)
	{
		if(win[x].mark==lose[y].mark)
		{
			if(win[x].id<lose[y].id) p[k++]=win[x++];
			else p[k++]=lose[y++];
		}
		else
		{
			if(win[x].mark<lose[y].mark) p[k++]=lose[y++];
			else p[k++]=win[x++];
		}
	}
	while(x<h)
		p[k++]=win[x++];
	while(y<h)
		p[k++]=lose[y++];
}
int main()
{
	cin>>n>>r>>q;
	n*=2;
	for(int i=0;i<n;++i)
	{
		cin>>p[i].mark;
		p[i].id=i+1;
	}
	for(int i=0;i<n;++i)
		cin>>p[i].power;
	sort(p,p+n,CMP);
	for(int w=0;w<r;++w)
	{
		for(int i=0;i<n;i+=2)
		{
			if(p[i].power<p[i+1].power)
			{
				++p[i+1].mark;
				win[i/2]=p[i+1];
				lose[i/2]=p[i];
			}
			if(p[i].power>p[i+1].power)
			{
				++p[i].mark;
				lose[i/2]=p[i+1];
				win[i/2]=p[i];
			}
		}
		for(int i=0;i<n;++i)
			cout<<p[i].id<<" "<<p[i].mark<<endl;
		cout<<endl;
		for(int i=0;i<n/2;++i)
			cout<<win[i].id<<" "<<win[i].mark<<endl;
		cout<<endl;
		for(int i=0;i<n/2;++i)
			cout<<lose[i].id<<" "<<lose[i].mark<<endl;
		cout<<endl;
		Merge();
		for(int i=0;i<n;++i)
			cout<<p[i].id<<" "<<p[i].mark<<endl;
		cout<<endl;
	}
	cout<<p[q-1].id;
	return 0;
}
