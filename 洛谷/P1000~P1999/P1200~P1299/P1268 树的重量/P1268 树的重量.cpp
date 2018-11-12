#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN=35;
int n,ans;
int dist[MAXN][MAXN];
int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	while((n=read())){
		if(n==0) break;
		for(int i=1;i<=n;++i)
			for(int j=i+1;j<=n;++j)
				dist[i][j]=dist[j][i]=read();
		ans=dist[1][2];
		for(int i=3;i<=n;++i){
			int temp=105;
			for(int j=1;j<=i;++j)
				for(int k=j+1;k<i;++k)
					temp=min(temp,(dist[j][i]+dist[i][k]-dist[k][j])>>1);
			ans+=temp;
		}
		printf("%d\n",ans);
	}
	return 0;
}
