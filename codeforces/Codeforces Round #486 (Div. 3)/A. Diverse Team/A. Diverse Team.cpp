#include<cstdio>
#include<iostream>
#include<map>
using namespace std;
const int MAXN=101;
int n,k,key,tot=0;
int place[MAXN];
map<int,bool> mp;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	n=read();k=read();
	for(int i=1;i<=n;++i){
		key=read();
		if(mp.count(key)==false){
			place[++tot]=i;
			mp.insert(make_pair(key,true));
		}
		if(tot==k) break;
	}
	if(tot<k) printf("NO");
	else{
		printf("YES\n");
		for(int i=1;i<=tot;++i)
			printf("%d ",place[i]);
	}
	return 0;
}
