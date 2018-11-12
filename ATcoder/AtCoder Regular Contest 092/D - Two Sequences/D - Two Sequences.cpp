#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=200001;
int n;
int a[MAXN],b[MAXN],A[MAXN],B[MAXN],ans=0;
inline bool CMP(int x,int y){
	return x<y;
}
inline int read()
{
	int x=0,f=1;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x*f;
}
int main(){
	n=read();
	for(int i=1;i<=n;++i) a[i]=read();
	for(int i=1;i<=n;++i) b[i]=read();
	for(int w=0;w<=28;++w){
		for(int i=1;i<=n;++i){
			A[i]=a[i]&((1<<(w+1))-1);
			B[i]=b[i]&((1<<(w+1))-1);
		}
		sort(B+1,B+n+1,CMP);
		for(int i=1;i<=n;++i){
			int l1=lower_bound(B+1,B+n+1,(1<<w)-A[i])-B;
			int r1=lower_bound(B+1,B+n+1,(1<<(w+1))-A[i])-B-1;
			int l2=lower_bound(B+1,B+n+1,3*(1<<w)-A[i])-B;
			int r2=lower_bound(B+1,B+n+1,(1<<(w+2))-A[i])-B-1;
			if((r1-l1+r2-l2+2)&1) ans^=(1<<w);
		}
	}
	printf("%d",ans);
	return 0;
}
