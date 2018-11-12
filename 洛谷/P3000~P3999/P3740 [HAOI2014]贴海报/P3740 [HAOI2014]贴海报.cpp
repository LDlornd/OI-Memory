#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;
const int MAXN=1001;
int n,m,ans=0;
int l[MAXN],r[MAXN];
bool flag;
struct segtree{
	int Left,Right;
	bool val;
	segtree *son[2];
	segtree(){
		Left=Right=val=false;
		son[0]=son[1]=NULL;
	}
	inline void getready(int ll,int rr) {Left=ll;Right=rr;}
	inline void update() {val=son[0]->val&&son[1]->val;}
	inline void modify(int Start,int End){
		if(val) return;
		if(Left==Start&&Right==End) {val=flag=true;return;}
		int mid=(Left+Right)>>1;
		if(son[0]==NULL) (son[0]=new(segtree))->getready(Left,mid);
		if(son[1]==NULL) (son[1]=new(segtree))->getready(mid+1,Right);
		if(mid>=End) son[0]->modify(Start,End);
		else if(mid<Start) son[1]->modify(Start,End);
		else {son[0]->modify(Start,mid);son[1]->modify(mid+1,End);}
		update();
	}
}*root;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	n=read();m=read();
	for(int i=1;i<=m;++i)
		{l[i]=read();r[i]=read();}
	(root=new(segtree))->getready(1,n);
	for(int i=m;i>0;--i){
		flag=false;
		root->modify(l[i],r[i]);
		ans+=flag;
	}
	printf("%d",ans);
	return 0;
}
