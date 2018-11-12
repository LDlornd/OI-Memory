#include <iostream>
#include <cstdio>
#include <map>
#define LL long long
using namespace std;
LL l, r, l1, r1;
int n,num[20];
map<LL, LL> f[20];
LL dp(int x, int lim, LL sum){
    if(x==0)return sum>=l1 && sum<=r1;
    if(!lim && f[x].find(sum)!=f[x].end()) return f[x][sum];
    LL temp=0;
    for(int i=0; i<=(lim?num[x]:9); i++){
        if(sum==-1){
            if(i==0) temp+=dp(x-1, lim&&i==num[x], -1);
            else temp+=dp(x-1, lim&&i==num[x], i);
        }
        else temp+=dp(x-1, lim&&i==num[x], sum*i);
    }
    if(!lim) f[x][sum]=temp;
    return temp;
} 
LL solve(LL x){
    n=0;
    if(x==-1) return 0;
    while(x) num[++n]=x%10, x/=10;
    return dp(n, 1, -1)+(l==0 && l1==0);
}
int main(){
	freopen("testdata.in","r",stdin);
	freopen("ac.out","w",stdout);
    scanf("%lld%lld%lld%lld", &l, &r, &l1, &r1);
    printf("%lld\n", solve(r)-solve(l-1));
    return 0;
}
