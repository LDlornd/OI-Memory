#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=101;
int n,kmp[MAXN];
bool flag=true;
struct str{
	string s;
	int len;
	str() {s="";len=0;}
}data[MAXN];
inline bool judge(string s1,string s2,int len1,int len2){
	for(int i=2,j=0;i<=len1;++i){
		while(j&&s1[i]!=s1[j+1]) j=kmp[j];
		if(s1[i]==s1[j+1]) ++j;
		kmp[i]=j;
	}
	for(int i=1,j=0;i<=len2;++i){
		while(j&&s2[i]!=s1[j+1]) j=kmp[j];
		if(s2[i]==s1[j+1]) ++j;
		if(j==len1) return true;
	}
	return false;
}
inline bool CMP(const str &a,const str &b){
	if(a.len==b.len) return a.s<b.s;
	return a.len<b.len;
}
inline string read(){
	string ss="";ss+=(char)0;
	char c=getchar();
	for(;c<'a'||c>'z';c=getchar()) continue;
	for(;c>='a'&&c<='z';c=getchar()) ss+=c;
	return ss;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		data[i].len=(data[i].s=read()).length()-1;
	sort(data+1,data+n+1,CMP);
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
			if(flag&&judge(data[i].s,data[j].s,data[i].len,data[j].len)) continue;
			else {flag=false;break;}
	if(flag==false) printf("NO");
	else{
		printf("YES\n");
		for(int i=1;i<=n;++i){
			string ans=data[i].s;
			ans.erase(ans.begin(),ans.begin()+1);
			printf("%s\n",ans.c_str());
		}
	}
	return 0;
}
