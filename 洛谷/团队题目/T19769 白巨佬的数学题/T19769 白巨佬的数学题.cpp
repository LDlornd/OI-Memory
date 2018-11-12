#include<cstdio>
#include<iostream>
using namespace std;
long long int q,n,k,flag,ans;
inline long long int read()
{
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') {x=x*10+c-'0';c=getchar();}
	return x*f;
}
int main()
{
	q=read();
	while(q--)
	{
		n=read();
		if(n<5) printf("0\n");
		else
		{
			k=n-5;flag=k%3;k/=3;
			ans=3*k*(k+1)/2+1;
			for(int i=0;i<flag;++i)
				ans+=(k+i);
			printf("%lld\n",ans);
		}
	}
	return 0;
}
