#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
const int MAXN=10001;//���ĵ��� 
int n,m,xx,yy,sp,ep,ans=1; 
int to[4];//�������� 
int dl1[MAXN],head1=1,tail1=1; //BFSʱ�õ��Ķ��� 
int dl2[MAXN],head2=1,tail2=1; //������˵�Ŀǰȴ���ܵ���ķ���Ķ��� 
bool light_up[MAXN],vis[MAXN]; //���Ƿ��Ѵ�   �Ƿ�������Ѿ������ʹ� 
int indl[MAXN];                //ÿ�������ĸ������֣����ǲ��ڶ����У� 
struct edge
{
	int v;
	edge *NEXT;
	edge() {v=0;NEXT=NULL;}
}*con[MAXN];                        //����ͼ�ķ�ʽȥ����Դ򿪵ĵƵ���Ϣ 
inline void ins(int start,int end)  //�µĹ�ϵ����һ���ߣ� 
{
	edge *p=new(edge);
	p->v=end;
	p->NEXT=con[start];
	con[start]=p;
}
inline bool check(int nowplace)          //�жϵ��Ƿ��ܹ����� 
{
	for(int i=0;i<4;++i)
	{
		int place=nowplace+to[i];
		if(place<1||place>n*n) continue;
		if(place%n==0&&to[i]==-1) continue;   //��bug 
		if(place%n==1&&to[i]==1) continue;    //��bug 
		if(vis[place]) return true;
	}
	return false;
}
inline void bfs()
{
	bool flag=false;      //�ж��ǲ���Ҫ��һ�α��� 
	head2=tail2=1;   //��һ�����еĳ�ʼ�� 
	while(head1<tail1)
	{
		int nv=dl1[head1++];indl[nv]=0;         //����Ԫ�س��� 
		if(check(nv)==false&&vis[nv]==false)    //�ж�Ŀǰ��������ܷ񱻵�����Ǳ����ͱ����������Ҫ��Ϊ��ͳһ 1 ����㣩 
			{dl2[tail2++]=nv;continue;}
		vis[nv]=true;flag=true;               //�������з�����Ե�����ܻ�����µı仯�� 
		for(edge *p=con[nv];p;p=p->NEXT)
		{
			int vv=p->v;
			if(light_up[vv]==false)
				{light_up[vv]=true;++ans;}     //�������ŵƵķ���ĵ� 
			if(check(vv))                            //���������ܹ������� 
				if(indl[vv]==0&&vis[vv]==false)        
					{dl1[tail1++]=vv;indl[vv]=1;}	//�ŵ������Ķ�����ȥ 
				else continue;
			else if(indl[vv]==0&&vis[vv]==false)      
					{dl2[tail2++]=vv;indl[vv]=2;}	//������ܵ���ŵ�����һ��������ȥ����������һ�� 
		}               //ע�⣺�����ʱֻ��ȡ���ڶ�����δ�����ʹ��ķ��䣬��Ȼ�ᵼ���ظ��������������޵ݹ� 
	}
	if(flag)        //����з�����Ա����� 
	{
		for(int i=head2;i<=tail2;++i)
			dl1[i]=dl2[i];
		head1=head2;tail1=tail2;      //��������Ҫ������д�������������ö���2���Ƕ���1 
		bfs();               //�������� 
	}
}
inline int read()   //�ճ������Ż� 
{
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') {x=x*10+c-'0';c=getchar();}
	return x*f;
}
int main()
{
	memset(indl,0,sizeof(indl));
	memset(light_up,0,sizeof(light_up));
	memset(vis,0,sizeof(vis));
	n=read();m=read();
	to[0]=-1*n;to[1]=1;to[2]=n;to[3]=-1;
	while(m--)
	{
		sp=(((xx=read())-1)*n+(yy=read()));  //��ά���� 
		ep=(((xx=read())-1)*n+(yy=read()));	 //��ά���� 
		ins(sp,ep);
	}
	dl1[tail1++]=1;indl[1]=1;
	vis[1]=true;light_up[1]=true;      //���ֳ�ʼ�� 
	bfs();
	printf("%d",ans);
	return 0;
}
