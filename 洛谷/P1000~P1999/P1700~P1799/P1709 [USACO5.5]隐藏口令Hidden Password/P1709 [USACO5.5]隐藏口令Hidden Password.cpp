#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int MAXN=10000001;
int len,ans;
char s[MAXN];
int main()
{
	scanf("%d",&len);
	for(int i=1;i<=len;++i)
		while(s[i]<'a'||s[i]>'z') s[i+len]=s[i]=getchar();
	int start=1,end=2,k=0;
	while(start<=len&&end<=len)
	{
		k=0;
		while(s[start+k]==s[end+k]&&k<len) ++k;
		if(k==len) {ans=min(start,end);break;}
		if(s[start+k]>s[end+k]) start=start+k+1;
		else end=end+k+1;
		if(start==end) ++end;
	}
	ans=min(start,end);
	printf("%d",ans-1);
	return 0;
}
