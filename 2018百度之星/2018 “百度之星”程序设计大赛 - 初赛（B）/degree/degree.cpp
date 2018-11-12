#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int MAXN=2e5+5;
int T,n,m,k,u,v,maxindu,res;
int indu[MAXN];
inline void getready(){
    memset(indu,0,sizeof(indu));
    maxindu=0;
}
int read(){
    int x=0,f=1;char c=getchar();
    for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
    for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
    return x*f;
}
int main(){
    T=read();
    for(int casenum=1;casenum<=T;++casenum){
        getready();
        n=read();m=read();k=read();
        for(int i=1;i<=m;++i){
            u=read();v=read();
            ++indu[u];++indu[v];
            maxindu=max(maxindu,max(indu[u],indu[v]));
        }
        res=n-m-1;
        if(k>=m-maxindu) printf("%d\n",n-1);
        else printf("%d\n",maxindu+k+res);
    }
    return 0;
}
