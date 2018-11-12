#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN=1e6+5;
char s[MAXN];
int n,k;
int main(){
	freopen("trans.in","r",stdin);
	freopen("ac.out","w",stdout);
	while(scanf("%d%d",&n,&k)!=EOF){
		scanf("%s",s+1);s[n+1]=0;
		while(k--){
			bool flag=false;
			for(int i=1;i<n;++i){
				if(s[i]=='2'&&s[i+1]=='3'){
					if(i&1) s[i+1]='2';
					else s[i]='3';
					flag=true;break;
				}
			}
			if(flag==false) break;
		}
		printf("%s\n",s+1);
	}
	return 0;
}
