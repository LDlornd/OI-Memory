#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
int q,a,b,c,d;
string s;
inline int read()
{
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') {x=x*10+c-'0';c=getchar();}
	return x*f;
}
int main()
{
	q=read();
	while(q--)
	{
		bool flag=false;
		a=read();b=read();c=read();d=read();
		s="";
		if(a<b) {swap(a,b);flag=true;}
		
	}
}
