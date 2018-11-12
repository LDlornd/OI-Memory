#include<cstdio>
#include<iostream>
using namespace std;
typedef long long int ll;
const int MAXN=1e6+5;
int n,m;
int Start[MAXN],End[MAXN];
ll have[MAXN],need[MAXN];
ll dif[MAXN],now=0;
bool judge(int key){
    if(now<key){
        ++now;
        for(;now<=key;++now){
            dif[Start[now]]-=need[now];
            dif[End[now]+1]+=need[now];
        }
    }
    else if(now>key){
        for(;now>key;--now){
            dif[Start[now]]+=need[now];
            dif[End[now]+1]-=need[now];
        }
    }
    now=key;
    ll temp=0;
    for(int i=1;i<=n;++i){
        temp+=dif[i];
        if(temp<0) return true;
    }
    return false;
}
template<typename T>
T read(){
    T x=0,f=1;char c=getchar();
    for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
    for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
    return x*f;
}
int main(){
    n=read<int>();m=read<int>();
    for(int i=1;i<=n;++i) {have[i]=read<ll>();dif[i]=have[i]-have[i-1];}
    for(int i=1;i<=m;++i) {need[i]=read<ll>();Start[i]=read<int>();End[i]=read<int>();}
    int Left=1,Right=n,ans=n+1;
    while(Left<=Right){
        int mid=(Left+Right)>>1;
        if(judge(mid)) {ans=mid;Right=mid-1;}
        else Left=mid+1;
    }
    if(ans==n+1) printf("0");
    else printf("-1\n%d",ans);
    return 0;
}
