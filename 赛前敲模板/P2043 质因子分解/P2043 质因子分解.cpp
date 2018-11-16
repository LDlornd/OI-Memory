#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN=10005;
int n,cnt=0;
int prime[MAXN],num[MAXN];
bool flag[MAXN];
void init(){
	flag[1]=true;
	for(int i=2;i<MAXN;++i){
		if(flag[i]==false) prime[++cnt]=i;
		for(int j=1;j<=cnt;++j){
			if(1ll*i*prime[j]>=MAXN) break;
			flag[i*prime[j]]=true;
		}
	}
}
int main(){
	init();
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		int tmp=i;
		for(int j=1;j<=cnt&&prime[j]<=tmp;++j){
			while(tmp%prime[j]==0){
				tmp/=prime[j];
				++num[j];
			}
		}
	}
	for(int i=1;i<=cnt;++i)
		if(num[i]) printf("%d %d\n",prime[i],num[i]);
	return 0;
}
