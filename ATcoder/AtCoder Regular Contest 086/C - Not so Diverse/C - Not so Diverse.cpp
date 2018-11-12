#include<cstdio>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
const int MAXN=200001;
int n,m,k,tot=0,ans=0;
map <int,int> MAP;
struct num
{
	int data,appear;
	num() {data=0;appear=0;}
}NUM[MAXN];
inline bool CMP(const num &a,const num &b)
{
	return a.appear>b.appear;
}
inline int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {x=x*10+c-'0';c=getchar();}
	return x*f;
}
int main()
{
	n=read();m=read();
	for(int i=1;i<=n;++i)
	{
		k=read();
		if(MAP.count(k)==false) MAP.insert(pair<int,int>(k,1));
		else ++MAP[k];
	}
	for(map<int,int>::iterator it=MAP.begin();it!=MAP.end();++it)
	{
		NUM[++tot].appear=it->second;
		NUM[tot].data=it->first;
	}
	sort(NUM+1,NUM+tot+1,CMP);
	for(int i=1;i<=m;++i)
		ans+=NUM[i].appear;
	printf("%d",n-ans);
	return 0;
}
