#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
const int MAXN1=100001;
const int MAXN2=5000001;
int n,m,u,v,tot=0;
struct B{
	int Left,Right;
	B() {Left=Right=0;}
}bian[MAXN2];
struct edge{
	int v;
	edge *Next;
	edge() {v=0;Next=NULL;}
}*con[MAXN1];
inline void ins(int Start,int End){
	edge *p=new(edge);
	p->v=End;
	p->Next=con[Start];
	con[Start]=p;
	bian[++tot].Left=Start;
	bian[tot].Right=End;
}
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
inline void print(int ans1,int ans2,int ans3){
	if(ans1>ans2) swap(ans1,ans2);
	if(ans1>ans3) swap(ans1,ans3);
	if(ans2>ans3) swap(ans2,ans3);
	printf("%d %d %d",ans1,ans2,ans3);
}
inline bool judge(int nu,int nv){
	set<int> a,b,c;
	set<int>::iterator it;
	for(edge *p=con[nu];p;p=p->Next) a.insert(p->v);
	for(edge *p=con[nv];p;p=p->Next) b.insert(p->v);
	set_intersection(a.begin(),a.end(),b.begin(),b.end(),inserter(c,c.begin()));
	for(it=c.begin();it!=c.end();++it){
		print(nu,nv,*it);
		return true;
	}
	return false;
}
int main(){
	n=read();m=read();
	while(m--){
		u=read();v=read();
		ins(u,v);ins(v,u);
	}
	for(int i=1;i<=tot;i+=2)
		if(judge(bian[i].Left,bian[i].Right)) break;
	return 0;
}
