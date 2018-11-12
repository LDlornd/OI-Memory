#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int MAXN=1e5+5;
char s[MAXN];
int n,m,T,q,x,y,len;
int sum1=0,sum2=0;
int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	n=read();m=read();T=read();
	scanf("%s",s+1);len=strlen(s+1);
	for(int i=1;i<=len;++i){
		if(s[i]=='U') --sum1;
		if(s[i]=='D') ++sum1;
		if(s[i]=='L') --sum2;
		if(s[i]=='R') ++sum2;
	}
	if(sum1<0) sum1+=n;sum1=(sum1*T)%n;
	if(sum2<0) sum2+=m;sum2=(sum2*T)%m;
	q=read();
	while(q--){
		x=read()+sum1;y=read()+sum2;
		if(x>n) x%=n;
		if(y>m) y%=m;
		printf("%d %d\n",x,y);
	}
	return 0;
}
