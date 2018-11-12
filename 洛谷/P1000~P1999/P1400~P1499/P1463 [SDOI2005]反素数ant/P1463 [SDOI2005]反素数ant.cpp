#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long int ll;
const int MAXN=2001;
const ll INF=2000000000;
ll n;
int antinum=0,maxdivnum=0;
int prime[MAXN],tot=0;
ll anti_prime[MAXN];
bool flag[MAXN];
struct antiprime
{
	ll data;
	int divnum;
	antiprime(ll dd=0,int vv=0) {data=dd;divnum=vv;}
}NUM[MAXN];
inline void get_prime()
{
	memset(flag,0,sizeof(flag));
	flag[0]=flag[1]=true;
	for(int i=1;i<=MAXN;++i)
	{
		if(flag[i]==false) prime[++tot]=i;
		for(int j=1;j<=tot&&i*prime[j]<MAXN;++j)
		{
			flag[i*prime[j]]=true;
			if(i%prime[j]==0) break;
		}
	}
}
inline void get_anti_prime(ll nownum,int num,int limit,int rank)
{
	if(nownum>INF||num>=MAXN) return;
	if(anti_prime[num]==0) ++antinum;
	if(anti_prime[num]==0||anti_prime[num]>nownum) anti_prime[num]=nownum;
	ll temp=nownum;
	for(int i=1;i<=limit;++i)
	{
		temp*=prime[rank];
		if(temp>INF) break;
		get_anti_prime(temp,num*(i+1),i,rank+1);
	}
}
inline bool CMP(const antiprime &a,const antiprime &b)
{
	return a.data<b.data;
}
int main()
{
	scanf("%lld",&n);
	memset(anti_prime,0,sizeof(anti_prime));
	get_prime();
	get_anti_prime(1,1,50,1);
	for(int i=1;i<MAXN;++i)
		NUM[i]=antiprime((anti_prime[i]?anti_prime[i]:INF+1),i);
	sort(NUM,NUM+MAXN,CMP);
	maxdivnum=NUM[1].divnum;
	for(int i=2;i<=MAXN;++i)
		if(maxdivnum>NUM[i].divnum) NUM[i].data=INF+1;
		else maxdivnum=NUM[i].divnum;
	sort(NUM,NUM+MAXN,CMP);
	for(int i=2;i<=MAXN;++i)
		if(NUM[i].data<=n&&NUM[i+1].data>n)
		{
			printf("%lld",NUM[i].data);
			break;
		}
	return 0;
}
