#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<set>
using namespace std;
const int MAXN=1505;
int n,m,L,R,l,r;
int arr[MAXN];
set<int> st;
struct segtree{
	int Start,End,val;
	segtree *son[2];
	segtree() {Start=End=val=0;son[0]=son[1]=NULL;}
	
}*root;
int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	freopen("miku.in","r",stdin);
	freopen("miku.out","w",stdout);
	n=read();m=read();L=read();R=read();
	for(int i=1;i<=n;++i){
		arr[i]=read();
		if(arr[i]<arr[i-1]) st.insert(i-1);
	}
	while(m--){
		l=read();r=read();
		int pos=*st.lower_bound(l);
		while(pos<r){
			swap(arr[pos],arr[pos+1]);
			if(arr[pos]<arr[pos-1]) st.insert(pos-1);
			if(arr[pos+2]<arr[pos+1]) st.insert(pos+1);
			st.erase(pos);
			pos=*st.lower_bound(l);
		}
	}
	for(int i=L;i<=R;++i) printf("%d ",arr[i]);
	return 0;
}
