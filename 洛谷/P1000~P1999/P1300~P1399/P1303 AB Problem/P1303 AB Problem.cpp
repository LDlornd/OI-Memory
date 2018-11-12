#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int MAXN=5000;
char s[MAXN];
int a[MAXN],b[MAXN],ans[MAXN];
int main()
{
	memset(ans,0,sizeof(ans));
	int p1,p2;
	bool flag=true;
	scanf("%s",s);
	p1=strlen(s);
	for(int i=p1;i>=1;--i) a[i]=s[p1-i]-'0';
	scanf("%s",s);
	p2=strlen(s);
	for(int i=p2;i>=1;--i) b[i]=s[p2-i]-'0';
	if(p1<p2)
	{
		for(int i=1;i<=p2;++i)
			swap(a[i],b[i]);
		swap(p1,p2);
	}
	for(int i=1;i<=p1;++i)
	{
		for(int j=1;j<=p2;++j)
		{
			ans[i+j-1]+=a[i]*b[j];
			ans[i+j]+=ans[i+j-1]/10;
			ans[i+j-1]%=10;
		}
	}
	for(int i=p1+p2;i>=1;--i)
		if(ans[i]!=0||flag==false) {printf("%d",ans[i]);flag=false;}
	if(flag) printf("0");
	return 0;
}
