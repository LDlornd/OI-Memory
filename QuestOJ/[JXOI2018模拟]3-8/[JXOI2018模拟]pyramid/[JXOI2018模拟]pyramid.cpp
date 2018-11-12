#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN=10001;
long long int ans=0;
int n,m,now=1,place;
int L[MAXN],R[MAXN],L1[MAXN],R1[MAXN];
int Heap[MAXN],tot=0;
inline void ins(int key){
	if(key==0) return;
	int now=tot+1;
	Heap[++tot]=key;
	while(now!=1){
		int father=now>>1;
		if(Heap[father]>=Heap[now]) return;
		swap(Heap[father],Heap[now]);
		now=father;
	}
}
inline void del(){
	int now=1;
	swap(Heap[1],Heap[tot--]);
	while((now<<1)<=tot){
		int son=now<<1;
		if(Heap[son]<=Heap[son+1]) ++son;
		if(Heap[now]>=Heap[son]) return;
		swap(Heap[now],Heap[son]);
		now=son;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>L[i]>>R[i];
		L1[i]=R[i];R1[i]=L[i];
	}
	for(int i=1;i<=m;++i){
		long long int temp=0;
		for(int j=now;j<=n;++j){
			if((R[j]-L[j]+1)*(j-now+1)>temp){
				temp=(R[j]-L[j]+1)*(j-now+1);
				place=j;
			}
		}
		ans+=temp;
		now=place+1;
	}
	cout<<ans;
	return 0;
}
