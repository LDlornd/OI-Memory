#include<cstdio>
#include<iostream>
using namespace std;
typedef long long int ll;
const int mod=1e9+7;
const int MAXN=1e4;
ll C[MAXN][MAXN],ans=0;
int a,b,c,d;
ll get_C(int x,int y){
	if(x<y||x<0||y<0) return 0;
	if(C[x][y]) return C[x][y];
	else return C[x][y]=(get_C(x-1,y)+get_C(x-1,y-1))%mod;
}
ll judge(int x,int y){
	if(x==0) return 1;
	if(y==0) return 0;
	return get_C(x+y-1,y-1);
}
int main(){
	C[0][0]=1;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	for(int i=0;i<=a-c;++i){
		for(int j=0;j<=b-d;++j){
			ans=(ans+(ll)get_C(c+d,c)*get_C(i+j,i)%mod*judge(a-c-i,d)%mod*judge(b-d-j,c)%mod)%mod;
		}
	}
	printf("%lld",ans);
	return 0;
}
