#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
int n,len,ans=0;
int arr[MAXN],cparr[MAXN];
bool CMP(int a,int b){
	return a<b;
}
int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	freopen("testdata.in","r",stdin);
	n=read();len=read();
	for(int i=1;i<=n;++i) arr[i]=read();
	for(int i=1;i+len-1<=n;++i){
		for(int j=1;j<=len;++j)
			cparr[j]=arr[i+j-1];
		sort(cparr+1,cparr+len+1,CMP);
		if(len&1) ++len;
		ans=max(ans,cparr[len>>1]);
	}
	printf("%d",ans);
	return 0;
}
