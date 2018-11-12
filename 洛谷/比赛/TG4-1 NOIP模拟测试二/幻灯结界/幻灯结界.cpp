#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=200001;
int attack[MAXN],defend[MAXN],cha[MAXN];
inline bool CMP(int a,int b)
{
	return a<b;
}
int main()
{
	int n,x,y,ans=0,num=0,xnum=0;
	scanf("%d%d%d",&n,&x,&y);
	for(int i=1;i<=n;++i)
		scanf("%d",&defend[i]);
	for(int i=1;i<=n;++i)
		scanf("%d",&attack[i]);
	sort(defend+1,defend+n+1,CMP);
	sort(attack+1,attack+n+1,CMP);
	for(int i=1;i<=n&&defend[i]<y;++i)
	{
		if(num==x) break;
		++num;
		defend[i]=y;
		
	}
	sort(defend+1,defend+n+1,CMP);
	for(int i=1;i<=n;++i)
		ans=max(ans,attack[i]-defend[i]);
	printf("%d",ans);
	return 0;
}
