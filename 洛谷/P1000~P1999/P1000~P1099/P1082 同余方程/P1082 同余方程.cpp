#include<cstdio>
#include<iostream>
using namespace std;
inline int exgcd(int a,int b,int &x,int &y)
{
	if(b==0)
	{
		x=1;y=0;
		return a;
	}
	int temp=exgcd(b,a%b,x,y);
	int s=x;
	x=y;y=s-a/b*y;
	return temp;
}
inline int read()
{
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') {x=x*10+c-'0';c=getchar();}
	return x;
}
int main()
{
	int ansx,ansy;
	int a=read(),b=read();
	exgcd(a,b,ansx,ansy);
	while(ansx<0) ansx+=b;
	while(ansx-b>0) ansx-=b;
	printf("%d",ansx);
	return 0; 
}
