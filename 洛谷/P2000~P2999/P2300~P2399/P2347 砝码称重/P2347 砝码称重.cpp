#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN=1005;
int weight[7]={0,1,2,3,5,10,20};
int arr[7],ans=0;
bool flag[MAXN]; 
int main(){
	for(int i=1;i<=6;++i) scanf("%d",&arr[i]);
	flag[0]=true;
	for(int i=1;i<=6;++i)
		for(int j=1;j<=arr[i];++j)
			for(int k=MAXN-1;k>=0;--k)
				if(flag[k]&&k+weight[i]<MAXN) flag[k+weight[i]]=true;
	for(int i=1;i<MAXN;++i) if(flag[i]) ++ans;
	printf("Total=%d",ans);
	return 0;
}
