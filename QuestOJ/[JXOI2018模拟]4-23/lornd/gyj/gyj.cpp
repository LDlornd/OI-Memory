#include<cstdio>
#include<iostream>
using namespace std;
typedef long long int ll;
const int MAXN=100001;
int n,m,K;
ll place[MAXN],v[MAXN];
struct xy{
	ll A,B,T;
	xy(ll aa=0,ll bb=0,ll tt=0) {A=aa;B=bb;T=tt;}
}arr[25000000];
template<typename T>
inline T read(){
	T x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	freopen("gyj.in","r",stdin);
	freopen("gyj.out","w",stdout);
	n=read<int>();
	for(int i=1;i<=n;++i){
		place[i]=read<ll>();v[i]=read<ll>();
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
