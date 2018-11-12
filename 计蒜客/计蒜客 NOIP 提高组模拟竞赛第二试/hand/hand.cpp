#include<cstdio>
#include<iostream>
using namespace std;
typedef long long int ll;
const int MAXN=1e6+5;
double output;
ll n,m,ans=0,tot=0;
int flag[MAXN<<1];
bool vis[MAXN<<1];
void dfs(int now,ll sum){
	if(now==m+1){
		cout<<sum<<" "<<tot<<endl;
		ans+=sum;++tot;
		return;
	}
	if(vis[now]) dfs(now+1,sum);
	int person=(now>n)?(now-n):now;
	++flag[person];
	for(int i=now+1;i<=m;++i){
		if(vis[i]) continue;
		int tmp=(i>n)?(i-n):i;
		vis[i]=true;++flag[tmp];
		if(flag[tmp]==2) dfs(now+1,sum+1);
		else dfs(now+1,sum);
		vis[i]=false;--flag[tmp];
	}
}
int main(){
	scanf("%lld",&n);m=n<<1;
	dfs(1,0);
	cout<<ans<<" "<<tot<<endl;
	return 0;
}
