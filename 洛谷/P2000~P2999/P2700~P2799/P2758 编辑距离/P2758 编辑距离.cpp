#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int MAXN=2005;
char A[MAXN],B[MAXN];
int lena,lenb;
int dp[MAXN][MAXN];
int main(){
	scanf("%s%s",A+1,B+1);
	lena=strlen(A+1);lenb=strlen(B+1);
	for(int i=0;i<=max(lena,lenb);++i) dp[i][0]=dp[0][i]=i;
	for(int i=1;i<=lena;++i)
		for(int j=1;j<=lenb;++j)
			dp[i][j]=min(dp[i-1][j-1]+(A[i]!=B[j]),min(dp[i-1][j],dp[i][j-1])+1);
	printf("%d",dp[lena][lenb]);
	return 0;
}
