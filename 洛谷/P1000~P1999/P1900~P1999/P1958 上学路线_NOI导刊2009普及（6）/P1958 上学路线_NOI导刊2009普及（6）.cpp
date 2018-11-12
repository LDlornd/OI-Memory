#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int s[20][20];
bool bu[20][20];
int main()
{
	memset(s,0,sizeof(s));
	memset(bu,0,sizeof(bu));
	int a,b,n,x,y;
	cin>>a>>b>>n;
	for(int i=0;i<n;++i)
	{
		cin>>x>>y;
		bu[x][y]=1;
	}
	s[1][1]=1;
	for(int i=1;i<=a;++i)
		for(int j=1;j<=b;++j)
		{
			if(i==1&&j==1) continue;
			if(bu[i][j]) continue;
			s[i][j]=s[i-1][j]+s[i][j-1];
		}
	cout<<s[a][b];
	return 0;
}
