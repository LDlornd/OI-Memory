#include<cstdio>
#include<cstring>
using namespace std;
int s[100000],visit[100000],ans[4]={0,0,0,0};
int n;
void judge(int a[4])
{
	int num=0;
	int sum=(a[0]+a[1]+a[2]+a[3])/4;
	for(int i=0;i<4;++i)
	{
		if(a[i]==sum) {++num;return;}
		
	}
}
void select(int a[],int b, int c)
{
	if(c==0)
	{
		for(int i=0;i<4;++i)
		{
			printf("%d",ans[i]);
		}
		printf("\n");
		judge(ans);
	}
}
int main()
{
	memset(visit,0,sizeof(visit));
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		scanf("%d",s[i]);
	}
	select(s,n,4);
}
