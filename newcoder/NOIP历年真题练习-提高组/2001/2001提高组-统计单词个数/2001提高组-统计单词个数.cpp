#include<cstdio>
#include<iostream>
#include<string>
#include<map>
using namespace std;
const int MAXN=205;
char s[MAXN];
int n,k,num,maxlen=0;
int arr[MAXN][MAXN],dp[MAXN][MAXN];
string ss;
map<string,bool> mp;
int judge(int Start,int End){
	ss="";
	for(int i=Start;i<=End;++i){
		ss+=s[i];
		if(mp.count(ss)) return 1;
	}
	return 0;
}
void read(){
	int place=0;
	char c;
	while((c=getchar())){
		if(c<'a'||c>'z') continue;
		s[++place]=c;
		if(place==n) break;
	}
}
int readnum(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	n=readnum()*20;k=readnum();
	read();
	num=readnum();
	while(num--){
		cin>>ss;
		maxlen=max(maxlen,(int)ss.length());
		mp.insert(make_pair(ss,true));
	}
	for(int j=n;j>=1;--j)
		for(int i=j;i>=1;--i){
			arr[i][j]=arr[i+1][j]+judge(i,j);
		}
	for(int i=1;i<=n;++i){
		for(int w=1;w<=k;++w){
			if(w==1) {dp[i][w]=arr[1][i];continue;}
			for(int j=1;j<i;++j){
				if(dp[j][w-1]) dp[i][w]=max(dp[i][w],dp[j][w-1]+arr[j+1][i]);
			}
		}
	}
	printf("%d",dp[n][k]);
	return 0;
}
