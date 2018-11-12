#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int MAXN=1e6+1;
char s1[MAXN],s2[MAXN];
int len1,len2,kmp[MAXN];
inline void getready(){
	kmp[1]=0;
	for(int i=2,j=0;i<=len2;++i){
		while(j&&s2[i]!=s2[j+1]) j=kmp[j];
		if(s2[i]==s2[j+1]) ++j;
		kmp[i]=j;
	}
}
inline void Kmp(){
	getready();
	for(int i=1,j=0;i<=len1;++i){
		while(j&&s1[i]!=s2[j+1]) j=kmp[j];
		if(s1[i]==s2[j+1]) ++j;
		if(j==len2){
			printf("%d\n",i-j+1);
			j=kmp[j];
		}
	}
}
int main(){
	scanf("%s%s",s1+1,s2+1);
	len1=strlen(s1+1);len2=strlen(s2+1);
	Kmp();
	for(int i=1;i<=len2;++i) printf("%d ",kmp[i]);
	return 0;
}
