#include<cstdio>
#include<iostream>
using namespace std;
typedef long long int ll;
const int MAXN=3e5+5;
int T,n,ans,maxnum;
int arr[MAXN];
bool judge(int key){
    ll temp=0;
    for(int i=1;i<=n;++i){
        if(arr[i]<key) temp-=(key-arr[i]);
        else temp+=(arr[i]-key)/2;
    }
    return temp>=0;
}
inline void getready(){
    maxnum=ans=0;
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
        n=read();
        for(int i=1;i<=n;++i) maxnum=max(maxnum,(arr[i]=read()));
        int l=0,r=maxnum;
        while(l<=r){
            int mid=(l+r)>>1;
            if(judge(mid)){
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        printf("%d\n",ans);
    }
    return 0;
}
