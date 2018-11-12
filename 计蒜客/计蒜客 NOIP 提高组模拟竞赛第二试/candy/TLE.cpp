#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long int ll;
const int MAXN=1e5+5;
int n,k,cnt,tot=0;
int Size[MAXN];
ll arr[MAXN][11];
vector<ll> ans;
void dfs(int now,ll sum){
	if(now==n+1){
		ans.push_back(sum);++tot;
		return;
	}
	for(int i=1;i<=Size[now];++i)
		dfs(now+1,sum+arr[now][i]);
}
bool CMP(int a,int b){
	return a>b;
}
int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	n=read();k=read();
	for(int i=1;i<=n;++i){
		Size[i]=cnt=read();
		for(int j=1;j<=cnt;++j){
			arr[i][j]=read();
		}
	}
	dfs(1,0);
	sort(ans.begin(),ans.end(),CMP);
	printf("%lld",ans[k-1]);
	return 0;
}
