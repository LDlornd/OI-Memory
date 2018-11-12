#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN=101;
int n,k,l,r,ans=0;
int arr[MAXN];
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	n=read();k=read();
	for(int i=1;i<=n;++i) arr[i]=read();
	for(l=1;l<=n;++l)
		if(arr[l]>k) break;
		else ++ans;
	for(r=n;r>l;--r)
		if(arr[r]>k) break;
		else ++ans;
	printf("%d",ans);
	return 0;
}
