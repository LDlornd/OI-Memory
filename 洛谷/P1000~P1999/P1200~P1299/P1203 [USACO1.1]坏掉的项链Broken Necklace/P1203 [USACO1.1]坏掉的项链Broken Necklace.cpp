#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN=355;
char s[MAXN];
int n,cnt=1,tot=0,ans=0;
int num[MAXN];
int main(){
	scanf("%d%s",&n,s+1);
	for(int i=2;i<=n;++i){
		if(s[i]==s[i-1]) ++cnt;
		else{
			num[++tot]=cnt;
			cnt=1;
		}
	}
	num[++tot]=cnt;
	for(int i=1;i<=tot;++i) cout<<num[i]<<" ";cout<<endl;
	for(int i=2;i<=tot;++i)
		ans=max(ans,num[i-1]+num[i]);
	if(s[1]==s[n]){
		ans=max(ans,num[2]+num[1]+num[tot]);
		ans=max(ans,num[1]+num[tot]+num[tot-1]);
	}
	printf("%d",ans);
	return 0;
}
