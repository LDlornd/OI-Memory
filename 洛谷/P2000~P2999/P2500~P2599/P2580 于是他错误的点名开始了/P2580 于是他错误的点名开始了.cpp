#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
const int MAXN=55;
char s[MAXN];
int n,m,len,flag;
struct trie{
	int val;
	trie *son[26];
	trie(){
		val=0;
		memset(son,0,sizeof(son));
	}
	void ins(int len,int now){
		if(len==now-1) return;
		if(son[s[now]-'a']) son[s[now]-'a']->ins(len,now+1);
		else (son[s[now]-'a']=new(trie))->ins(len,now+1);
	}
	int query_1(int len,int now){
		if(len==now-1) return 1;
		if(son[s[now]-'a']==NULL) return -1;
		return son[s[now]-'a']->query_1(len,now+1);
	}
	int query_2(int len,int now){
		if(len==now-1){
			if(val==1) return 0;
			else{
				val=1;
				return 1;
			}
		}
		if(son[s[now]-'a']==NULL) return -1;
		return son[s[now]-'a']->query_2(len,now+1);
	}
}*root;
int main(){
	root=new(trie);
	scanf("%d",&n);
	while(n--){
		scanf("%s",s+1);len=strlen(s+1);
		if(root->query_1(len,1)==-1) root->ins(len,1);
	}
	scanf("%d",&m);
	while(m--){
		scanf("%s",s+1);len=strlen(s+1);
		flag=root->query_2(len,1);
		if(flag==-1) printf("WRONG\n");
		if(flag==0) printf("REPEAT\n");
		if(flag==1) printf("OK\n");
	}
	return 0;
}
