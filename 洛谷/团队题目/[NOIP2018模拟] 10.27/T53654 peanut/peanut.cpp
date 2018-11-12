#include<cmath>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=25;
int n,m,k,cnt=0,now=0,ans=0;
struct node{
	int x,y,val;
	node(int xx=0,int yy=0,int vv=0) {x=xx;y=yy;val=vv;}
}arr[MAXN*MAXN];
bool CMP(const node &a,const node &b){
	return a.val>b.val;
}
int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	freopen("peanut.in","r",stdin);
	freopen("peanut.out","w",stdout);
	n=read();m=read();k=read();
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			int tmp=read();
			if(tmp) arr[++cnt]=node(i,j,tmp);
		}
	}
	sort(arr+1,arr+cnt+1,CMP);
	arr[0].y=arr[1].y;
	for(int i=1;i<=cnt;++i){
		now+=(abs(arr[i].x-arr[i-1].x)+abs(arr[i].y-arr[i-1].y)+1);
		if(now+arr[i].x>k) break;
		ans+=arr[i].val;
	}
	printf("%d",ans);
	return 0;
}
