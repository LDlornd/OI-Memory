#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=50001;
int T,n,V,opt[MAXN];
bool flag;
struct backpack{
	int cost,add,key;
	backpack() {cost=add=key=0;}
}arr[MAXN];
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=x*10+c-'0';
	return x*f;
}
int main(){
	T=read();
	while(T--){
		flag=false;
		n=read();V=read();
		for(int i=1;i<=n;++i){
			arr[i].cost=read();arr[i].add=read();
			arr[i].key=arr[i].add-arr[i].cost;
		}
		if(n>10){
			printf("Yes\n");
			continue;
		}
		for(int i=1;i<=n;++i) opt[i]=i;
		do{
			int temp=V;
			for(int i=1;i<=n;++i){
				if(temp<arr[opt[i]].cost) break;
				if(i==n) flag=true;
				temp+=arr[opt[i]].key;
			}
		}while(next_permutation(opt+1,opt+n+1)&&flag==false);
		if(flag) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
