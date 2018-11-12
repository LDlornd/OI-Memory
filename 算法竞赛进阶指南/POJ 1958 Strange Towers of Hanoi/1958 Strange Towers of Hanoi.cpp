#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN=115;
int three[MAXN],four[MAXN];
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	for(int i=1;i<=12;++i) three[i]=three[i-1]*2+1;
	for(int w=1;w<=12;++w){
		four[w]=2147483647;
		for(int k=1;k<=w;++k){
			four[w]=min(four[w],2*four[w-k]+three[k]);
		}
		printf("%d\n",four[w]);
	}
	return 0;
}
