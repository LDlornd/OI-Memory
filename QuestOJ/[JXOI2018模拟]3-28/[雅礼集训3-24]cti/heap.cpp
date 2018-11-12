#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100;
int n,q,opt,x;
priority_queue<int> Q;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	n=read();
	while(n--){
		opt=read();
		if(opt==1) {x=read();Q.push(x)}
		if(opt==2) cout<<Q.top()<<endl;
		if(opt==3) Q.
	}
	return 0;
}
