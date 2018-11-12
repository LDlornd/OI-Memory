#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100001;
int T,n,V,Place;
bool flag;
struct backpack{
	int cost,add,key;
	backpack() {cost=add=key=0;}
}arr[MAXN];
struct ANS{
	int tempans,tempplace;
	ANS(int tt,int ttt) {tempans=tt;tempplace=ttt;}
};
inline ANS MAX(ANS,ANS);
struct segtree{
	int minnum,maxnum,val,place,Start,End;
	segtree *leftson,*rightson;
	segtree(){
		minnum=maxnum=val=place=Start=End=0;
		leftson=rightson=NULL;
	}
	inline void update(){
		minnum=min(leftson->minnum,rightson->minnum);
		maxnum=max(leftson->maxnum,rightson->maxnum);
		val=max(leftson->val,rightson->val);
		place=(val==leftson->val)?leftson->place:rightson->place;
	}
	inline void build(int nstart,int nend){
		Start=nstart;End=nend;
		if(Start==End){minnum=maxnum=arr[Start].cost;val=arr[Start].key;place=Start;return;}
		int mid=(Start+End)>>1;
		(leftson=new(segtree))->build(Start,mid);
		(rightson=new(segtree))->build(mid+1,End);
		update();
	}
	inline void del(int key){
		if(Start==key&&End==key) {val=-2147483647;return;}
		int mid=(Start+End)>>1;
		if(key<=mid) leftson->del(key);
		else rightson->del(key);
		update();
	}
	inline ANS query(int key){
		if(maxnum<key) return ANS(val,place);
		if(minnum>key) return ANS(0,0);
		return MAX(leftson->query(key),rightson->query(key));
	}
	inline void dfs(){
		cout<<Start<<" "<<End<<" "<<minnum<<" "<<maxnum<<" "<<val<<" "<<place<<endl;
		if(Start==End) return;
		leftson->dfs();
		rightson->dfs();
	}
}*root;
inline ANS MAX(ANS a,ANS b) {return (a.tempans>b.tempans)?a:b;}
inline bool CMP(const backpack &a,const backpack &b){
	if(a.key==b.key) return a.cost<b.cost;
	return a.key>b.key;
}
inline bool CMP2(const backpack &a,const backpack &b){
	return a.cost>b.cost;
}
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=x*10+c-'0';
	return x*f;
}
int main(){
	T=read();
	while(T--){
		flag=true;Place=0;
		n=read();V=read();
		for(int i=1;i<=n;++i){
			arr[i].cost=read();arr[i].add=read();
			arr[i].key=arr[i].add-arr[i].cost;
		}
		sort(arr+1,arr+n+1,CMP);
		for(int i=1;i<=n;++i)
			if(arr[i].key<0){
				Place=i-1;
				break;
			}
		if(Place>=1){
			(root=new(segtree))->build(1,Place);
		//root->dfs();
		for(int i=1;i<=Place;++i){
			ANS temp=root->query(V);
			if(temp.tempplace==0){
				flag=false;break;
			}
			else root->del(temp.tempplace);
			V+=temp.tempans;
			//cout<<V<<endl;
			if(V<0){
				flag=false;
				break;
			}
		}
		if(flag==false) printf("No\n");
		else{
			sort(arr+Place+1,arr+n+1,CMP2);
			for(int i=Place+1;i<=n;++i)
				if(V>arr[i].cost) V+=arr[i].key;
				else {flag=false;break;}
			if(flag) printf("Yes\n");
			else printf("No\n");
			}
		}
		else{
			sort(arr+Place+1,arr+n+1,CMP2);
			for(int i=Place+1;i<=n;++i)
				if(V>arr[i].cost) V+=arr[i].key;
				else {flag=false;break;}
			if(flag) printf("Yes\n");
			else printf("No\n");
		}
	}
	return 0;
}
