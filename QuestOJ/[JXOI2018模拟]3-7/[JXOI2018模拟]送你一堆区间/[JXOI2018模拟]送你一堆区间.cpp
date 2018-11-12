#include<cstdio>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
const int MAXN=500001;
const int mod=1000000009;
int n,m,ans=0;
int Left[MAXN],Right[MAXN];
int Point[MAXN];
map<int,int> vis;
inline void dfs(int now)
{
	if(now==n+1)
	{
		for(int i=1;i<=m;++i)
			if(vis[Point[i]]==0) return;
		if(++ans==mod) ans=0;
		return;
	}
	dfs(now+1);
	for(int i=1;i<=m;++i){
		if(Point[i]<Left[now]) continue;
		if(Point[i]>Right[now]) break;
		++vis[Point[i]];
	}
	dfs(now+1);
	for(int i=1;i<=m;++i){
		if(Point[i]<Left[now]) continue;
		if(Point[i]>Right[now]) break;
		--vis[Point[i]];
	}
}
inline bool CMP(int a,int b)
{
	return a<b;
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>Left[i]>>Right[i];
	for(int i=1;i<=m;++i){
		cin>>Point[i];
		vis.insert(make_pair(Point[i],0));
	}
	sort(Point+1,Point+m+1,CMP);
	dfs(1);
	cout<<ans;
	return 0;
}
