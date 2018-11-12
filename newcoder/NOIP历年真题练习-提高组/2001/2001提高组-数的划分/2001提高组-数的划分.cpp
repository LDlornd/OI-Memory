#include<cstdio>
#include<iostream>
using namespace std;
typedef long long int ll;
ll ans=0;
int n,k;
void dfs(int now,int sum,int last){
	if(now==k+1){
		if(sum==n) ++ans;
		return;
	}
	for(int i=last;sum+i<=n;++i){
		dfs(now+1,sum+i,i);
	}
}
int main(){
	freopen("testdata.in","r",stdin);
	scanf("%d%d",&n,&k);
	dfs(1,0,1);
	printf("%lld",ans);
	return 0;
}
