#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=101;
const int INF=2e9+1;
int n,p,have[MAXN];
int temp,ans=INF;
int dist[MAXN][MAXN];
inline bool CMP(int a,int b)
{
	return a<b;
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			cin>>dist[i][j];
	cin>>p;
	have[0]=1;have[p+1]=n;
	for(int i=1;i<=p;++i) cin>>have[i];
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
	sort(have+1,have+p+1,CMP);
	do{
		temp=0;
		for(int i=0;i<=p;++i) temp+=dist[have[i]][have[i+1]];
		ans=min(ans,temp);
	}while(next_permutation(have+1,have+p+1));
	cout<<ans;
	return 0;
}
