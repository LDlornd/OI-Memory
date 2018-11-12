#include<cstdio>
#include<string>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
const int MAXN=101;
int n;
int in[MAXN],Copy[MAXN],kmp[MAXN];
int res[MAXN],head,tail;
struct str{
	string s;
	int len;
	str() {s="";len=0;}
}data[MAXN];
struct edge{
	int v;
	edge *nex;
	edge() {v=0;nex=NULL;}
}*con[MAXN];
inline void ins(int Start,int End){
	edge *p=new(edge);
	p->v=End;p->nex=con[Start];con[Start]=p;
	++in[End];
}
inline void top_sort(){
	head=1;tail=0;
	for(int i=1;i<=n;++i) if(in[i]==0) res[++tail]=i;
	while(head<=tail){
		int nv=res[head++];
		for(edge *p=con[nv];p;p=p->nex){
			if(--in[p->v]==0) res[++tail]=p->v;
		}
	}
}
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
inline bool CMP1(int a,int b){
	return a<b;
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
			if(judge(data[i].s,data[j].s,data[i].len,data[j].len))
				ins(i,j);
	top_sort();
	for(int i=n;i>=1;--i)
		for(int j=i-1;j>=1;--j)
			if(judge(data[res[j]].s,data[res[i]].s,data[res[j]].len,data[res[i]].len)) continue;
			else {tail=0;break;}
	if(tail!=n) printf("NO");
	else{
		printf("YES\n");
		for(int i=1;i<=n;++i){
			string ans=data[res[i]].s;
			ans.erase(ans.begin(),ans.begin()+1);
			printf("%s\n",ans.c_str());
		}
	}
	return 0;
}
