#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int MAXN=101;
int len;
char s[MAXN];
int main(){
	scanf("%s",s+1);
	len=strlen(s+1);
	for(int i=1;i<=len-2;++i){
		if(s[i]=='.'||s[i+1]=='.'||s[i+2]=='.') continue;
		if(s[i]==s[i+1]||s[i]==s[i+2]||s[i+1]==s[i+2]) continue;
		printf("Yes");
		return 0;
	}
	printf("No");
	return 0;
}
