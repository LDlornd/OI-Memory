#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN=10;
long long int ans=0,dp[MAXN][MAXN*MAXN][1<<MAXN];
int n,key,MAX;
int cnt[1<<MAXN];
bool one[1<<MAXN],two[1<<MAXN][1<<MAXN];
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>key;
	MAX=1<<n;
	for(int i=0;i<MAX;++i){
		if(i&(i>>1)) continue;
		one[i]=true;
		for(int j=1;j<=i;j<<=1)
			if(i&j) ++cnt[i];
	}
	for(int i=0;i<MAX;++i){
		if(one[i]){
			for(int j=0;j<MAX;++j){
				if(one[j]==false||(i&j)||(i&(j>>1))||(i&(j<<1))) continue;
				two[i][j]=true;
			}
		}
	}
	for(int i=0;i<MAX;++i)
		if(one[i]) dp[1][cnt[i]][i]=1;
	for(int i=1;i<n;++i){
		for(int j=0;j<MAX;++j){
			if(one[j]){
				for(int k=0;k<MAX;++k){
					if(one[k]==false||two[j][k]==false) continue;
					for(int w=cnt[j];w+cnt[k]<=key;++w){
						dp[i+1][w][k]+=dp[i][w][j];
					}
				}
			}
		}
	}
	for(int i=0;i<MAX;++i)
		ans+=dp[n][key][i];
	cout<<ans;
	return 0;
}
