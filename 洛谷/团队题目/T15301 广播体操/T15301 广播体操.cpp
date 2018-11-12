#include<cstdio>
#include<iostream>
using namespace std;
typedef long long int ll;
const int MAXN=50005;
int n;
int height[MAXN],Left[MAXN],Right[MAXN];
ll ans=0;
int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	n=read();
	for(int i=1;i<=n;++i) height[i]=read();
	for(int i=1;i<=n;++i){
		Left[i]=1;
		for(int j=i-1;j>=1;j-=Left[j])
			if(height[j]>=height[i]) Left[i]+=Left[j];
			else break;
	}
	for(int i=n;i>=1;--i){
		Right[i]=1;
		for(int j=i+1;j<=n;j+=Right[j])
			if(height[j]>=height[i]) Right[i]+=Right[j];
			else break;
	}
	for(int i=1;i<=n;++i){
		ans=max(ans,(ll)height[i]*(Left[i]+Right[i]-1));
	}
	printf("%lld",ans);
	return 0;
}
