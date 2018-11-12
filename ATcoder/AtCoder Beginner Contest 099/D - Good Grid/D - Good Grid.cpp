#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN1=501;
const int MAXN2=31;
int n,c,key,res=2147483647;
int D[MAXN2][MAXN2];
int num[3][MAXN2];
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	n=read();c=read();
	for(int i=1;i<=c;++i)
		for(int j=1;j<=c;++j)
			D[i][j]=read();
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j){
			key=read();
			++num[(i+j)%3][key];
		}
	for(int i=1;i<=c;++i){
		for(int j=1;j<=c;++j){
			if(i==j) continue;
			for(int k=1;k<=c;++k){
				if(i==k||j==k) continue;
				int ans=0;
				for(int w=1;w<=c;++w){
					if(w==i) continue;
					ans+=(D[w][i]*num[0][w]);
				}
				for(int w=1;w<=c;++w){
					if(w==j) continue;
					ans+=(D[w][j]*num[1][w]);
				}
				for(int w=1;w<=c;++w){
					if(w==k) continue;
					ans+=(D[w][k]*num[2][w]);
				}
				res=min(res,ans);
			}
		}
	}
	printf("%d",res);
	return 0;
}
