#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
typedef long long int ll;
const int MAXN=1e8+5;
const int mod=1e9+7;
ll ans=1;
int n;
int f[MAXN];
bool flag[MAXN];
int main(){
	freopen("test.in","r",stdin);
	//freopen("tle.out","w",stdout);
    scanf("%d",&n);
    f[2]=1;
    for(int i=3;i<=n;++i){
        for(int j=2;j<i;++j)
            if(i%j!=0){
                f[i]=f[j]+1;
                if(f[i]>=mod) f[i]-=mod;
                break;
            }
        ans=ans*f[i]%mod;
        if(i>14){
        	int temp=1;
        	for(int j=i-11;j<=i;++j){
        		if(flag[j]) break;
				temp*=f[j];
        		if(temp==6*6*6*6*8*8){
        			cout<<i<<" "<<f[i]<<endl;
        			flag[i]=true;
				}
			}
		}
		//if(i>=400&&i<=450) cout<<i<<" "<<f[i]<<endl;
		//if(i%12==6) cout<<ans<<" "<<i<<endl;
        //if(i>=n-6) cout<<ans<<" "<<f[i]<<endl;
        //if(i==n) cout<<ans<<" "<<f[i]<<endl;
        //if(i==n+1) cout<<ans<<" "<<f[i]<<endl;
    }
    printf("%lld",ans);
    return 0;
}
