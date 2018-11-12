#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int INF=2000000000;
const int MAXN=1005;
char s[MAXN];
int T,n,ans;
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%s",&n,s+1);
        ans=0;
        for(int i=1;i<=n;++i){
        	if(s[i]=='.'){
        		++ans;
        		i+=2;
			}
		}
		printf("%d\n",ans);
    }
    return 0;
}
