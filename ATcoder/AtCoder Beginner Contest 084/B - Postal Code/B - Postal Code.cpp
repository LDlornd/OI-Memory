#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int MAXN=20;
char s[MAXN];
int main()
{
	int n,m,num=0,place=0;
	scanf("%d%d\n",&n,&m);
	scanf("%s",s);
	int len=strlen(s);
	for(int i=0;i<len;++i)
		if(s[i]=='-') {++num;place=i;}
	if(num==1&&place==n&&m+n+1==len) printf("Yes");
	else printf("No");
	return 0;
}
