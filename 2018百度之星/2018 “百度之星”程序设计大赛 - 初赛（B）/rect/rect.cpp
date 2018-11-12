#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
typedef long long int ll;
const int MAXN=1e5+5;
int T,mx,my,n,x,y;
ll ans=0;
int read(){
    int x=0,f=1;char c=getchar();
    for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
    for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
    return x*f;
}
int main(){
    T=read();
    for(int casenum=1;casenum<=T;++casenum){
        mx=read();my=read();n=read();
        ans=0;
        while(n--){
            x=read();y=read();
            ans+=(ll)min(min(x,mx-x),min(y,my-y));
        }
        cout<<ans<<endl;
    }
    return 0;
}
