#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
const int MAXN=5e5+5;
int n,ans=1;
int color[MAXN];
int same[MAXN],tops=0;
int diff[MAXN],topd=0;
int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	n=read();color[1]=read();
	for(int i=2;i<=n;++i){
		color[i]=read();
		if(color[i]==color[1]) same[++tops]=i;
		else {diff[++topd]=i;++ans;}
	}
	for(int i=1;i<=tops;++i)
		for(int j=1;j<=topd;++j)
			if(same[i]%diff[j]==0) {++ans;break;}
	printf("%d",ans);
	return 0;
}
