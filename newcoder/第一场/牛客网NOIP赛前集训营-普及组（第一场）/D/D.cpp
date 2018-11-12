#include<cstdio>
#include<string>
#include<iostream>
#include<map>
using namespace std;
const int MAXN=105;
string s[MAXN];
int n,len,k,ans=0;
int fa[MAXN];
map<string,int> mp;
void caculate(){
	mp.clear();
	for(int i='a';i<='h';++i)
		if(fa[fa[i]]!=fa[i]) return;
	for(int i=1;i<=n;++i){
		string temp;temp.resize(len);
		for(int j=0;j<len;++j)
			temp[j]=fa[s[i][j]];
		if(mp.count(temp)) ++mp[temp];
		else mp.insert(make_pair(temp,1));
	}
	int tempans=0;
	map<string,int>::iterator it=mp.begin();
	for(;it!=mp.end();++it)
		tempans+=(it->second*(it->second-1))>>1;
	ans=max(ans,tempans);
}
void dfs(int now,int cnt){
	if(cnt>k) return;
	if(now=='i') {caculate();return;}
	for(int i='a';i<=now;++i){
		fa[now]=i;
		dfs(now+1,cnt+(i!=now));
	}
}
void read(int key){
	s[key].resize(len);
	int now=0;
	char c=getchar();
	while(c<'a'||c>'h') c=getchar();
	for(;c>='a'&&c<='h';c=getchar()) s[key][now++]=c; 
}
int main(){
	scanf("%d%d%d",&n,&len,&k);
	for(int i=1;i<=n;++i) read(i);
	if(k>=7) ans=(n*(n-1))>>1;
	else dfs('a',0);
	printf("%d",ans);
	return 0;
}
