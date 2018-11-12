#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN=1005;
char opt;
int n,d,u,v;
int x[MAXN],y[MAXN];
int flag[MAXN],tot=0;
int fa[MAXN],Size[MAXN];
int getfa(int key){
	if(fa[key]==key) return key;
	else return fa[key]=getfa(fa[key]);
}
void Merge(int a,int b){
	a=getfa(a);b=getfa(b);
	if(Size[a]<Size[b]) swap(a,b);
	fa[b]=a;Size[a]+=Size[b];
}
int get_dist(int a,int b){
	return (x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]);
}
char getopt(){
	char c=getchar();
	while(c<'A'||c>'Z'){
		c=getchar();
		if(c==EOF) return EOF;
	}
	return c;
}
int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	freopen("test.in","r",stdin);
	n=read();d=read();d=d*d;
	for(int i=1;i<=n;++i){
		fa[i]=i;Size[i]=1;
		x[i]=read();y[i]=read();
	}
	while(true){
		opt=getopt();
		if(opt==EOF) break;
		if(opt=='O'){
			u=read();
			for(int i=1;i<=tot;++i)
				if(get_dist(u,flag[i])<=d&&getfa(u)!=getfa(flag[i]))
					Merge(u,flag[i]);
			flag[++tot]=u;
		}
		else{
			u=read();v=read();
			if(getfa(u)==getfa(v)) printf("SUCCESS\n");
			else printf("FAIL\n");
		}
	}
	return 0;
}
