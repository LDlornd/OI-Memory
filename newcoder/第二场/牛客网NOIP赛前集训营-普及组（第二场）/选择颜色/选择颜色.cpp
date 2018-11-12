#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
typedef long long ll;
const int mod=10007;
ll n,c;
ll A[2][2],B[2][2],temp[2][2];
void multi(ll (&a)[2][2],ll b[2][2]){
	memset(temp,0,sizeof(temp));
	for(int i=0;i<2;++i)
		for(int j=0;j<2;++j)
			for(int k=0;k<2;++k)
				temp[i][j]=(temp[i][j]+a[i][k]*b[k][j])%mod;
	for(int i=0;i<2;++i)
		for(int j=0;j<2;++j)
			a[i][j]=temp[i][j];
}
void quick_mi(ll index){
	while(index){
		if(index&1) multi(B,A);
		multi(A,A);
		index>>=1;
	}
}
int main(){
	scanf("%lld%lld",&n,&c);
	A[0][0]=c-2;A[0][1]=c-1;A[1][0]=1;A[1][1]=0;
	B[0][0]=B[1][1]=1;B[0][1]=B[1][0]=0;
	quick_mi(n);
	printf("%lld",c*B[1][1]%mod);
	return 0;
}
