#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN=11;
int m,n,k;
int arr[MAXN];
bool flag[MAXN];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i) scanf("%d",&arr[i]);
	for(int i=1;i<=m;++i)
		{scanf("%d",&k);flag[k]=true;}
	for(int i=1;i<=n;++i)
		if(flag[arr[i]]) printf("%d ",arr[i]);
	return 0;
}
