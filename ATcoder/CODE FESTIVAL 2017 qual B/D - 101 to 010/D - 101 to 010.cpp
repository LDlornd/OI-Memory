#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;
const int MAXN=500001;
char s[MAXN];
int main()
{
	int n,ans=0;
	scanf("%d\n",&n);
	for(int i=1;i<=n;++i)
		scanf("%c",&s[i]);
	for(int i=2;i<n;++i)
	{
		if(s[i-1]=='1'&&s[i]=='0'&&s[i+1]=='1')
		{
			s[i-1]='0';
			s[i]='1';
			s[i+1]='0';
			++ans;
			i=i-1;
		}
	}
	printf("%d",ans);
	return 0;
}
