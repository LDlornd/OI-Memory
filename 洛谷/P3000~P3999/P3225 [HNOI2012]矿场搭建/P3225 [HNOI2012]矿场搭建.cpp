#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
const int MAXN=501;
long long int ans=0,fanganshu=1;//��¼���յĴ𰸣��������뷽���� 
int n,m,u,v,fenliangtot=0,casenum=0;//������������������ߵ���Ϣ����ʱ������u��v������ͨ�������������������� 
int zhan[MAXN],top=0;//dfsʱ�õ���ջ 
int visit=0,dfn[MAXN],low[MAXN];//tarjan���ر������ 
int root[MAXN],num[MAXN],roottot=0;//�ڽ���tarjanʱ��¼���ڵ��Լ�ɾ���ýڵ��ķ�������
//������ʱ�»����ͼ����ͨ����������ǿ��˸�roottot��¼tarjanʱ���ڵ�ĸ���
bool vis[MAXN];//dfsʱ�ã���ʵ�ϸо���һ�������˵�dfn���飩 
struct fenliang//��¼ͼ��ÿһ������ͨ������������ 
{
	int num,gediannum;//��ͨ�����еķǸ����������� 
	fenliang() {num=0;gediannum=0;}
}group[MAXN];
struct edge//�ڽӱ��ͼ 
{
	int v;
	edge *NEXT;
	edge() {v=0;NEXT=NULL;}
}*con[MAXN];
inline void ins(int start,int end)//��ͼ�мӱ� 
{
	edge *p=new(edge);
	p->v=end;
	p->NEXT=con[start];
	con[start]=p;
}
inline void tarjan(int nv,int father)//tarjanģ�� 
{
	dfn[nv]=low[nv]=++visit;
	for(edge *p=con[nv];p;p=p->NEXT)
	{
		//nv��vv��ͬһ�����ϣ�����������������������У���
		//1��vv��nv�����ȣ���ʱ���������ı߾���һ�������
		//2��vv��nv�Ķ��ӽڵ�
		int vv=p->v;
		if(dfn[vv]==0)//���vv֮ǰû�б����ʹ�����vv��nv�Ķ��� 
		{
			tarjan(vv,nv);
			low[nv]=min(low[nv],low[vv]); //�ݹ��Լ����� 
			if(low[vv]>=dfn[nv]) ++num[nv];
			//low[vv]>=dfn[nv]˵����nv����һ��������û���κ�һ���ڵ������nv��������ȥ
			//����ȥ��nv��ͼ�Ͳ���ͨ�ˣ�nv�Ǹ�㣩
			//����Ϊ���۸��ڵ�ȥ��֮��ͼ�Ƿ���ͨ��low[vv]>=dfn[nv]һ�������������Ҫ��1����main������ 
		}
		else if(vv!=father) low[nv]=min(low[nv],dfn[vv]);//����������һ 
	}
}
inline void dfs(int nv)
{
	vis[nv]=true;
	zhan[++top]=nv;//�ڱ���ʱ�ѱ������Ľڵ���ջ 
	for(edge *p=con[nv];p;p=p->NEXT)
	{
		int vv=p->v;
		if(vis[vv]==false)
		{
			dfs(vv);//��ʵ���������������tarjanҲ���Ƕ���������ж� 
			//������ͼ��ǿ��ͨ����ʱ������ʹ�ù�һ��ջ����ջ�е�Ԫ���п�����ͬһ��ǿ��ͨ��������
			//�������������ͼ��ͬ���ĵ���ֻ�����ǰ�ǿ��ͨ����������˫��ͨ���� 
			//���������ʵ�Ϻ�����ǿ��ͨ�ķ���ʱ��if(low[nv]==dfn[nv])ʱһ����
			//ֻ����һ������ܻ��ڶ��˫��ͨ�������棬��һ�������ֻ����һ��ǿ��ͨ��������
			//����whileҪ����ǰ����������������һ�����У��ж�������ǲ���һ����㣩
			if(low[vv]>=dfn[nv])
			{
				++fenliangtot; //����һ��˫��ͨ���� 
				int place=zhan[top];
				while(place!=nv)
				{
					--top;
					if(num[place]) ++group[fenliangtot].gediannum; //����������Ǹ�� 
					else ++group[fenliangtot].num; //��������㲻�Ǹ�� 
					place=zhan[top];
				}
				//������һ�������ĸ��ڵ������ 
				cout<<place<<" "<<num[place]<<"fuck"<<endl;
				if(num[place]) ++group[fenliangtot].gediannum;
				else ++group[fenliangtot].num;
				cout<<group[fenliangtot].gediannum<<" "<<group[fenliangtot].num<<endl;
			}
		}
	}
}
inline int read()//�ճ������Ż� 
{
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') {x=x*10+c-'0';c=getchar();}
	return x*f;
}
int main()
{
	while(true)
	{
		m=read();//������� 
		if(m==0) return 0;//������� 
		memset(con,0,sizeof(con));
		memset(dfn,0,sizeof(dfn));
		memset(num,0,sizeof(num));
		memset(vis,0,sizeof(vis));
		memset(group,0,sizeof(group));
		ans=n=roottot=fenliangtot=0;
		fanganshu=1;
		//�ó�ʼ���Ķ���ȫ����ʼ��һ�� 
		while(m--)
		{
			u=read();v=read();
			n=max(n,max(u,v));
			ins(u,v);ins(v,u);
		}//������ͼ�мӱߣ���Ϊ������ͼ�����Լ����� 
		cout<<n<<endl;
		for(int i=1;i<=n;++i)
			if(dfn[i]==0)
			{root[++roottot]=i;tarjan(i,0);}//tarjan�Ҹ�� 
		//��¼���ڵ�����Ϊ���ڵ�Ҫ���У�Ҫ��tarjan�������numֵ��һ����������ʵ��numֵ 
		for(int i=1;i<=n;++i) cout<<dfn[i]<<" ";cout<<endl;
		for(int i=1;i<=n;++i) cout<<low[i]<<" ";cout<<endl;
		for(int i=1;i<=roottot;++i)
			if(num[root[i]]!=0) --num[root[i]];//�����������������numֵΪ��ĵ���Ǹ���� 
		for(int i=1;i<=n;++i) cout<<num[i]<<" ";cout<<endl;
		for(int i=1;i<=n;++i)
			if(vis[i]==false) dfs(i);//dfs���˫��ͨ���� 
		for(int i=1;i<=fenliangtot;++i)//�����󵽵�˫��ͨ���������� 
		{
			int a=group[i].num,b=group[i].gediannum;
			cout<<a<<" "<<b<<endl;
			if(b>=2) continue;//������˫��ͨ�����и�������ڵ���2��˵����Ҫ������ 
			else if(b==1) {++ans;fanganshu*=a;}//������������1������Ҫ��һ������ 
			else if(b==0) {ans+=2;fanganshu*=(a*(a-1)/2);}//��������ڸ�㣬��Ҫ���������� 
		}
		printf("Case %d: %lld %lld\n",++casenum,ans,fanganshu);
	}
}
