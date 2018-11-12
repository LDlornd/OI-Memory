#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN=250000;
const int mod=1e9+7;
int n,ans=0;
int arr[MAXN],lg[MAXN];
int dp[MAXN],sum[MAXN];
bool judge(int x,int y,int key){
	if(x<=2) return true;
	int mid=key>>1;
	if(x<=mid) return judge(x,y,mid);
	else if(y>mid) return judge(x-mid,y-mid,mid);
	else if(x-y>=mid) return judge(x-mid,y,mid);
	else return false;
}
void init(){
	lg[1]=0;
	for(int i=2;i<MAXN;++i) lg[i]=lg[i>>1]+1;
}
int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	init();
	n=read();
	for(int i=1;i<=n;++i) arr[i]=read();
	for(int w=n;w>=1;--w){
		for(int i=w+1;i<=n;++i){
			if(arr[w]>=arr[i]){
				if(judge(arr[w]+1,arr[i]+1,1<<(lg[arr[w]+1]+(lg[arr[w]+1]==lg[arr[w]])))) dp[w]=(dp[w]+dp[i]+1)%mod;
			}
		}
	}
	for(int i=1;i<=n;++i) ans=(ans+dp[i])%mod;
	printf("%d",ans);
	return 0;
}
