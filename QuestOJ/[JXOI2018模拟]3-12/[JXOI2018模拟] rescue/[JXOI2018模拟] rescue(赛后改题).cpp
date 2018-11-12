#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
const int MAXN=31;
int n,arr[MAXN];
int rudu[MAXN],res[MAXN],head,tail;
int dp[MAXN];
struct edge{
	int v;
	edge *Next;
	edge() {v=0;Next=NULL;}
}*con[MAXN],*anti[MAXN];
inline void ins(int Start,int End,edge *a[],bool flag){
	edge *p=new(edge);
	p->v=End;
	p->Next=a[Start];
	a[Start]=p;
	if(flag) ++rudu[End];
}
inline void top_sort(){
	head=1;tail=0;
	for(int i=1;i<=n;++i) if(rudu[i]==0) res[++tail]=i;
	while(head<=tail){
		int nv=res[head++];
		for(edge *p=anti[nv];p;p=p->Next){
			int vv=p->v;
			if((--rudu[vv])==0) res[++tail]=vv;
		}
	}
}
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=x*10+c-'0';
	return x*f;
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		arr[i]=read();
		for(int j=1;j<i;++j)
			if(arr[i]%arr[j]==0){
				ins(j,i,con,false);
				ins(i,j,anti,true);
			}
	}
	top_sort();
	for(int i=1;i<=n;++i){
		printf("%d 's sons: ",i);
		for(edge *p=con[i];p;p=p->Next)
			cout<<p->v<<" ";
		cout<<endl;
	}
	for(int i=1;i<=n;++i) cout<<res[i]<<" ";cout<<endl;
	for(int i=1;i<=n;++i) dp[i]=1;
	for(int i=1;i<=n;++i){
		int nv=res[i];
		for(edge *p=con[nv];p;p=p->Next){
			int vv=p->v;
			if(arr[nv]==arr[vv]) dp[nv]=min(dp[nv],dp[vv]+1);
			else dp[nv]=max(dp[nv],dp[vv]+1);
		}
	}
	printf("%d",dp[1]);
	return 0;
}
