#include<cstdio>
#include<iostream>
using namespace std;
typedef long long int ll;
const int MAXN=35;
int n;
int root[MAXN][MAXN];
ll arr[MAXN],ans[MAXN][MAXN];
ll getans(int l,int r){
	if(l>r) return 1;
	if(ans[l][r]) return ans[l][r];
	if(l==r) return arr[l];
	ll temp=0;
	for(int i=l;i<=r;++i){
		if(getans(l,i-1)*getans(i+1,r)+arr[i]>temp){
			temp=getans(l,i-1)*getans(i+1,r)+arr[i];
			root[l][r]=i;
		}
	}
	ans[l][r]=temp;
	return temp;
}
void dfs(int l,int r){
	if(l>r) return;
	if(l==r){
		printf("%d ",l);
		return;
	}
	else printf("%d ",root[l][r]);
	dfs(l,root[l][r]-1);
	dfs(root[l][r]+1,r);
}
template<typename T>
T read(){
	T x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	n=read<int>();
	for(int i=1;i<=n;++i) arr[i]=read<ll>();
	printf("%lld\n",getans(1,n));
	dfs(1,n);
	return 0;
}
