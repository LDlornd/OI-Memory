#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=8001;
int endx=0,endy=0,f=1;
int arr[MAXN],arx[MAXN],ary[MAXN],tot=0,place=0,placex=-1,placey=0;
bool dp[MAXN*MAXN+1];
inline bool CMP(int a,int b)
{
	return a<b;
}
bool judge(int k,int a[],int lena)
{
	memset(dp,0,sizeof(dp));
	int d=k-a[0],sum=0;
	if(lena==0&&d!=0)
	{
		if(d!=0) return false;
		else return true;
	}
	if(lena==1)
	{
		if(d==a[1]||d==-a[1]) return true;
		else return false;
	}
	for(int i=1;i<=lena;++i)
	{
		a[i]=(a[i]*lena-d);
		sum+=a[i];a[i]*=2;
	}
	sort(a+1,a+lena+1,CMP);
	dp[0]=true;
	for(int i=1;i<=sum;++i)
		for(int j=1;j<=lena&&a[j]<=i&&dp[i]==false;++j)
			dp[i]=(dp[i]||dp[i-a[j]]);
	if(dp[sum]) return true;
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
