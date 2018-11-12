#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
const int MAXN=1001;
const int INF=2000000000;
long long int ans=0,dist[MAXN];
int n,m,k,s,u,v,a,b,c;
int fa[MAXN],flag[MAXN];
int Queue[MAXN],head,tail;
bool vis[MAXN];
struct edge{
	int A,B,C,num;
	edge() {A=B=C=num=0;}
}con[MAXN][MAXN];
inline void ins(int Start,int End,int aa,int bb,int cc){
	con[Start][End].A=aa;
	con[Start][End].B=bb;
	con[Start][End].C=cc;
	con[Start][End].num=1;
}
inline int spfa(){
	for(int i=2;i<=n;++i) dist[i]=INF;dist[1]=0;
	head=tail=1;Queue[1]=1;vis[1]=true;
	while((head%MAXN)<=(tail%MAXN)){
		int nv=Queue[head];vis[nv]=false;
		for(int vv=1;vv<=n;++vv){
			edge &temp=con[nv][vv];
			if(temp.num==0||temp.num>temp.C) continue;
			int cost=temp.A*temp.num+temp.B;
			if(dist[vv]>dist[nv]+cost){
				dist[vv]=dist[nv]+cost;
				fa[vv]=nv;
				if(vis[vv]==false){
					vis[vv]=true;
					tail=(tail==MAXN-1)?0:tail+1;
					Queue[tail]=vv;
				}
			}
		}
		head=(head==MAXN-1)?0:head+1;
	}
	int temp=INF,place;
	for(int i=1;i<=s;++i)
		if(dist[flag[i]]<temp){
			temp=dist[flag[i]];
			place=flag[i];
		}
	for(;place>1;place=fa[place]) ++con[fa[place]][place].num;
	return temp;
}
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=x*10+c-'0';
	return x*f;
}
int main(){
	n=read();m=read();k=read();s=read();
	for(int i=1;i<=s;++i) flag[i]=read();
	while(m--){
		u=read();v=read();a=read();b=read();c=read();
		ins(u,v,a,b,c);
	}
	while(k--){
		int temp=spfa();
		if(temp>=INF){
			printf("-1");
			return 0;
		}
		ans+=temp;
	}
	printf("%lld",ans);
}
