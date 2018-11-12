#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long int ll;
const int MAXN=100001;
struct node{
	int Left,Right,Block,ID;
	node() {Left=Right=Block=ID=0;}
}arr[MAXN];
int n,m,stand,Start=1,End=0;
ll temp,num[MAXN];
ll A[MAXN],ans[MAXN];
inline bool CMP(const node &a,const node &b){
	if(a.Block==b.Block) return a.Right<b.Right;
	return a.Block<b.Block;
}
inline void add(int key){
	num[key]+=key;
}
inline void del(int key){
	num[key]-=key;
}
int main(){
	ios::sync_with_stdio(false);
	memset(num,0,sizeof(num));
	cin>>n>>m;stand=sqrt(n);
	for(int i=1;i<=n;++i) cin>>A[i];
	for(int i=1;i<=m;++i){
		cin>>arr[i].Left>>arr[i].Right;
		arr[i].Block=(arr[i].Left)/stand;
		arr[i].ID=i;
	}
	sort(arr+1,arr+m+1,CMP);
	for(int i=1;i<=m;++i){
		while(Start<arr[i].Left) del(A[Start++]);
		while(Start>arr[i].Left) add(A[--Start]);
		while(End<arr[i].Right) add(A[++End]);
		while(End>arr[i].Right) del(A[End--]);
		temp=0;
		for(int j=1;j<=n;++j)
			temp=max(temp,num[j]);
		ans[arr[i].ID]=temp;
	}
	for(int i=1;i<=m;++i)
		cout<<ans[i]<<endl;
	return 0;
}
