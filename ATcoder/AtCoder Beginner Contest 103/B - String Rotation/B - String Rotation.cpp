#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int MAXN=201;
char s[MAXN],t[MAXN];
int len;
int main(){
	scanf("%s",s);scanf("%s",t);
	len=strlen(s);
	for(int i=len;i<(len<<1);++i) s[i]=s[i-len];
	for(int Left=0;Left<len;++Left){
		bool flag=true;
		for(int i=0;i<len;++i)
			if(s[Left+i]!=t[i]) {flag=false;break;}
		if(flag) {printf("Yes\n");return 0;}
	}
	printf("No\n");
	return 0;
}
