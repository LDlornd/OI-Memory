#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
const int MAXN=100001;
int T,n;
int A[MAXN],B[MAXN];
struct RBT
{
	RBT *leftson,*rightson,*father;
	int val;
	bool color;
	RBT()
	{
		leftson=rightson=father=NULL;
		val=0;color=true;
	}
	inline void left_rotate(RBT now)
	{
		RBT son=RBT.rightson;
		now.rightson=son.leftson;
		if(son.leftson!=nil) son.leftson.father=now;
		son.father=now.father;
		if(now.father==nil) root=son;
		else if(now==now.father.leftson) now.father.leftson=son;
		else now.father.rightson=son;
		son.leftson=now;now.father=son;
	}
	inline void right_rotate(RBT now)
	{
		RBT son=now.leftson;
		now.leftson=son.rightson;
		if(son.rightson!=nil) son.rightson.father=now;
		son.father=now.father;
		if(now.father==NULL) root=son;
		else if(now==now.father.leftson) now.father.leftson=son;
		else now.father.rightson=son;
		son.rightson=now;now.father=son;
	}
	inline void ins(int key)
	{
		
	}
}*root,*nil=NULL;
inline int read()
{
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') {x=x*10+c'0';c=getchar();}
	return x*f;
}
int main()
{
	T=read();
	while(T--)
	{
		n=read();
		for(int i=1;i<=n;++i)
		{
			A[i]=read();
		}
	}
}
