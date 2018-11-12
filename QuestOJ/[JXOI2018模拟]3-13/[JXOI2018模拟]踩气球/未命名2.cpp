#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
using namespace std;
const int MAXN=1e5+1;
int n,m,num,k,ans=0;
int arr[MAXN];
struct que{
	int Left,Right;
	que() {Left=Right=0;}
}Q[MAXN];
struct segtree{
	vector<int> A,B;
	int Start,End,val;
	segtree *leftson,*rightson;
	segtree() {A.clear();B.clear();Start=End=val=0;leftson=rightson=NULL;}
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
		int mid=(Start+End)>>1;
		if((mid>=nstart&&mid<nend)||(nstart==nend&&nstart==Start)) {A.push_back(key);B.push_back(1);return;}
		if(mid>=nend) leftson->ins(nstart,nend,key);
		else if(mid<nstart) rightson->ins(nstart,nend,key);
	}
	inline int query(int nstart,int nend){
		if(Start==nstart&&End==nend) return val;
		int mid=(Start+End)>>1;
		if(nend<=mid) return leftson->query(nstart,nend);
		else if(nstart>mid) return rightson->query(nstart,nend);
		else return leftson->query(nstart,mid)+rightson->query(mid+1,nend);
	}
	inline bool modify(int place){
		if(Start==place&&End==place){
			--arr[place];--val;
			if(val==0){
				int Size=A.size();
				for(int i=0;i<Size;++i){
					int now=A[i];
					if(B[i]&&query(Q[now].Left,Q[now].Right)==0){
						++ans;B[i]=0;
					}
				}
				return true;
			}
			return false;
		}
		int mid=(Start+End)>>1;
		bool Flag;
		if(mid>=place) Flag=leftson->modify(place);
		else Flag=rightson->modify(place);
		update();
		if(Flag){
			int Size=A.size();
			for(int i=0;i<Size;++i){
				int now=A[i];
				if(B[i]&&query(Q[now].Left,Q[now].Right)==0){
					++ans;B[i]=0;
				}
			}
		}
		return Flag;
	}
	inline void dfs(){
		cout<<Start<<" "<<End<<" *** ";
		int Size=A.size();
		for(int i=0;i<Size;++i)
			cout<<A[i]<<" ";
		cout<<endl;
		if(Start==End) return;
		leftson->dfs();
		rightson->dfs();
	}
}*root;
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>arr[i];
	(root=new(segtree))->build(1,n);
	for(int i=1;i<=m;++i){
		cin>>Q[i].Left>>Q[i].Right;
		root->ins(Q[i].Left,Q[i].Right,i);
	}
	//root->dfs();
	cin>>num;
	while(num--){
		cin>>k;
		k=(k+ans-1)%n+1;
		root->modify(k);
		cout<<ans<<endl;
	}
	return 0;
}
