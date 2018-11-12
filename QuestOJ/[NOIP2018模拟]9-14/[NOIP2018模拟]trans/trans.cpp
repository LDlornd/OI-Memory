#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int MAXN=1e6+5;
char s[MAXN];
int n,k;
int vis[MAXN];
int main(){
	while(scanf("%d%d",&n,&k)!=EOF){
		memset(vis,0,sizeof(vis));
		scanf("%s",s+1);s[n+1]=0;
		int cnt=0,place=0;
		for(int i=1;i<n;++i){
			if(s[i]=='2'&&s[i+1]=='3'){
				++vis[i];
				if(vis[i]==3){
					place=i;
					break;
				}
				if(i&1) s[i+1]='2';
				else{
					s[i]='3';
					i-=2;
				}
				if((++cnt)==k) break;
				//cout<<cnt<<" "<<i<<" "<<vis[i]<<endl;
			}
		}
		//cout<<cnt<<" "<<place<<endl;
		int res=k-cnt;
		res%=4;cnt=0;
		for(int i=place;i<n;++i){
			if(s[i]=='2'&&s[i+1]=='3'){
				if((++cnt)>res) break;
				if(i&1) s[i+1]='2';
				else{
					s[i]='3';
					i-=2;
				}
			}
		}
		printf("%s\n",s+1);
	}
	return 0;
}
