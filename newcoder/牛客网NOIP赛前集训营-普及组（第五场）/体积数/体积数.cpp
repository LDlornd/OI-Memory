#include<cstdio>
#include<iostream>
using namespace std;
typedef long long int ll;
const int MAXN=1e7+5;
int limit,ans=1;
bool vis[MAXN];
int main(){
	scanf("%d",&limit);
	for(int i=2;i<=limit;++i){
		ll now=i*i;
		if(now>limit) break;
		while(now<=limit){
			if(vis[now]==false){
				++ans;
				vis[now]=true;
			}
			now*=i;
		}
	}
	printf("%d",ans);
	return 0;
}
