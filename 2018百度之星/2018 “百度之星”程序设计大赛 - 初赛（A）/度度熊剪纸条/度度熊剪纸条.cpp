#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int MAXN=10005;
char s[MAXN];
int n,k,tot,place;
int dp[MAXN];
bool flag;
struct node{
	int cost,val;
	node(int cc=0,int vv=0){
		cost=cc;;val=vv;
	}
}arr[MAXN];
void getready(){
	memset(dp,0,sizeof(dp));
	tot=0;flag=false;
	++k;
}
int main(){
	while(scanf("%d%d",&n,&k)!=EOF){
		scanf("%s",s+1);
		getready();
		for(int l=1;l<=n;++l){
			if(s[l]=='0') continue;
			for(int r=l;r<=n;++r){
				if(s[r+1]=='1') continue;
				if(l==1&&r==n) arr[++tot]=node(0,r-l+1);
				if(l==1&&r!=n) arr[++tot]=node(1,r-l+1);
				if(l!=1&&r==n) arr[++tot]=node(1,r-l+1);
				if(l!=1&&r!=n) arr[++tot]=node(2,r-l+1);
				if(flag==false) {place=r;flag=true;}
				l=r;break;
			}
		}
		if(k==1){
			if(s[1]=='0') printf("%d\n",0);
			else printf("%d\n",place);
			continue;
		}
		for(int w=1;w<=tot;++w)
			for(int i=k;i>=arr[w].cost;--i)
				dp[i]=max(dp[i],dp[i-arr[w].cost]+arr[w].val);
		printf("%d\n",dp[k]);
	}
	return 0;
}
