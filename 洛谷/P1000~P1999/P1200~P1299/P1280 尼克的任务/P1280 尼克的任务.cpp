#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN=10005;
vector<int> work[MAXN];
int ans[MAXN];
int main()
{
	memset(ans,0,sizeof(ans));
	int total,num,x,y;
	scanf("%d%d",&total,&num);
	for(int i=1;i<=num;++i)
	{
		scanf("%d%d",&x,&y);
		work[x].push_back(y);
	}
	for(int i=total;i>=1;--i)
		if(work[i].empty()) ans[i]=ans[i+1]+1;
		else
		{
			int s=work[i].size();
			for(int j=0;j<s;++j)
				ans[i]=max(ans[i],ans[i+work[i][j]]);
		}
	printf("%d",ans[1]);
	return 0;
}
