#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long int ll;
const int MAXN=205;
int n,casenum=0;
ll ans,c,k,h;
ll dp[MAXN];
struct node{
	ll length,wide,height;
	node() {length=wide=height=0;}
}arr[MAXN];
struct edge{
	int v;
	edge *nex;
	edge() {v=0;nex=NULL;}
}*con[MAXN];
void ins(int Start,int End){
	edge *p=new(edge);
	p->v=End;
	p->nex=con[Start];con[Start]=p;
}
void getready(){
	memset(con,0,sizeof(con));
	memset(dp,0,sizeof(dp));
}
bool CMP(const node &a,const node &b){
	if(a.length==b.length) return a.wide>b.wide;
	else return a.length>b.length;
}
ll read(){
	ll x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	freopen("testdata.in","r",stdin);
	while(scanf("%d",&n)!=EOF){
		if(n==0) break;
		getready();
		for(int i=1;i<=n;++i){
			c=read();k=read();h=read();
			arr[i*6-5].length=c;arr[i*6-5].wide=k;arr[i*6-5].height=h;
			arr[i*6-4].length=c;arr[i*6-4].wide=h;arr[i*6-4].height=k;
			arr[i*6-3].length=k;arr[i*6-3].wide=c;arr[i*6-3].height=h;
			arr[i*6-2].length=k;arr[i*6-2].wide=h;arr[i*6-2].height=c;
			arr[i*6-1].length=h;arr[i*6-1].wide=c;arr[i*6-1].height=k;
			arr[i*6].length=h;arr[i*6].wide=k;arr[i*6].height=c;
		}
		n=n*6;
		sort(arr+1,arr+n+1,CMP);
		for(int i=1;i<=n;++i)
			for(int j=i+1;j<=n;++j)
				if(arr[i].length>arr[j].length&&arr[i].wide>arr[j].wide)
					ins(j,i);
		ans=dp[1]=arr[1].height;
		for(int i=2;i<=n;++i){
			dp[i]=arr[i].height;
			for(edge *p=con[i];p;p=p->nex)
				dp[i]=max(dp[i],dp[p->v]+arr[i].height);
			ans=max(ans,dp[i]);
		}
		printf("Case %d: maximum height = %lld\n",++casenum,ans);
	}
	return 0;
}
