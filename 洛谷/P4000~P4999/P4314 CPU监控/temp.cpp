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
	bool change;
	segtree *son[2];
	segtree(){
		Start=End=0;
		now_val=history_val=-INF;
		addlazy=0;changelazy=0;
		change=false;
		son[0]=son[1]=NULL;
	}
	inline void update(){
		now_val=max(son[0]->now_val,son[1]->now_val);
		history_val=max(history_val,now_val);
	}
	inline void caculate(int a,int c,bool C){
//		if(C) now_val=c+a;
//		else now_val+=a;
//		if(C) addlazy=0;
//		else addlazy+=a;
		if(C){
			change=C;changelazy=c;
		}
		addlazy=C?0:addlazy+a;
		now_val=C?(c+addlazy):now_val+addlazy;
		history_val=max(history_val,now_val);
	}
	inline void push_down(){
		son[0]->caculate(addlazy,changelazy,change);
		son[1]->caculate(addlazy,changelazy,change);
		son[0]->history_val=history_val;
		son[1]->history_val=history_val;
		addlazy=0;changelazy=now_val;change=false;
	}
	inline void build(int nstart,int nend){
		Start=nstart;End=nend;
		if(Start==End){
			changelazy=history_val=now_val=arr[Start];
			//cout<<Start<<" "<<End<<" "<<history_val<<" "<<now_val<<endl;
			return;
		}
		int mid=(Start+End)>>1;
		(son[0]=new(segtree))->build(Start,mid);
		(son[1]=new(segtree))->build(mid+1,End);
		update();
		//cout<<Start<<" "<<End<<" "<<history_val<<" "<<now_val<<endl;
	}
	inline void change_add(int nstart,int nend,int key){
		if(Start==nstart&&End==nend){
			caculate(key,0,false);
			return;
		}
		push_down();
		int mid=(Start+End)>>1;
		if(nstart>mid) son[1]->change_add(nstart,nend,key);
		else if(nend<=mid) son[0]->change_add(nstart,nend,key);
		else{
			son[0]->change_add(nstart,mid,key);
			son[1]->change_add(mid+1,nend,key);
		}
		update();
	}
	inline void change_change(int nstart,int nend,int key){
		if(Start==nstart&&End==nend){
			caculate(0,key,true);
			//cout<<Start<<" "<<End<<" "<<change<<"fuck!!!"<<endl;
			return;
		}
		int mid=(Start+End)>>1;
		if(nstart>mid) son[1]->change_change(nstart,nend,key);
		else if(nend<=mid) son[0]->change_change(nstart,nend,key);
		else{
			son[0]->change_change(nstart,mid,key);
			son[1]->change_change(mid+1,nend,key);
		}
		update();
	}
	inline int query_now(int nstart,int nend){
		if(Start==nstart&&End==nend) return now_val;
		push_down();
		int mid=(Start+End)>>1;
		if(nstart>mid) return son[1]->query_now(nstart,nend);
		else if(nend<=mid) return son[0]->query_now(nstart,nend);
		else return max(son[0]->query_now(nstart,mid),son[1]->query_now(mid+1,nend));
	}
	inline int query_history(int nstart,int nend){
		if(Start==nstart&&End==nend) return history_val;
		push_down();
		int mid=(Start+End)>>1;
		if(nstart>mid) return son[1]->query_history(nstart,nend);
		else if(nend<=mid) return son[0]->query_history(nstart,nend);
		else return max(son[0]->query_history(nstart,mid),son[1]->query_history(mid+1,nend));
	}
	inline void bfs(){
		cout<<Start<<" "<<End<<" "<<now_val<<" "<<history_val<<" "<<addlazy<<" "<<changelazy<<" "<<change<<endl;
		//cout<<Start<<" "<<End<<" "<<now_val<<" "<<history_val<<endl;
		if(Start==End) return;
		//push_down();
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
	freopen("wa.out","w",stdout);
	T=read();
	for(int i=1;i<=T;++i) arr[i]=read();
	//cout<<arr[1]<<" "<<arr[2]<<endl;
	(root=new(segtree))->build(1,T);
	//root->bfs();
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
		}
		if(opt=='C'){
			x=read();y=read();z=read();
			root->change_change(x,y,z);
		}
//		cout<<opt<<" "<<x<<" "<<y<<endl;
//		cout<<"*********************"<<endl;
//		root->bfs();
//		cout<<"*********************"<<endl;
	}
	return 0;
}
