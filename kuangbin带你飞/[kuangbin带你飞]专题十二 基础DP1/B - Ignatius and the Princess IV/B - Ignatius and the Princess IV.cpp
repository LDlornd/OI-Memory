#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN=1e6+5;
int n,now,sum;
int arr[MAXN];
int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	while(scanf("%d",&n)!=EOF){
		for(int i=1;i<=n;++i){
			arr[i]=read();
			if(i==1) {now=arr[i];sum=1;}
			else{
				if(arr[i]==now) ++sum;
				else if(sum>0) --sum;
				else {now=arr[i];sum=1;}
			}
		}
		printf("%d\n",now);
	}
	return 0;
}
