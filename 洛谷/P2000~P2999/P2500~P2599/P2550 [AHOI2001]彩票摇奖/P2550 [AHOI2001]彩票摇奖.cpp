#include<cstdio>
#include<iostream>
using namespace std;
int n,k,temp;
int sum[10];
bool num[50];
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	n=read();
	for(int i=1;i<=7;++i) num[k=read()]=true;
	while(n--){
		temp=0;
		for(int i=1;i<=7;++i)
			if(num[k=read()]) ++temp;
		++sum[7-temp];
	}
	for(int i=0;i<=6;++i) printf("%d ",sum[i]);
	return 0;
}
