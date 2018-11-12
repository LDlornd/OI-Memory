#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=16;
int n,m,now;
int A[MAXN],temp[MAXN];
int len[MAXN],best[MAXN],tot;
long long int ans=0;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
inline int Search(int key){
	if(tot==0) return 1;
	int l=1,r=tot,tempans=tot+1;
	while(l<r){
		int mid=(l+r)>>1;
		if(best[mid]>key) r=(tempans=mid)-1;
		else l=mid+1;
	}
	if(best[l]>key) tempans=l;
	return tempans;
}
inline int get_LIS(){
	tot=0;
	for(int i=1;i<=n;++i){
		int place=Search(temp[i]);
		len[i]=place;
		best[place]=temp[i];
		if(place>tot) ++tot;
	}
	int maxlen=0;
	for(int i=1;i<=n;++i) maxlen=max(maxlen,len[i]);
	return maxlen;
}
int main(){
	n=read();m=read();
	for(int i=1;i<=m;++i) A[i]=read();
	for(int i=1;i<=n;++i) temp[i]=i;
	do{
		int len=get_LIS();
		if(len==m){
			now=1;
			for(int i=1;i<=n&&now<=m;++i)
				if(temp[i]==A[now]) ++now;
			if(now>m) ++ans;
		}
	}while(next_permutation(temp+1,temp+n+1));
	printf("%lld",ans);
	return 0;
}
