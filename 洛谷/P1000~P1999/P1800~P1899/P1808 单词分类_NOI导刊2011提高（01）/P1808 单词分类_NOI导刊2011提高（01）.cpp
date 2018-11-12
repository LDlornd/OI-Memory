#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
struct word
{
	int len;
	char s[101];
}w[10000];
bool CMP1(char a,char b)
{
	return a<b;
}
bool CMP2(const word &a,const word &b)
{
	int l=strcmp(a.s,b.s);
	if(l>0) return false;
	else return true;
}
int main()
{
	int n,ans=1;
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		scanf("%s",w[i].s);
		w[i].len=strlen(w[i].s);
		sort(w[i].s,w[i].s+w[i].len,CMP1);
	}
	sort(w,w+n,CMP2);
	for(int i=0;i<n-1;++i)
	{
		if(strcmp(w[i].s,w[i+1].s)!=0) ++ans;
	}
	printf("%d",ans);
	return 0;
}
