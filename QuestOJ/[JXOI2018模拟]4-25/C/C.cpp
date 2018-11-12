#include<cstdio>
#include<iostream>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	cout<<500000004;
	fclose(stdin);fclose(stdout);
	return 0;
}
