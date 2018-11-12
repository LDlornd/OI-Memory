#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int MAXN=20010;
int endx=0,endy=0,f=1;
int arr[MAXN],arx[MAXN],ary[MAXN],tot=0,place=0,placex=-1,placey=0;
bool dp[MAXN];
bool judge(int k,int a[],int lena)
{
	k=k-a[0]+8000;
	memset(dp,0,sizeof(dp));
	dp[8000]=true;
	for(int i=1;i<=lena;++i)
		for(int j=0;j<20010;++j)
		{
			if(dp[j]&&j>=a[i]) dp[j-a[i]]=true;
			if(dp[j]&&j+a[i]<20010) dp[j+a[i]]=true;
		}
	if(dp[k]) return true;
	else return false;
}
void read()
{
	char c=getchar();
	while(c=='F'||c=='T')
	{
		if(c=='F') ++tot;
		else if(c=='T') {arr[++place]=tot;tot=0;}
		c=getchar();
	}
	if(tot!=0) arr[++place]=tot;
	f=1;
	while(c<'0'||c>'9') {if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') {endx=endx*10+c-'0';c=getchar();}
	endx*=f;f=1;
	while(c<'0'||c>'9') {if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') {endy=endy*10+c-'0';c=getchar();}
	endy*=f;
}
int main()
{
	read();arx[0]=ary[0]=0;
	for(int i=1;i<=place;++i)
	{
		if(i&1) arx[++placex]=arr[i];
		else ary[++placey]=arr[i];
	}
	if(judge(endx,arx,placex)==false) printf("No");
	else if(judge(endy,ary,placey)==false) printf("No");
	else printf("Yes");
	return 0;
}
