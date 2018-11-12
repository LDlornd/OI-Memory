#include<cstdio>
#include<iostream>
using namespace std;
typedef long long int ll;
ll k,l,p,ans=0;
int s,w;
int arr[11];
void dfs(int now){
	if(now==l+1){
		if(s==0||(s&&arr[s]==w)) ans=(ans+1)%p;
		return;
	}
	else if(now==1){
		for(int i=1;i<=k;++i){
			arr[now]=i;
			dfs(now+1);
		}
	}
	else if(now==2){
		for(int i=1;i<=k;++i){
			if(arr[now-1]!=i){
				arr[now]=i;
				dfs(now+1);
			}
		}
	}
	else{
		for(int i=1;i<=l;++i){
			if(arr[now-2]!=i&&arr[now-1]!=i){
				arr[now]=i;
				dfs(now+1);
			}
		}
	}
}
void get_50_pts(){
	dfs(1);
}
void get_30_pts(){
	
}
int main(){
	freopen("testdata.in","r",stdin);
	freopen("tle.out","w",stdout);
	scanf("%lld%lld%lld%d%d",&k,&l,&p,&s,&w);
	if(l<=10) get_50_pts();
	else if(s==0) get_30_pts();
	printf("%lld",ans);
	return 0;
}
