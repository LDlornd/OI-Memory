#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
int n,ans=2;
int h[MAXN];
int read(){
    int x=0,f=1;char c=getchar();
    for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
    for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
    return x*f;
}
int main(){
    n=read();
    for(int i=1;i<=n;++i) h[i]=read();
    n=unique(h+1,h+n+1)-h-1;
    for(int i=2;i<n;++i)
        if((h[i]>h[i-1]&&h[i]>h[i+1])||(h[i]<h[i-1]&&h[i]<h[i+1])) ++ans;
    printf("%d",ans);
    return 0;
}
