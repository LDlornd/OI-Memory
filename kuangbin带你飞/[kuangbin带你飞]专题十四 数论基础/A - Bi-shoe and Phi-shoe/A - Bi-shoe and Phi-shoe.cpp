#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN=1e6+1000;
typedef long long int ll;
ll ans=0;
int T,n,key,tot=0;
int prime[MAXN],f[MAXN],cnt[MAXN],Copy[MAXN];
bool flag[MAXN],vis[MAXN];
void getready(){
	for(int i=2;i<MAXN;++i){
		if(flag[i]==false){
			prime[++tot]=i;
			f[i]=i-1;
		}
		ll now;
		for(int j=1;j<=tot;++j){
			now=(ll)i*prime[j];
			if(now>=MAXN) break;
			flag[now]=true;
			if(i%prime[j]==0){
				f[now]=f[i]*prime[j];
				break;
			}
			else f[now]=f[i]*f[prime[j]];
		}
	}
	for(int i=1;i<MAXN;++i){
		if(vis[f[i]]) continue;
		cnt[f[i]]=i;vis[f[i]]=true;
	}
	for(int i=1;i<MAXN;++i) Copy[i]=cnt[i];
	for(int i=1000997;i>0;--i)
		if(cnt[i]==0||cnt[i]>cnt[i+1]) cnt[i]=cnt[i+1];
}
int main(){
	freopen("testdata.in","r",stdin);
	freopen("AC.out","w",stdout);
	getready();
	scanf("%d",&T);
	for(int casenum=1;casenum<=T;++casenum){
		scanf("%d",&n);
		ans=0;
		while(n--){
			scanf("%d",&key);
			ans+=(ll)cnt[key];
		}
		printf("Case %d: %lld Xukha\n",casenum,ans);
	}
	return 0;
}
