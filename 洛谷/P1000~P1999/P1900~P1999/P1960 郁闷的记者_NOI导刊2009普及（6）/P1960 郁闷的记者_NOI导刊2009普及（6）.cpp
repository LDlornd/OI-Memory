#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
const int MAXN=5001;
int n,m,u,v,flag=0;
int rudu[MAXN];
int res[MAXN],head=1,tail=0;
struct edge
{
	int v;
	edge *Next;
	edge() {v=0;Next=NULL;}
}*con[MAXN];
inline void ins(int start,int end)
{
	edge *p=new(edge);
	p->v=end;
	p->Next=con[start];
	con[start]=p;
	++rudu[end];
}
inline void top_sort()
{
	int sum=0;
	for(int i=1;i<=n;++i)
		if(rudu[i]==0) {res[++tail]=i;++sum;}
	if(sum>1) flag=1;
	while(head<=tail){
		int nv=res[head++];sum=0;
		for(edge *p=con[nv];p;p=p->Next){
			int vv=p->v;
			if(--rudu[vv]==0) {res[++tail]=vv;++sum;}
		}
		if(sum>1) flag=1;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	memset(rudu,0,sizeof(rudu));
	cin>>n>>m;
	while(m--)
		{cin>>u>>v;ins(u,v);}
	top_sort();
	for(int i=1;i<=n;++i) cout<<res[i]<<endl;
	cout<<flag;
	return 0;
}
