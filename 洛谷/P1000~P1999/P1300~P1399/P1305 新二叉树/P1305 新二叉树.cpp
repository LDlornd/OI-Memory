#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;
const int MAXN=30;
struct edge
{
	char data;
	edge *leftchild,*rightchild;
	edge() {leftchild=NULL;rightchild=NULL;}
}*con[MAXN];
inline void pre_bianli(edge *now)
{
	if(now==NULL) return;
	printf("%c",now->data);
	pre_bianli(now->leftchild);
	pre_bianli(now->rightchild);
}
int main()
{
	char a,b,c;
	int n,root;
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		scanf("\n%c%c%c",&a,&b,&c);
		if(i==0) root=a-'a';
		if(con[a-'a']==NULL) con[a-'a']=new(edge);
		con[a-'a']->data=a;
		if(b!='*') 
		{
			if(con[b-'a']==NULL) con[b-'a']=new(edge);
			con[a-'a']->leftchild=con[b-'a'];
		}
		if(c!='*')
		{
			if(con[c-'a']==NULL) con[c-'a']=new(edge);
			con[a-'a']->rightchild=con[c-'a'];
		}
	}
	pre_bianli(con[root]);
	return 0;
}
