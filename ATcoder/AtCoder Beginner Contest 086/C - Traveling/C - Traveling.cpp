#include<cmath>
#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN=100001;
int n,nowt=0,nowx=0,nowy=0,tot,tox,toy;
bool flag=true;
inline int read()
{
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') {x=x*10+c-'0';c=getchar();}
	return x*f;
}
int main()
{
	n=read();
	while(n--)
	{
		tot=read();tox=read();toy=read();
		int dist=abs(tox-nowx)+abs(toy-nowy);
		int Time=tot-nowt;
		if(Time<dist) {flag=false;break;}
		Time-=dist;
		if(Time&1) {flag=false;break;}
		nowt=tot;nowx=tox;nowy=toy;
	}
	if(flag) printf("Yes");
	else printf("No");
	return 0;
}
