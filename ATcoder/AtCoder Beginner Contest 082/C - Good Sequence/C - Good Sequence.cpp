#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100001;
struct num
{
	int yuan,appear;
	num() {yuan=appear=0;}
}con[MAXN];
int tot=1,ans=0,arr[MAXN];
inline bool CMP(int a,int b)
{
	return a<b;
}
inline int read()
{
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') {x=x*10+c-'0';c=getchar();}
	return x*f;
}
int main()
{
	int n=read();
	for(int i=1;i<=n;++i) arr[i]=read();
	sort(arr+1,arr+n+1,CMP);
	con[1].yuan=arr[1];con[1].appear=1;
	for(int i=2;i<=n;++i)
		if(arr[i]==arr[i-1]) ++con[tot].appear;
		else {con[++tot].yuan=arr[i];con[tot].appear=1;}
	for(int i=1;i<=tot;++i)
		if(con[i].appear>con[i].yuan) ans+=(con[i].appear-con[i].yuan);
		else if(con[i].appear<con[i].yuan) ans+=con[i].appear;
	printf("%d",ans);
	return 0;
}
