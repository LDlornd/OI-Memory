#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
typedef long long int ll;
const int MAXN=17;
int n,key,MAX,s[MAXN];
ll ans=0,dp[MAXN][(1<<MAXN)+1];
bool flag[MAXN][MAXN];
int main(){
	ios::sync_with_stdio(false);
	memset(flag,0,sizeof(flag));
	memset(dp,0,sizeof(dp));
	cin>>n>>key;MAX=1<<n;
	for(int i=1;i<=n;++i) cin>>s[i];
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			if(abs(s[i]-s[j])>key) flag[i][j]=true;
	for(int i=1;i<=n;++i) dp[i][1<<(i-1)]=1;
	for(int w=0;w<MAX;++w)
		for(int i=1;i<=n;++i)
			if(w&(1<<(i-1)))
				for(int j=1;j<=n;++j)
					if((w&(1<<(j-1)))==0&&flag[i][j])
						dp[j][w|(1<<(j-1))]+=dp[i][w];
	for(int i=1;i<=n;++i)
		ans+=dp[i][MAX-1];
	cout<<ans;
	return 0;
}
