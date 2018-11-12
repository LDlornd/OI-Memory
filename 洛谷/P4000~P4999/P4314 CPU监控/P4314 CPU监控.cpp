#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
const int INF=2147483647;
const int MAXN=100001;
char opt;
int T,E,x,y,z;
int arr[MAXN];
struct segtree{
	int Start,End;
	int now_val,history_val;
	int addlazy,changelazy;
	bool add,change;
	segtree *son[2];
	segtree(){
		Start=End=0;
		now_val=history_val=-INF;
		addlazy=changelazy=0;
		add=false;change=false;
		son[0]=son[1]=NULL;
	}
	inline void update(){
		now_val=max(son[0]->now_val,son[1]->now_val);
		history_val=max(history_val,now_val);
	}
	inline void caculate(){
		if(add) now_val+=addlazy;
		if(change) now_val=changelazy;
		history_val=max(history_val,now_val);
	}
	inline void push_down(){
		caculate();
		if(add){
			son[0]->addlazy+=addlazy;
			son[1]->addlazy+=addlazy;
			son[0]->add=son[1]->add=add;
		}
		if(change){
			son[0]->changelazy=changelazy;
			son[1]->changelazy=changelazy;
			son[0]->change=son[1]->change=change;
		}
		add=change=false;
	}
	inline void build(int nstart,int nend){
		Start=nstart;End=nend;
		if(Start==End){
			history_val=now_val=arr[Start];
			return;
		}
		int mid=(Start+End)>>1;
		(son[0]=new(segtree))->build(Start,mid);
		(son[1]=new(segtree))->build(mid+1,End);
		update();
	}
	inline void change_add(int nstart,int nend,int key){
		//cout<<Start<<" "<<End<<endl;
		if(son[0]!=NULL&&son[1]!=NULL) push_down();
		if(Start==nstart&&End==nend){
			addlazy=key;
			add=true;
			//cout<<Start<<" "<<End<<" "<<add<<endl;
			return;
		}
		int mid=(Start+End)>>1;
		if(nstart>mid) son[1]->change_add(nstart,nend,key);
		else if(nend<=mid) son[0]->change_add(nstart,nend,key);
		else{
			son[0]->change_add(nstart,mid,key);
			son[1]->change_add(mid+1,nend,key);
		}
	}
	inline void change_change(int nstart,int nend,int key){
		if(son[0]!=NULL&&son[1]!=NULL) push_down();
		if(Start==nstart&&End==nend){
			changelazy=key;
			change=true;
			return;
		}
		int mid=(Start+End)>>1;
		if(nstart>mid) son[1]->change_change(nstart,nend,key);
		else if(nend<=mid) son[0]->change_change(nstart,nend,key);
		else{
			son[0]->change_change(nstart,mid,key);
			son[1]->change_change(mid+1,nend,key);
		}
	}
	inline int query_now(int nstart,int nend){
		if(son[0]!=NULL&&son[1]!=NULL) push_down();
		if(Start==End) caculate();
		if(Start==nstart&&End==nend) return now_val;
		int mid=(Start+End)>>1;
		if(nstart>mid) return son[1]->query_now(nstart,nend);
		else if(nend<=mid) return son[0]->query_now(nstart,nend);
		else return max(son[0]->query_now(nstart,mid),son[1]->query_now(mid+1,nend));
	}
	inline int query_history(int nstart,int nend){
		if(son[0]!=NULL&&son[1]!=NULL) push_down();
		if(Start==End) caculate();
		if(Start==nstart&&End==nend) return history_val;
		int mid=(Start+End)>>1;
		if(nstart>mid) return son[1]->query_history(nstart,nend);
		else if(nend<=mid) return son[0]->query_history(nstart,nend);
		else return max(son[0]->query_history(nstart,mid),son[1]->query_history(mid+1,nend));
	}
	inline void bfs(){
		if(son[0]!=NULL&&son[1]!=NULL) push_down();
		//if(Start==End) caculate();
		cout<<Start<<" "<<End<<" "<<now_val<<" "<<history_val<<" "<<addlazy<<" "<<changelazy<<" "<<add<<" "<<change<<endl;
		if(Start==End) return;
		son[0]->bfs();
		son[1]->bfs();
	}
}*root;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	freopen("testdata.in","r",stdin);
	T=read();
	for(int i=1;i<=T;++i) arr[i]=read();
	(root=new(segtree))->build(1,T);
//	cout<<"*********************"<<endl;
//	root->bfs();
//	cout<<"*********************"<<endl;
	E=read();
	while(E--){
		opt=getchar();
		while(opt<'A'||opt>'Z') opt=getchar();
		if(opt=='Q'){
			x=read();y=read();
			printf("%d\n",root->query_now(x,y));
		}
		if(opt=='A'){
			x=read();y=read();
			printf("%d\n",root->query_history(x,y));
		}
		if(opt=='P'){
			x=read();y=read();z=read();
			root->change_add(x,y,z);
//			cout<<opt<<" "<<x<<" "<<y<<" "<<z<<endl;
//			cout<<"*********************"<<endl;
//			root->bfs();
//			cout<<"*********************"<<endl;
		}
		if(opt=='C'){
			x=read();y=read();z=read();
			root->change_change(x,y,z);
//			cout<<opt<<" "<<x<<" "<<y<<" "<<z<<endl;
//			cout<<"*********************"<<endl;
//			root->bfs();
//			cout<<"*********************"<<endl;
		}
	}
	return 0;
}
