#include<cstdio>
#include<iostream>
using namespace std;
typedef long long int ll;
const int MAXN=1e5+5;
ll ans;
int n,q,k,ql,qr;
int arr[MAXN];
bool judge(int key){
	int temp=0;
	for(int i=1;i<=key;i<<=1)
		temp+=((key&i)!=0);
	return temp==k;
}
int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	n=read();q=read();k=read();
	for(int i=1;i<=n;++i) arr[i]=read();
	while(q--){
		ql=read();qr=read();
		ans=0;
		for(int i=ql;i<=qr;++i)
			for(int j=i+1;j<=qr;++j)
				if(judge(arr[i]^arr[j])) ++ans;
		printf("%lld\n",ans);
	}
	return 0;
}
