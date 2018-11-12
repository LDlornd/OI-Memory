#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=200001;
int n,m,opt,l,r,k;
int arr[MAXN],temp[MAXN];
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=x*10+c-'0';
	return x*f;
}
inline void del(){
	for(int i=1;i<n;++i)
		arr[i]=arr[i+1];
	--n;
}
inline void add(){
	for(int i=(++n);i>1;--i)
		arr[i]=arr[i-1];
	arr[1]=read();
}
inline bool CMP(int a,int b){return a<b;}
inline void query(){
	l=read();r=read();k=read();
	for(int i=l;i<=r;++i) temp[i]=arr[i];
	sort(temp+l,temp+r+1,CMP);
	printf("%d\n",temp[l+k-1]);
}
int main(){
	n=read();m=read();
	for(int i=1;i<=n;++i) arr[i]=read();
	while(m--){
		opt=read();
		if(opt==1) del();
		if(opt==2) add();
		if(opt==3) query();
	}
	return 0;
}
