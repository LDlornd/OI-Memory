#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int s[20],visit[20],ans[20];
int k=0,m,n,flag=0;
int cmp(int a,int b)
{
	return a<b;
}
bool judge(int a)
{
	if(a==0||a==1) return false;
	if(a==2) return true;
	int z=ceil(sqrt(a));
	for(int i=2;i<z;++i)
		if(a%i==0) return false;
	return true;
}
void select(int a,int z)
{
	if(a==0)
	{
		int sum=0;
		for(int i=n-m;i<z;++i)
			sum+=ans[i];
		if(judge(sum)) ++k;
		return;
	}
	for(int i=flag;i<z;++i)
	{
		if(a==z) {ans[0]=s[i];continue;}
		if(s[i]<ans[z-a-1]||(s[i]==ans[z-a-1]&&visit[i]==1)) continue;
		ans[z-a]=s[i];
		visit[i]=1;flag=i;
		select(a-1,n);
		ans[z-a]=0;visit[i]=0;
	}
}
int main()
{
	memset(visit,0,sizeof(visit));
	memset(ans,0,sizeof(ans));
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i)
		scanf("%d",&s[i]);
	sort(s,s+n,cmp);
	select(m,n);
	printf("%d",k);
	return 0;
}
