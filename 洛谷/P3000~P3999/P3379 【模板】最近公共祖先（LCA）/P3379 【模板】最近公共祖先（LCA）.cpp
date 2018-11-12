#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<vector>
using namespace std;
const int MAXN=500001;
struct edge
{
	int v;
	edge *next;
	edge() {next=NULL;}
}*con[MAXN];
vector<int> tree[MAXN];
int depth[MAXN];
int first[MAXN],array[2*MAXN],len=0;
int ans[30][MAXN*2];
inline void ins(int start,int end)
{
	edge *p=new(edge);
	p->v=end;
	p->next=con[start];
	con[start]=p;
}
inline void gettree(int nowroot,int fa,int deep)
{
	int s=tree[nowroot].size();
	depth[nowroot]=deep;
	for(int i=0;i<s;++i)
	{
		int nv=tree[nowroot][i];
		if(nv!=fa)
		{
			ins(nowroot,nv);
			gettree(nv,nowroot,deep+1);
		}
	}
}
void dfs(int nv)
{
	array[++len]=nv;
	if(first[nv]==0) first[nv]=len;
	for(edge *p=con[nv];p!=NULL;p=p->next)
	{
		dfs(p->v);
		array[++len]=nv;
	}
}
void getready()
{
	for(int i=1;i<=len;++i) ans[0][i]=array[i];
	for(int i=1;i<30;++i)
		for(int j=1;(j+(1<<i))<=len;++j)
		{
			if(depth[ans[i-1][j]]<depth[ans[i-1][j+(1<<(i-1))]]) ans[i][j]=ans[i-1][j];
			else ans[i][j]=ans[i-1][j+(1<<(i-1))];
		}
}
inline int Search(int Left,int Right)
{
    int k=0;
    while(1<<(k+1)<=Right-Left+1) ++k;
    if(depth[ans[k][Left]]<depth[ans[k][Right-(1<<k)+1]]) return ans[k][Left];
    else return ans[k][Right-(1<<k)+1];
}
inline int read()
{
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') {x=x*10+c-'0';c=getchar();}
	return x;
}
int main()
{
	memset(first,0,sizeof(first));
	int n,q,root,x,y;
	//scanf("%d%d%d",&n,&q,&root);
	n=read();q=read();root=read();
	cout<<n<<" "<<q<<" "<<root<<endl;
	for(int w=1;w<n;++w)
	{
		//scanf("%d%d",&x,&y);
		x=read();y=read();
		cout<<x<<" "<<y<<endl;
		tree[x].push_back(y);
		tree[y].push_back(x);
	}
	gettree(root,0,0);
	dfs(root);
	getready();
	for(int w=0;w<q;++w)
	{
		//scanf("%d%d",&x,&y);
		x=read();y=read();
		cout<<x<<" "<<y<<endl;
		if(first[x]>first[y]) printf("%d\n",Search(first[y],first[x]));
        else printf("%d\n",Search(first[x],first[y]));
	}
	return 0;
}
