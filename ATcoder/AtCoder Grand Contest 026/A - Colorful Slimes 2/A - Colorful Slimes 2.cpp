#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN=101;
int n,tot=1,ans=0;
int color[MAXN],same[MAXN];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&color[i]);
	same[1]=1;
	for(int i=1;i<n;++i)
		if(color[i]==color[i+1]) ++same[tot];
		else same[++tot]=1;
	for(int i=1;i<=tot;++i) ans+=(same[i]>>1);
	printf("%d",ans);
	return 0;
}
