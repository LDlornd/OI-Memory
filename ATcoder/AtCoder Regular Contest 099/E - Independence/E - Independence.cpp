#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
const int MAXN=701;
int n,m,u,v,big,small,ans;
int bq[MAXN],bh,bt;
int sq[MAXN],sh,st;
bool flag[MAXN][MAXN],vis[MAXN];
inline bool dfs(int now){
	if(now==n+1) return true;
	bool bf=true,sf=true;
	if(bt<big){
		for(int i=1;i<=bt;++i)
			if(flag[now][bq[i]]==false){
				cout<<now<<" "<<bq[i]<<"bigfuck"<<endl;
				bf=false;break;
			}
	}
	else bf=false;
	if(st<small){
		for(int i=1;i<=st;++i)
			if(flag[now][sq[i]]==false){
				cout<<now<<" "<<sq[i]<<"smallfuck"<<endl;
				sf=false;break;
			}
	}
	else sf=false;
	cout<<"flag[1][2]=="<<flag[1][2]<<flag[2][1]<<" "<<now<<" "<<bf<<" "<<sf<<endl;
	if(bf==false&&sf==false) return false;
	if(bf==false&&sf==true){
		sq[++st]=now;
		if(dfs(now+1)) return true;
		else {--st;return false;}
	}
	if(bf==true&&sf==false){
		bq[++bt]=now;
		if(dfs(now+1)) return true;
		else {--bt;return false;}
	}
	if(bf&&sf){
		sq[++st]=now;
		if(dfs(now+1)) return true;
		else --st;
		bq[++bt]=now;
		if(dfs(now+1)) return true;
		else {--bt;return false;}
	}
}
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	n=read();m=read();
	for(int i=1;i<=m;++i){
		u=read();v=read();
		flag[u][v]=flag[v][u]=true;
	}
	for(small=0,big=n;small<=big;++small,--big){
		if((small*(small-1)+big*(big-1))>(m<<1)) continue;
		bt=st=0;
		sq[++st]=1;
		cout<<small<<" "<<big<<endl;
		if(dfs(2)){
			ans=((small*(small-1)+big*(big-1))>>1);
			printf("%d",ans);
			return 0;
		}
		cout<<"fuck***********************************8"<<endl;
		bt=st=0;
		bq[++bt]=1;
		if(dfs(2)){
			ans=((small*(small-1)+big*(big-1))>>1);
			printf("%d",ans);
			return 0;
		}
	}
	printf("-1");
	return 0;
}
