#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
#define N 2510
#define M 5010
#define fs first
#define sc second
#define chkmin(a,b) a=min(a,b)
#define pil pair<int,ll>
using namespace std;
const int mod=1000000007;
int n,m;
ll f[N][M],T,ans;
pil st[M];
int read()
{
	int x=0,f=1;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x*f;
}
struct edge
{
	int t;ll w;
	edge *next;
}*con[N];
void ins(int x,int y,ll w)
{
	edge *p=new edge;
	p->t=y;p->w=w;
	p->next=con[x];
	con[x]=p;
}
ll cal(pil a,pil b)// a better than b
{
	return (a.sc-b.sc)/(b.fs-a.fs);
}
int main()
{
	n=read();m=read();T=read();
	for(int i=1;i<=m;i++)
	{
		int x=read(),y=read(),w=read();
		ins(x,y,w);ins(y,x,w);
	}
	memset(f,0x3f,sizeof(f));
	f[1][0]=0;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			for(edge *p=con[j];p;p=p->next)
				chkmin(f[p->t][i],f[j][i-1]+p->w);					
	for(int i=2;i<=n;i++)
	{
		int top=0;
		for(int j=m;j;j--)
		{
			cout<<j<<" "<<top<<endl;
			pil tmp=make_pair(j,f[i][j]);
			while(top>1&&cal(tmp,st[top])<=cal(st[top],st[top-1])) top--;
			while(top&&tmp.sc<=st[top].sc) top--;
			st[++top]=tmp;
		}
		cout<<top<<"fuvk!!!!!!!!!!!!!!"<<endl;
		ll tim=0;
		for(int i=1;i<=top&&tim<=T;i++)
		{
			cout<<i<<" "<<tim<<" "<<top<<"fuck"<<endl;
			ll nxt=i==top?T:min(cal(st[i+1],st[i]),T);
			cout<<i<<" "<<nxt<<" "<<st[i].fs<<" "<<st[i].sc<<endl;
			ans=(ans+(nxt-tim+1)*st[i].sc%mod+(nxt+tim)*(nxt-tim+1)/2%mod*st[i].fs%mod)%mod;
			cout<<(nxt-tim+1)*st[i].sc%mod<<endl;
			cout<<(nxt+tim)*(nxt-tim+1)/2%mod*st[i].fs%mod<<endl;
			tim=nxt+1;
			cout<<ans<<endl;
		}
	}
	printf("%lld",ans);	
	return 0;
}
