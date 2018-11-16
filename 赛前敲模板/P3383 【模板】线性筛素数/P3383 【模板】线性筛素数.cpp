#include<cstdio>
#include<iostream>
using namespace std;
typedef long long int ll;
const int MAXN=1e7+5;
int n,m,k;
int prime[MAXN],cnt=0;
bool flag[MAXN];
void init(){
	flag[1]=true;
	for(int i=2;i<MAXN;++i){
		if(flag[i]==false) prime[++cnt]=i;
		for(int j=1;j<=cnt;++j){
			ll tmp=1ll*i*prime[j];
			if(tmp>=MAXN) break;
			flag[tmp]=true;
			if(i%prime[j]==0) break;
		}
	}
}
int main(){
	init();
	scanf("%d%d",&n,&m);
	while(m--){
		scanf("%d",&k);
		if(flag[k]) printf("No\n");
		else printf("Yes\n"); 
	}
	return 0;
}
