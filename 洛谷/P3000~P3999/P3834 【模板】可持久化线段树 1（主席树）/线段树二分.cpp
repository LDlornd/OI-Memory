#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
using namespace std;
const int INF=1e9+7;
const int MAXN=2e5+5;
int n,q,ql,qr,qk;
int arr[MAXN];
struct segtree{
	vector<int> val;
	int Start,End,Size;
	segtree *son[2];
	segtree(){
		val.clear();Start=End=0;
		son[0]=son[1]=NULL;
	}
	void update(){
		int s1=son[0]->Size,s2=son[1]->Size;
		int p1=1,p2=1;
		val.push_back(INF);
		while(p1<=s1&&p2<=s2){
			if(son[0]->val[p1]<son[1]->val[p2]) val.push_back(son[0]->val[p1++]);
			else val.push_back(son[1]->val[p2++]);
		}
		while(p1<=s1) val.push_back(son[0]->val[p1++]);
		while(p2<=s2) val.push_back(son[1]->val[p2++]);
		Size=s1+s2;
	}
	void build(int nstart,int nend){
		Start=nstart;End=nend;
		if(Start==End){
			val.push_back(INF);
			val.push_back(arr[Start]);
			Size=1;
			return;
		}
		int mid=(Start+End)>>1;
		(son[0]=new(segtree))->build(Start,mid);
		(son[1]=new(segtree))->build(mid+1,End);
		update();
	}
	int low_bound(int key){
		int l=1,r=Size,temp=0;
		while(l<=r){
			int mid=(l+r)>>1;
			if(val[mid]<=key) {temp=mid;l=mid+1;}
			else r=mid-1;
		}
		//cout<<key<<" "<<temp<<endl;
		return temp;
	}
	int query(int nstart,int nend,int key){
		if(Start==nstart&&End==nend) return low_bound(key);
		int mid=(Start+End)>>1;
		if(nend<=mid) return son[0]->query(nstart,nend,key);
		else if(nstart>mid) return son[1]->query(nstart,nend,key);
		else return son[0]->query(nstart,mid,key)+son[1]->query(mid+1,nend,key);
	}
}*root;
int Search(int Left,int Right,int key){
	int l=-INF,r=INF,temp=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(root->query(Left,Right,mid)>=key) {temp=mid;r=mid-1;}
		else l=mid+1;
	}
	return temp;
}
int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	n=read();q=read();
	for(int i=1;i<=n;++i) arr[i]=read();
	(root=new(segtree))->build(1,n);
	while(q--){
		ql=read();qr=read();qk=read();
		printf("%d\n",Search(ql,qr,qk));
	}
	return 0;
}
