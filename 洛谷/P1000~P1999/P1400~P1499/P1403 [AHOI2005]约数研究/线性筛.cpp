#include<cstdio>
#include<iostream>
using namespace std;
typedef long long int ll;
const int MAXN=1000005;
ll ans=0;
int n,tot=0;
int prime[MAXN],minp[MAXN],minq[MAXN],divcnt[MAXN];
bool flag[MAXN];
void getready(){
	divcnt[1]=1;
	for(int i=2;i<MAXN;++i){
		if(flag[i]==false){
			prime[++tot]=i;
			divcnt[i]=2;
			minp[i]=i;minq[i]=1;
		}
		for(int j=1;j<=tot;++j){
			int temp=i*prime[j];
			if(temp>=MAXN) break;
			flag[temp]=true;
			minp[temp]=j;
			if(i%prime[j]==0){
				minq[temp]=minq[i]+1;
				divcnt[temp]=divcnt[i]/(minq[i]+1)*(minq[temp]+1);
				break;
			}
			minq[temp]=1;
			divcnt[temp]=divcnt[i]*divcnt[prime[j]];
		}
	}
}
int main(){
	getready();
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		ans+=divcnt[i];
	printf("%lld",ans);
	return 0;
}
