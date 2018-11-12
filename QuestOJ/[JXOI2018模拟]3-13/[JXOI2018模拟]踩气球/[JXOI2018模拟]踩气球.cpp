#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
using namespace std;
const int MAXN=1e5+1;
int n,m,num,k,ans=0;
int arr[MAXN],tot[MAXN];
struct segtree *root;
struct que{
	int Left,Right;
	que() {Left=Right=0;}
}Q[MAXN];
struct segtree{
	vector<int> A;
	int Start,End,val;
	segtree *leftson,*rightson;
	segtree() {A.clear();Start=End=val=0;leftson=rightson=NULL;}
	inline void update() {val=leftson->val+rightson->val;}
	inline void build(int nstart,int nend){
		Start=nstart;End=nend;
		if(nstart==nend) {val=arr[nstart];return;}
		int mid=(nstart+nend)>>1;
		(leftson=new(segtree))->build(nstart,mid);
		(rightson=new(segtree))->build(mid+1,nend);
		update();
	}
	inline void ins(int nstart,int nend,int key){
		if(Start==nstart&&End==nend){
			A.push_back(key);
			++tot[key];
			return;
		}
		int mid=(Start+End)>>1;
		if(nend<=mid) leftson->ins(nstart,nend,key);
		else if(nstart>mid) rightson->ins(nstart,nend,key);
		else {leftson->ins(nstart,mid,key);rightson->ins(mid+1,nend,key);}
	}
	inline void modify(int place){
		if(Start==place&&End==place){
			val=0;
			int Size=A.size();
			for(int i=0;i<Size;++i){
				int now=A[i];
				if(--tot[now]==0) ++ans;
			}
			return;
		}
		int mid=(Start+End)>>1;
		if(mid>=place) leftson->modify(place);
		else rightson->modify(place);
		update();
		if(val==0){
			int Size=A.size();
			for(int i=0;i<Size;++i){
				int now=A[i];
				if(--tot[now]==0) ++ans;
			}
		}
		return;
	}
};
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>arr[i];
	(root=new(segtree))->build(1,n);
	for(int i=1;i<=m;++i){
		cin>>Q[i].Left>>Q[i].Right;
		root->ins(Q[i].Left,Q[i].Right,i);
	}
	cin>>num;
	while(num--){
		cin>>k;
		k=(k+ans-1)%n+1;
		--arr[k];
		if(arr[k]==0) root->modify(k);
		cout<<ans<<endl;
	}
	return 0;
}
