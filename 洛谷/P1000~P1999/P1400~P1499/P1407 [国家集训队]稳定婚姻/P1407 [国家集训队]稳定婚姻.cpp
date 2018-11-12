#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<map>
using namespace std;
const int MAXN=401;
string s1,s2;
int n,m,tot=0;
int dfn[MAXN],low[MAXN];
int Stack[MAXN],top=0;
map<string,int> MAP;
struct edge{
	int v;
	edge *nex;
	edge() {v=0;nex=NULL;}
}*con[MAXN];
inline void ins(int Start,int End){
	edge *p=new(edge);
	p->v=End;
	p->nex=con[Start];con[Start]=p;
}
inline void tarjan(int nv){
	
}
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		cin>>s1>>s2;
		MAP.insert(make_pair(s1,++tot));
		MAP.insert(make_pair(s2,++tot));
		ins(tot-1,tot);
	}
	m=read();
	while(m--){
		cin>>s1>>s2;
		ins(MAP[s2],MAP[s1]);
	}
	
	return 0;
}
