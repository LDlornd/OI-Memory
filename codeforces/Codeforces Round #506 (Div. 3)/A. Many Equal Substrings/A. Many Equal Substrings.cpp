#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN=55;
char s[MAXN];
int n,k,place,len;
bool flag=true;
bool judge(int start1,int end1,int start2){
	for(;start1<=end1;++start1,++start2)
		if(s[start1]!=s[start2]) return false;
	return true;
}
int main(){
	scanf("%d%d%s",&n,&k,s+1);
	printf("%s",s+1);
	place=1;
	for(int i=1;i<n;++i)
		if(judge(1,1+i-1,n-i+1)){
			place=i+1;
		}
	while(--k) printf("%s",s+place);
	return 0;
}
