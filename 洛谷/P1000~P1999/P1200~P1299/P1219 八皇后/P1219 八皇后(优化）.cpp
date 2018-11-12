#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int n;
int num=0;
bool a[50],b[50],c[50];
int solution[3][13];
void setdown(int x,int y)
{
	for(int i=num;i<3;++i)
	{
		solution[i][n-x-1]=y+1;
	}
}
void setin(int m,int x,int y)
{
	a[y]=1;
	b[x+y]=1;
	c[x-y+n]=1;
}
void setout(int m,int x,int y)
{
	a[y]=0;
	b[x+y]=0;
	c[x-y+n]=0;
}
void set(int m)
{
	if(m==0)
	{
		for(int i=0;i<n;++i)
		{
			if(a[i]==0&&b[m+i]==0&&c[m-i+n]==0)
			{
				if(num<3) setdown(m,i);
				++num;
			}
		}
		return;
	}
	for(int i=0;i<n;++i)
	{
		if(a[i]==0&&b[m+i]==0&&c[m-i+n]==0)
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
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	cin>>n;
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
