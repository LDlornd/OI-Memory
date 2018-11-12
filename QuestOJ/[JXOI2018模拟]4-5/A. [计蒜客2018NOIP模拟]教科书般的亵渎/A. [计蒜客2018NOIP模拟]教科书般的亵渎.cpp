#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN=100001;
int n,k,key,maxlife=0;
int ans1=0,ans2=0;
int cnt[MAXN*2];
bool flag[MAXN*2];
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	n=read();k=read();
	for(int i=1;i<=n;++i){
		key=read();
		++cnt[key];
		maxlife=max(maxlife,key);
	}
	for(int i=1;i<=maxlife;++i){
		if(cnt[i]) flag[i]=true;
		else if(cnt[i+k]){
			flag[i]=true;
			--cnt[i+k];++cnt[i];
		}
	}
	for(int i=1;i<=maxlife;++i){
		if(flag[i]){
			ans1+=cnt[i];
			ans2=i+1;
		}
		else break;
	}
	printf("%d %d",ans1,ans2);
	return 0;
}
