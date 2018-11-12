#include<cstdio>
#include<iostream>
using namespace std;
typedef long long int ll;
const int MAXN=1001;
int n,place;
int fa[MAXN],opt[MAXN],tot=0;
ll arr[MAXN],dp[MAXN],ans=-1e9-1;
bool flag=true;
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>arr[i];
		dp[i]=arr[i];
		if(arr[i]>0) flag=false;
	}
		for(int i=1;i<=n;++i)
		for(int j=1;j<i;++j)
			if(((i-j)&1)==0){
				if(dp[j]+arr[i]>dp[i]){
					dp[i]=dp[j]+arr[i];
					fa[i]=j;
				}
			}
	for(int i=1;i<=n;++i){
		if(dp[i]>ans){
			ans=dp[i];
			place=i;
		}
	}
	for(int i=n;i>place;--i) opt[++tot]=i;
	while(fa[place]!=0){
		int Next=fa[place];
		int mid=(Next+place)>>1;
		for(int i=mid;i>Next;--i) opt[++tot]=i;
		place=fa[place];
	}
	for(int i=1;i<place;++i) opt[++tot]=1;
	cout<<ans<<endl<<tot<<endl;
	for(int i=1;i<=tot;++i) cout<<opt[i]<<endl;
	return 0;
}
