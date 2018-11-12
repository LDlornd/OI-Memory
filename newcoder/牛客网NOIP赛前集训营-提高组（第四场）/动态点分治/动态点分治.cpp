#include<cstdio>
#include<iostream>
using namespace std;
typedef long long int ll;
int T;
ll l,r,k;
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
		l=read<ll>();r=read<ll>();k=read<ll>();
		if(k==0){
			if(l<=0&&r>=0){
                printf("0 ");
                if(l<=1&&r>=1) printf("1");
            }
            else if(l<=1&&r>=1) printf("1");
			else printf("None.");
		}
		else if(k==1){
			if(l<=1&&r>=1) printf("1");
			else printf("None.");
		}
		else{
			bool flag=false;
			for(ll now=1;now<=r;now*=k){
				if(now>=l){
					printf("%lld ",now);
					flag=true;
				}
				if((r/now)<k) break;
			}
			if(flag==false) printf("None.");
		}
		printf("\n");
	}
	return 0;
}
