#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
const int MAXN=101;
const int mod=1e9+7;
int n,k,ans=0;
string l,r;
string arr[MAXN];
inline string add(string key){
	int len=key.length();
	for(int i=len-1;i>=0;--i){
		if(key[i]!='9') {++key[i];break;}
		key[i]='0';
	}
	if(key[0]=='0') key.insert(0,"1");
	return key;
}
inline bool cmp(string a,string b){
	int lena=a.length(),lenb=b.length();
	if(lena<lenb) return true;
	if(lena>lenb) return false;
	for(int i=0;i<lena;++i){
		if(a[i]<b[i]) return true;
		if(a[i]>b[i]) return false;
	}
	return true;
}
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=x*10+c-'0';
	return x*f;
}
int main(){
	n=read();k=read();
	cin>>l>>r;
	for(int i=1;i<=n;++i) cin>>arr[i];
	for(string s=add(l);cmp(s,r);s=add(s)){
		int sum=0;
		for(int i=1;i<=n&&sum<k;++i)
			if(s.find(arr[i])!=-1) ++sum;
		if(sum==k) (++ans)%=mod;
	}
	printf("%d",ans);
	return 0;
}
