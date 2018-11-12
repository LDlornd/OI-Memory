#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN=200001;
int n;
long long int ans=0,temp=2147483647;
long long int A[MAXN],B[MAXN];
bool flag=false;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d%d",&A[i],&B[i]);
		if(A[i]!=B[i]) flag=true;
		if(A[i]>B[i]) temp=min(temp,B[i]);
		ans+=B[i];
	}
	ans-=temp;
	if(flag) printf("%lld",ans);
	else printf("0");
	return 0;
}
