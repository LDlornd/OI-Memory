#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long int ll;
const int MAXN=1005;
ll limit,len,n;
ll weight[MAXN],sum[MAXN],v[MAXN];
ll lg[MAXN];
double t[MAXN],maxt[15][MAXN];
double dp[MAXN];
void init(){
    lg[1]=0;
    for(int i=2;i<=n;++i) lg[i]=lg[i>>1]+1;
    for(int i=1;i<=n;++i) maxt[0][i]=t[i];
    for(int i=1;i<=lg[n];++i)
        for(int j=1;(j+(1<<i)-1)<=n;++j)
            maxt[i][j]=max(maxt[i-1][j],maxt[i-1][j+(1<<(i-1))]);
}
double query(int Start,int End){
    if(Start==End) return t[Start];
    int tmp=lg[End-Start];
    return max(maxt[tmp][Start],maxt[tmp][End-(1<<tmp)+1]);
}
ll read(){
    ll x=0,f=1;char c=getchar();
    for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
    for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
    return x*f;
}
int main(){
    limit=read();len=read();n=read();
    for(int i=1;i<=n;++i){
        weight[i]=read();sum[i]=sum[i-1]+weight[i];
        v[i]=read();t[i]=(double)len/v[i];
    }
    init();
    for(int i=1;i<=n;++i){
        dp[i]=dp[i-1]+t[i];
        for(int j=i-2;j>=0;--j){
            if(sum[i]-sum[j]>limit) break;
            dp[i]=min(dp[i],dp[j]+query(j+1,i));
        }
    }
    printf("%.1lf",dp[n]*60);
    return 0;
}
