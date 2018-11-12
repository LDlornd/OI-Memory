#include <bits/stdc++.h>
using namespace std;
typedef int _int;
#define int long long
const int N=200010;
int head,tail=1;
int n,f[N],pre[N],sum[N],q[N];
_int main(){
    cin>>n;int x;
    for (int i=1;i<=n;++i) cin>>x,sum[i]=sum[i-1]+x;
    for (int i=1;i<=n;++i) {
        while (head+1<tail&&sum[i]>=sum[q[head+1]]+pre[q[head+1]]) ++head;
        f[i]=f[q[head]]+1;
        pre[i]=sum[i]-sum[q[head]];
        while (head<tail&&sum[q[tail-1]]+pre[q[tail-1]]>sum[i]+pre[i]) --tail;
        q[tail++]=i;
        for(int k=head+1;k<tail;++k) cout<<q[k]<<" ";cout<<endl;
    }
    for(int i=1;i<=n;++i) cout<<f[i]<<" ";cout<<endl;
	for(int i=1;i<=n;++i) cout<<pre[i]<<" ";cout<<endl;
    cout<<n-f[n];
    return 0;
}
