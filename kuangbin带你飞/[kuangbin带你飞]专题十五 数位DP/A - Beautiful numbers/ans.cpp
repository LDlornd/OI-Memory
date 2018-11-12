#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MOD  = 1000000007;
const int maxn = 200010;
int  num[30],len;
LL  dp[30][2550][50];
int a[50],has[2520];
int gcd(int a,int b)
{
    if(!b) return a;
    else return gcd(b,a%b);
}
int llcm(int a,int b){
    return a/gcd(a,b)*b;
}
LL dfs(int pos,int mod,int lcm,int limit){
    if(pos<0) return mod%lcm==0;
    if(!limit&&dp[pos][mod][has[lcm]]!=-1) return dp[pos][mod][has[lcm]];
    int endi =limit?num[pos]:9;
    LL res = 0;
    int tlcm ;
    for(int i=0; i<=endi; i++)
    {
        if(!i) res += dfs(pos-1,(mod*10+i)%2520,lcm,limit&&(i==endi));
        else   res += dfs(pos-1,(mod*10+i)%2520,llcm(lcm,i),limit&&(i==endi));
    }

    if(!limit) dp[pos][mod][has[lcm]] = res;
    return res;
}

LL solve(LL n)
{
    len = 0;
    while(n)
    {
        num[len++] = n%10;
        n /= 10;
    }
    return dfs(len-1,0,1,1);
}

void init()
{
    memset(has,0,sizeof(has));
    int tem ;
    for(int i=0;i<(1<<9);i++)
    {
        tem = 1;
        for(int j=1;j<=9;j++)
        {
            if(i&(1<<j))
                tem = llcm(tem,j+1);
        }
        has[tem]=1;
    }
    int l = 0;
    for(int i=0;i<=2520;i++)
        if(has[i]) a[l]=i,has[i]=l++;
}
int main()
{
    init();
    memset(dp,-1,sizeof(dp));
    int _;
    scanf("%d",&_);
    while(_--)
    {
        LL n,m;
        scanf("%I64d%I64d",&m,&n);
        printf("%I64d\n",solve(n)-solve(m-1));
    }
    return 0;
}
