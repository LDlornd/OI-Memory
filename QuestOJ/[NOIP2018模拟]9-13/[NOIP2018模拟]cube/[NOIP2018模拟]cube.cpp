#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN=3e4+5;
char opt;
int n,q,u,v;
int fa[MAXN],Size[MAXN],num[MAXN];
int getfa(int a){
	if(fa[a]==a) return a;
	int temp=getfa(fa[a]);
	num[a]+=num[fa[a]];
	//cout<<num[fa[a]]<<" "<<Size[fa[a]]<<endl;
	return fa[a]=temp;
}
void Merge(int a,int b){
	a=getfa(a);b=getfa(b);
	fa[a]=b;
	num[a]+=Size[b];
	Size[b]+=Size[a];
}
int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	q=n=read();
	for(int i=1;i<=n;++i)
		{fa[i]=i;Size[i]=1;num[i]=0;}
	while(q--){
		opt=getchar();
		while(opt!='M'&&opt!='C') opt=getchar();
		u=read();
		if(opt=='M'){
			v=read();
			Merge(u,v);
		}
		else{
			getfa(u);
			printf("%d\n",num[u]);
		}
	}
	return 0;
}
