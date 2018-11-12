#include<cstdio>
#include<string>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long int ll;
const int MAXN=100000;
const int mod=1e9+7;
int n,tot=0,did=1;
ll arr[MAXN],ans=0,fas=0,temp=0,debug=0;
int fa[MAXN],Size[MAXN];
bool flag=true,vis[MAXN];
struct G{
	int Left,Right;
	ll len;
	G(int ll=0,int rr=0,long long int Len=0) {Left=ll;Right=rr;len=Len;}
}data[MAXN];
struct edge{
	int v;
	ll val;
	edge *nex;
	edge() {v=0;val=0;nex=NULL;}
}*con[MAXN];
inline void ins(int Start,int End,ll key){
	edge *p=new(edge);
	p->v=End;p->val=key;
	p->nex=con[Start];con[Start]=p;
	p=new(edge);
	p->v=Start;p->val=key;
	p->nex=con[End];con[End]=p;
	data[++tot]=G(Start,End,key);
}
inline int getfa(int nv) {return (fa[nv]==nv)?nv:(fa[nv]=getfa(fa[nv]));}
inline void Merge(int a,int b){
	a=getfa(a);b=getfa(b);
	if(Size[a]<Size[b]) swap(a,b);
	fa[b]=a;Size[a]+=Size[b];
}
inline void getfas(int nv){
	if(nv==tot+1){
		for(int i=1;i<=n;++i) fa[i]=i;
		++debug;
		did=1;temp=0;
		for(int i=1;i<=tot;++i){
			if(vis[i]){
				int nl=data[i].Left,nr=data[i].Right;
				if(getfa(nl)!=getfa(nr)){
					Merge(nl,nr);
					++did;
				}
				temp+=data[i].len;
			}
		}
		if(did==n&&temp==ans) ++fas;
		return;
	}
	vis[nv]=true;
	getfas(nv+1);
	vis[nv]=false;
	getfas(nv+1);
}
inline bool CMP(const G &a,const G &b){
	return a.len<b.len;
}
template<typename T>
inline T read(){
	T x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	freopen("jst.in","r",stdin);
	freopen("jst.out","w",stdout);
	n=read<int>();
	for(int i=1;i<=n;++i){
		arr[i]=read<ll>();
		if(i>1&&arr[i]!=arr[i-1]) flag=false;
	}
	if(flag){
		fas=1;ans=arr[1]*(n-1);
		for(int i=3;i<=n;++i) (fas*=i)%=mod;
	}
	else{
		for(int i=1;i<=n;++i)
			for(int j=i+1;j<=n;++j)
				ins(i,j,arr[i]^arr[j]);
		sort(data+1,data+tot+1,CMP);
		for(int i=1;i<=n;++i) fa[i]=i;
		for(int i=1;i<=tot&&did<n;++i){
			int nl=data[i].Left,nr=data[i].Right;
			if(getfa(nl)!=getfa(nr)){
				Merge(nl,nr);
				ans+=data[i].len;
				++did;
			}
		}
		getfas(1);
	}
	printf("%lld\n%lld",ans,fas);
	fclose(stdin);fclose(stdout);
	return 0;
}
