#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
const int MAXN=100001;
struct child
{
	int num;
	child *next=NULL;
};
struct point
{
	int father,data;
	child firstchild;
};
//int fa[MAXN],du[MAXN];
point a[MAXN];
child *p,*v;
int main()
{
	//freopen("sample1.in","r",stdin);
	memset(a,0,sizeof(a));
	a[1].father=0;
	int n,m,x;
	long long int ans=0;
	scanf("%d%d",&n,&m);
	for(int i=2;i<=n;++i)
	{
		scanf("%d",&a[i].father);
		p=new(child);
		v=&a[a[i].father].firstchild;
		while(v->next!=NULL)
			v=v->next;
		v->num=i;
		v->next=p;
	}
	/*for(int i=1;i<=n;++i)
	{
		printf("case%d:\nfather==%d data==%d\nsons ",i,a[i].father,a[i].data);
		for(p=&a[i].firstchild;p->next!=NULL;p=p->next)
		{
			printf("%d ",p->num);
		}
		printf("\n");
	}*/
	for(int i=0;i<m;++i)
	{
		scanf("%d",&x);
		++a[x].data;
		//cout<<a[x].data<<" ";
		ans+=a[x].data;
		++a[a[x].father].data;
		//cout<<a[a[x].father].data<<" ";
		if(a[x].father!=0) ans+=a[a[x].father].data;
		for(p=&a[x].firstchild;p->next!=NULL;p=p->next)
		{
			++a[p->num].data;
			//cout<<a[p->num].data<<" ";
			ans+=a[p->num].data;
		}
		//cout<<ans<<endl;
	}
	printf("%d",ans);
	return 0;
}
