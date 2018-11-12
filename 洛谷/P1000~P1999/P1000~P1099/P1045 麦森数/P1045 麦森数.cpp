#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
const int MAXN=502;
const double LOG=0.30102999566;
int ans[MAXN],dishu[MAXN],temp[MAXN];
inline void multi(int a[MAXN],int b[MAXN],int result[MAXN])
{
	memset(temp,0,sizeof(temp));
	for(int i=1;i<=500;++i)
	{
		for(int j=1;i+j<=501;++j)
		{
			temp[i+j-1]+=a[i]*b[j];
			temp[i+j]+=temp[i+j-1]/10;
			temp[i+j-1]%=10;
		}
	}
	for(int i=1;i<=500;++i) result[i]=temp[i];
}
inline void kuaisumi(int zhishu)
{
	while(zhishu!=0)
	{
		if(zhishu&1) {multi(ans,dishu,ans);}
		multi(dishu,dishu,dishu);
		zhishu>>=1;
	}
}
int main()
{
	memset(dishu,0,sizeof(dishu));
	memset(ans,0,sizeof(ans));
	ans[1]=1;dishu[1]=2;
	int p;
	scanf("%d",&p);
	printf("%d\n",(int) (p*LOG+1));
	kuaisumi(p);
	--ans[1];
	for(int i=500;i>=1;--i)
    {
        printf("%d",ans[i]);
        if(i%50==1&&i!=1) printf("\n");
    }
	return 0;
}
