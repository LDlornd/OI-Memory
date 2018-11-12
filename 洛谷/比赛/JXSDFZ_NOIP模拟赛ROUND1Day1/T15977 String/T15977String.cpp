#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int MAXN=500001;
char s[MAXN];
bool flag[55],vis[55];
inline int change(char c)
{
	if(c>='A'&&c<='Z') return c-'A'+1;
	else return c-'a'+27;
}
int main()
{
	freopen("testdata.in","r",stdin);
	freopen("WAout.out","w",stdout);
	memset(flag,0,sizeof(flag)); 
	int n,num=0,tot=0,ans=MAXN;
	scanf("%d%s",&n,s+1);
	for(int i=1;i<=n;++i)
	{
		int k=change(s[i]);
		if(flag[k]==false)
			{++num;flag[k]=true;}
	}
	for(int i=1;i<=n;++i)
	{
		memset(vis,0,sizeof(vis));
		tot=0;
		for(int j=i;j<=n;++j)
		{
			int k=change(s[j]);
			if(vis[k]==false)
				{++tot;vis[k]=true;}
			if(j-i+1>=ans) break;
			if(tot==num) {ans=min(ans,j-i+1);break;}
		}
	}
	printf("%d",ans);
	fclose(stdin);fclose(stdout);
	return 0;
}
