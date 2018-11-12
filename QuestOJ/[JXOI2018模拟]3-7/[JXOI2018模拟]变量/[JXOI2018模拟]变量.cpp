#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=1001;
struct cal{
	int x,y,z,a,b,c,d,e,f;
	cal() {x=y=z=a=b=c=d=e=f=0;}
}rule[MAXN];
struct relation{
	int x,y,r;
	relation() {x=y=r=0;}
}R[MAXN];
long long int ans=0;
int T,n,W,p,q;
int val[MAXN];
inline void dfs(int now)
{
	if(now==n+1){
		for(int i=1;i<=q;++i)
			if(R[i].r==1&&val[R[i].x]!=val[R[i].y]) return;
			else if(R[i].r==0&&val[R[i].x]>val[R[i].y]) return;
		long long int temp=0;
		for(int i=1;i<=n;++i) temp+=val[i];
		for(int i=1;i<=p;++i){
			temp+=(rule[i].a*abs(val[rule[i].x]-val[rule[i].y])+rule[i].b*abs(val[rule[i].y]-val[rule[i].z])+rule[i].c*abs(val[rule[i].z]-val[rule[i].x]));
			temp+=(rule[i].d*(val[rule[i].x]-val[rule[i].y])+rule[i].e*(val[rule[i].y]-val[rule[i].z])+rule[i].f*(val[rule[i].z]-val[rule[i].x]));
		}
		if(ans==0) ans=temp;
		else ans=min(ans,temp);
		return;
	}
	if(val[now]!=0){
		dfs(now+1);
		return;
	}
	val[now]=-W;
	dfs(now+1);
	val[now]=W;
	dfs(now+1);
	val[now]=0;
}
inline bool CMP(const relation &A,const relation &B)
{
	return A.r>B.r;
}
int main()
{
	ios::sync_with_stdio(false);
	memset(val,0,sizeof(val));
	cin>>T;
	while(T--){
		memset(val,0,sizeof(val));
		ans=0;
		cin>>n>>W>>p>>q;
		if(W<0) W*=-1;
		for(int i=1;i<=p;++i) cin>>rule[i].x>>rule[i].y>>rule[i].z>>rule[i].a>>rule[i].b>>rule[i].c>>rule[i].d>>rule[i].e>>rule[i].f;
		for(int i=1;i<=q;++i) cin>>R[i].x>>R[i].y>>R[i].r;
		sort(R+1,R+q+1,CMP);
		for(int i=1;i<=q;++i){
			if(R[i].r==2) {val[R[i].x]=-W;val[R[i].y]=W;}
			if(R[i].r==1){
				if(val[R[i].x]!=0) val[R[i].y]=val[R[i].x];
				else if(val[R[i].y]!=0) val[R[i].x]=val[R[i].y];
			}
			if(R[i].r==0){
				if(val[R[i].x]==W) val[R[i].y]=W;
				else if(val[R[i].y]==-W) val[R[i].x]=-W;
			}
		}
		dfs(1);
		cout<<ans<<endl;
	}
	return 0;
}
