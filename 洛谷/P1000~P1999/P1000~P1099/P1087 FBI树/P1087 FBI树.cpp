#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;
const int MAXN=1025;
struct edge
{
	char c;
	edge *leftchild,*rightchild;
	edge() {leftchild=NULL;rightchild=NULL;}
}*root;
char s[MAXN];
inline void gouzao(int start,int end,edge *now)
{
	bool flag=true;
	int mid=(start+end)>>1;
	for(int i=start;i<end;++i)
		if(s[i]!=s[i+1]) flag=false;
	if(flag)
	{
		if(s[start]=='0') now->c='B';
		if(s[start]=='1') now->c='I';
	}
	else now->c='F';
	if(start==end) return;
	now->leftchild=new(edge);
	now->rightchild=new(edge);
	gouzao(start,mid,now->leftchild);
	gouzao(mid+1,end,now->rightchild);
}
inline void after_bianli(edge *now)
{
	if(now==NULL) return;
	after_bianli(now->leftchild);
	after_bianli(now->rightchild);
	printf("%c",now->c);
}
int main()
{
	int n;
	scanf("%d\n",&n);
	n=1<<n;
	for(int i=1;i<=n;++i)
		scanf("%c",&s[i]);
	root=new(edge);
	gouzao(1,n,root);
	after_bianli(root);
	return 0;
}
