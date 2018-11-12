#include<cstdio>
using namespace std;
void change(char a[])
{
	int m;
	char c;
	scanf("%d %c",&m,&c);
	a[m-1]=c;
}
void find(char a[])
{
	int m,n,flag=-1,num=0;
	scanf("%d%d",&m,&n);
	--m;--n;
	for(int i=m;i<=n;++i)
	{
		if(a[i]=='(') flag=0;
		if(a[i]==')'&&flag==0) ++num;
	}
	printf("%d\n",num);
}
int main()
{
	int x,y;
	scanf("%d%d",&x,&y);
	char s[x];
	for(int i=0;i<x;++i)
	{
		if(i==0) {s[i]='(';continue;}
		if(i==x-1) {s[i]=')';continue;}
		s[i]='x';
	}
	for(int k=0;k<y;++k)
	{
		int p;
		scanf("%d",&p);
		if(p==1) change(s);
		if(p==2) find(s);
	}
	return 0;
}
