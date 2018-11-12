#include<cstdio>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
const int MAXN1=10005;
const int MAXN2=100005;
int n,c,d,flag,now=0,ans=0;
double arr[MAXN1],ntime[2];
bool CMP(double a,double b){
	return a<b;
}
int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='0') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	n=read();c=read();d=read();flag=c+d;
	for(int i=1;i<=n;++i) scanf("%lf",&arr[i]);
	sort(arr+1,arr+n+1,CMP);
	for(int i=1;i<=n;++i){
		if(now+arr[i]>flag) break;
		now+=arr[i];
		++ans;
	}
	printf("%d",ans);
	return 0;
}
