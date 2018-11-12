#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int n;
int num=0;
int a[13][13],solution[3][13];
void setdown(int x,int y)
{
	for(int i=num;i<3;++i)
	{
		solution[i][n-x-1]=y+1;
	}
}
void setin(int m,int x,int y)
{
	int k=x+y,h=x-y;
	for(int i=0;i<=n;++i)
	{
		if(a[x][i]==0) a[x][i]=m;
		if(a[i][y]==0) a[i][y]=m;
		if(k-i>=0&&k-i<n&&a[i][k-i]==0) a[i][k-i]=m;
		if(i-h>=0&&i-h<n&&a[i][i-h]==0) a[i][i-h]=m;
	}
}
void setout(int m,int x,int y)
{
	int k=x+y,h=x-y;
	for(int i=0;i<=n;++i)
	{
		if(a[x][i]==m) a[x][i]=0;
		if(a[i][y]==m) a[i][y]=0;
		if(k-i>=0&&k-i<n&&a[i][k-i]==m) a[i][k-i]=0;
		if(i-h>=0&&i-h<n&&a[i][i-h]==m) a[i][i-h]=0;
	}
}
void set(int m)
{
	if(m==0)
	{
		for(int i=0;i<n;++i)
		{
			if(a[0][i]==0)
			{
				if(num<3) setdown(m,i);
				++num;
			}
		}
		return;
	}
	for(int i=0;i<n;++i)
	{
		if(a[m][i]==0)
		{
			if(num<3) setdown(m,i);
			setin(m,m,i);
			set(m-1);
			setout(m,m,i);
		}
	}
}
int main()
{
	cin>>n;
	memset(a,0,sizeof(a));
	set(n-1);
	for(int i=0;i<3;++i)
	{
		for(int j=0;j<n;++j)
		{
			cout<<solution[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<num;
	return 0;
}
