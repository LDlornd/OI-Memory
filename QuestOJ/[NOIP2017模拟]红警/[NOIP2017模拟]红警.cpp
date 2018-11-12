#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<queue>
using namespace std;
const int MAXN=100001;
int T,n,m,q1,q2,s,u,v;
int indofy[MAXN],inqyq[MAXN];
int res[MAXN];
struct edge{
	int v;
	edge *nex;
	edge() {v=0;nex=NULL;}
}*dofy[MAXN],*qyq[MAXN];
inline void ins(int Start,int End,edge *a[]){
	edge *p=new(edge);
	p->v=End;
	p->nex=a[Start];a[Start]=p;
}
struct MAX{
	int data;
	MAX(int dd=0) {data=dd;}
	bool operator <(const MAX &a)const{
		return !(data>a.data);
	}
};
struct MIN{
	int data;
	MIN(int dd=0) {data=dd;}
	bool operator <(const MIN &a)const{
		return !(data<a.data);
	}
};
priority_queue<MAX> QYQ;
priority_queue<MIN> DOFY;
inline bool dofy_topsort(){
	int tail=0;
	for(int i=1;i<=n;++i) if(indofy[i]==0) DOFY.push(MIN(i));
	while(!DOFY.empty()){
		int nv=res[++tail]=DOFY.top().data;
		DOFY.pop();
		for(edge *p=dofy[nv];p;p=p->nex){
			if((--indofy[p->v])==0) DOFY.push(MIN(p->v));
		}
	}
	return tail==n;
}
inline bool qyq_topsort(){
	int tail=0;
	for(int i=1;i<=n;++i) if(inqyq[i]==0) QYQ.push(MAX(i));
	while(!QYQ.empty()){
		int nv=res[++tail]=QYQ.top().data;
		QYQ.pop();
		for(edge *p=qyq[nv];p;p=p->nex){
			if((--inqyq[p->v])==0) QYQ.push(MAX(p->v));
		}
	}
	return tail==n;
}
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	T=read();
	while(T--){
		memset(dofy,0,sizeof(dofy));
		memset(qyq,0,sizeof(qyq));
		memset(indofy,0,sizeof(indofy));
		memset(inqyq,0,sizeof(inqyq));
		n=read();m=read();q1=read();q2=read();s=read();
		while(m--){
			u=read();v=read();
			ins(u,v,dofy);++indofy[v];
			ins(v,u,qyq);++inqyq[u];
		}
		if(q1==0) printf("DOFY\n");
		else{
			if(dofy_topsort()==false) printf("Impossible!\n");
			else{
				printf("%d",res[1]);
				for(int i=2;i<=n;++i)
					printf(" %d",res[i]);
				printf("\n");
			}
		}
		if(q2==0) printf("QYQ\n");
		else{
			if(qyq_topsort()==false) printf("Impossible!\n");
			else{
				printf("%d",res[n]);
				for(int i=n-1;i>=1;--i)
					printf(" %d",res[i]);
				printf("\n");
			}
		}
	}
	return 0;
}
