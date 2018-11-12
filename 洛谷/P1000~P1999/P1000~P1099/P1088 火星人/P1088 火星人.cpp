#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=10001;
int finger[MAXN];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%d",&finger[i]);
	for(int i=0;i<m;++i)
		next_permutation(finger+1,finger+n+1);
	for(int i=1;i<=n;++i)
		printf("%d ",finger[i]);
	return 0;
}
