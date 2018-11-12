#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long int ll;
const int MAXN=10;
int n,m;
int arr[MAXN],add[MAXN][MANX],ans[MAXN][MAXN];
bool vis[MANX];
struct point{
	ll point;
	int id;
	point(ll pp=0,int ii=0) {point=pp;id=ii;}
}rank[MAXN];
void judge(){
	
}
void dfs(now){
	if(now==m+1){
		judge();
		return;
	}
	
}
bool CMP(ll a,ll b){
	return a<b;
}
template<typename T>
T read(){
	T x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	n=read<int>();m=read<int>();
	for(int i=1;i<=n;++i) arr[i]=read<ll>();
	for(int i=1;i<=n;++i) add[1][i]=read<ll>();
	sort(add[1]+1,add[1]+n+1,CMP);
	for(int j=2;j<=m;++j)
		for(int i=1;i<=n;++i)
			add[j][i]=add[1][i];
	dfs(1);
}
