#include<cstdio>
#include<iostream>
using namespace std;
typedef long long int ll;
const int MAXN=1e5+5;
char opt[10];
int T,n,k;
ll s,p;
ll arr[MAXN];
bool flag=false;
void get_min(int &l,int &r){
	for(int i=1;i<=k;++i){
		int nl=l,nr=r;
		if(flag==false)
			while(nl<nr&&arr[nl]==arr[nr]) {++nl;--nr;}
		if(nl==nr) flag=true;
		if(arr[nl]>=arr[nr]) ++l;
		else --r;
	}
}
void get_max(int &l,int &r){
	for(int i=1;i<=k;++i){
		int nl=l,nr=r;
		if(flag==false)
			while(nl<nr&&arr[nl]==arr[nr]) {++nl;--nr;}
		if(nl==nr) flag=true;
		if(arr[nl]<=arr[nr]) ++l;
		else --r;
	}
}
template<typename T>
T read(){
	T x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	T=read<int>();
	while(T--){
		scanf("%s",opt+1);
		if(opt[3]=='w'){
			n=read<int>();k=read<int>();
			for(int i=1;i<=n;++i) arr[i]=read<ll>();
		}
		else{
			n=read<int>();k=read<int>();s=read<ll>();p=read<ll>();
			arr[1]=s;
			for(int i=2;i<=n;++i) arr[i]=(2333*arr[i-1]+6666)%p;
		}
		int head=1,tail=n;
		for(int i=0;head<tail;i^=1){
			if(i==0) get_max(head,tail);
			else get_min(head,tail);
		}
		printf("%lld\n",arr[head]);
	}
	return 0;
}
