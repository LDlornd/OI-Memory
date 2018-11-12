#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
typedef long long int ll;
const int mod=1e9+7;
const int MAXN=105;
ll k;
int n;
ll A[MAXN][MAXN],B[MAXN][MAXN],temp[MAXN][MAXN];
void times(ll (&a)[MAXN][MAXN],ll b[MAXN][MAXN]){
	memset(temp,0,sizeof(temp));
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			for(int k=1;k<=n;++k)
				temp[i][j]=(temp[i][j]+a[i][k]*b[k][j])%mod;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			a[i][j]=temp[i][j];
}
void quick_mi(ll index){
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			B[i][j]=(i==j);
	while(index){
		if(index&1) times(B,A);
		times(A,A);
		index>>=1;
	}
}
int main(){
	scanf("%d%lld",&n,&k);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			scanf("%lld",&A[i][j]);
	quick_mi(k);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j)
			printf("%lld ",B[i][j]);
		printf("\n");
	}
	return 0;
}
