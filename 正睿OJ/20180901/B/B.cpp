#include<cstdio>
#include<iostream>
using namespace std;
typedef long long int ll;
const int mod=323232323;
const int MAXN=5e5+1;
int a,b,c,ans=0,tot=0;
int n;
int arr[MAXN];
int temp[3]={2,3,3};
void dfs(int now,int x,int y,int z){
	if(x==2){
		cout<<now<<x<<y<<z<<endl;
		ans+=now;++tot;return;
	}
	dfs(now+1,x+1,y,z);
	if(y!=3) dfs(now+1,x,y+1,z);
	if(z!=3) dfs(now+1,x,y,z+1);
}
ll quick_mi(ll base,ll index){
	ll temp=1;
	while(index){
		if(index&1) temp=temp*base%mod;
		base=base*base%mod;
		index>>=1;
	}
	return temp;
}
int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	dfs(0,0,0,0);
	printf("%d %d",ans,tot);
	scanf("%d%d",&a,&b);
	printf("%lld",a*quick_mi((ll)b,(ll)mod-2)%mod);
	return 0;
}
