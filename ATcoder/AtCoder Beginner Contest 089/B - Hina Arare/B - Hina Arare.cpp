#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
char c;
int n,ans;
bool flag[27];
int main()
{
	memset(flag,false,sizeof(flag));
	scanf("%d",&n);
	while(n--)
	{
		c=0;
		while(c<'A'||c>'Z') c=getchar();
		flag[c-'A']=true;
	}
	for(int i=0;i<27;++i) if(flag[i]) ++ans;
	if(ans==3) printf("Three");
	else printf("Four");
	return 0;
}
