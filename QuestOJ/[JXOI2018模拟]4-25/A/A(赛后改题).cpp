#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
typedef long long int ll;
const int MAXN1=2501;
const int MAXN2=5001;
const ll INF=1e18;
const int mod=1e9+7;
ll ans=0;
ll n,m,T,u,v,l;
ll dp[MAXN1][MAXN2];
struct seg{
	ll k,b;
	seg(ll kk=0,ll bb=0) {k=kk;b=bb;}
};
seg Stack[MAXN2];ll top;
struct edge{
	ll v,len;
	edge *nex;
	edge() {v=len=0;nex=NULL;}
}*con[MAXN1];
inline void ins(ll Start,ll End,ll key){
	edge *p=new(edge);
	p->v=End;p->len=key;
	p->nex=con[Start];con[Start]=p;
	p=new(edge);
	p->v=Start;p->len=key;
	p->nex=con[End];con[End]=p;
}
inline ll calculate(seg x,seg y){return (y.b-x.b)/(x.k-y.k);}
inline ll read(){
	ll x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	n=read();m=read();T=read();
	for(int i=1;i<=m;++i){
		u=read();v=read();l=read();
		ins(u,v,l);
	}
	for(int i=1;i<=n;++i)
		for(int j=0;j<=m;++j)
			dp[i][j]=INF;
	dp[1][0]=0;
	for(int i=1;i<=m;++i)
		for(int j=1;j<=n;++j)
			for(edge *p=con[j];p;p=p->nex)
				dp[p->v][i]=min(dp[p->v][i],dp[j][i-1]+p->len);
	for(int i=2;i<=n;++i){
		top=0;
		for(int j=m;j;--j){
			seg temp=seg(j,dp[i][j]);
			while(top>1&&calculate(temp,Stack[top])<=calculate(Stack[top],Stack[top-1])) --top;
			while(top&&temp.b<=Stack[top].b) --top;
			Stack[++top]=temp;
		}
		int Time=0;
		for(int j=1;j<=top&&Time<=T;++j){
			int nxt=(j==top)?T:min(calculate(Stack[j+1],Stack[j]),T);
			ans=(ans+(ll)(nxt-Time+1)*(ll)Stack[j].b%mod+(ll)(nxt+Time)*(nxt-Time+1)/2%mod*(ll)Stack[j].k%mod)%mod;
			Time=nxt+1;
		}
	}
	printf("%lld",ans);
	return 0;
}
