#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
bool flag[10000000];
int main()
{
	memset(flag,0,sizeof(flag));
	flag[0]=flag[1]=1;
	int n,m,k,num;
	cin>>n>>m;
	k=sqrt(n)+1;
	for(int i=2;i<=k;++i)
	{
		if(!flag[i])
			for(int j=i*i;j<=n;j+=i)
			{
				flag[j]=1;
			}
	}
	for(int i=0;i<m;++i)
	{
		cin>>num;
		if(!flag[num]) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
