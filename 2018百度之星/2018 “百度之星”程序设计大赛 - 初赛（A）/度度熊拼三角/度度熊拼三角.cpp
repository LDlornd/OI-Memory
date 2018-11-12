#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=1001;
int T,n;
int len[MAXN];
inline bool CMP(int a,int b){
    return a>b;
}
int read(){
    int x=0,f=1;char c=getchar();
    for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
    for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
    return x*f;
}
int main(){
    while(scanf("%d",&n)!=EOF){
        for(int i=1;i<=n;++i) len[i]=read();
        sort(len+1,len+n+1,CMP);
        bool flag=false;
        for(int i=1;i<=n-2;++i){
            if(len[i]>=len[i+1]+len[i+2]) continue;
            flag=true;
            printf("%d\n",len[i]+len[i+1]+len[i+2]);
            break;
        }
        if(flag==false) printf("-1\n");
    }
    return 0;
}
