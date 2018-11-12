#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long int ll;
const int MAXN=1e5+5;
int n,k,u;
int Size[MAXN];
ll ans[1005],arr[MAXN][11];
struct node{
	ll sum;
	int place;
	node(ll ss=0,int pp=0) {sum=ss;place=pp;}
	bool operator < (const node &a)const{
		return sum<a.sum;
	}
};
void Merge(ll *A,ll *B,ll *C,int key){
	priority_queue<node> q;
	for(int i=1;i<=key;++i)
		q.push(node(A[i]+B[1],1));
	for(int i=1;i<=key;++i){
		if(q.empty()) break;
		node temp=q.top();q.pop();
		C[i]=temp.sum;
		int np=temp.place;
		if(np<n) q.push(node(temp.sum-B[np]+B[np+1],np+1));
	}
}
bool CMP(ll a,ll b){
	return a>b;
}
template<typename T>
T read(){
	T x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	n=read<int>();k=read<int>();
	for(int i=1;i<=n;++i){
		Size[i]=read<int>();
		for(int j=1;j<=Size[i];++j)
			arr[i][j]=read<ll>();
		sort(arr[i]+1,arr[i]+Size[i]+1,CMP);
	}
	for(int i=1;i<=Size[1];++i) ans[i]=arr[1][i];
	for(int i=2;i<=n;++i)
		Merge(ans,arr[i],ans,k);
	printf("%lld",ans[k]);
	return 0;
}
