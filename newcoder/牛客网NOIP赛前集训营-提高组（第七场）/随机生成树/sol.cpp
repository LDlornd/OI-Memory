#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN=500005;
int n,ans=1,cnt=0;
int color[MAXN],differ[MAXN];
bool flag[MAXN];
int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	n=read();color[1]=read();
	for(int i=2;i<=n;++i){
		color[i]=read();
		if(color[i]==color[1]) flag[i]=true;
		else{
			++ans;
			differ[++cnt]=i;
		}
	}
	for(int i=1;i<=cnt;++i)
		for(int j=differ[i];j<=n;j+=differ[i])
			if(flag[j]){
				++ans;flag[j]=false;
			}
	printf("%d",ans);
	return 0;
}
