#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
const int MAXN=1050000;
char s[MAXN];
int n,m,len;
bool dp[MAXN];
struct trie{
	bool val;
	trie *son[26];
	trie(){
		val=false;
		memset(son,0,sizeof(son));
	}
	void ins(int len,int now){
		if(now==0){
			val=true;
			return;
		}
		if(son[s[now]-'a']) son[s[now]-'a']->ins(len,now-1);
		else (son[s[now]-'a']=new(trie))->ins(len,now-1);
	}
	void query(int now,int place){
		if(val&&dp[now]){
			dp[place]=true;
			return;
		}
		if(son[s[now]-'a']) son[s[now]-'a']->query(now-1,place);
		return;
	}
}*root;
int main(){
	root=new(trie);
	scanf("%d%d",&n,&m);
	while(n--){
		scanf("%s",s+1);len=strlen(s+1);
		root->ins(len,len);
	}
	while(m--){
		memset(dp,0,sizeof(dp));dp[0]=true;
		scanf("%s",s+1);len=strlen(s+1);
		for(int i=1;i<=len;++i)
			root->query(i,i);
		for(int i=len;i>=0;--i)
			if(dp[i]){
				printf("%d\n",i);
				break;
			}
	}
	return 0;
}
