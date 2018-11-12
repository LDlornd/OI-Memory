#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN=100;
int T,n,l,r,ans;
int arr[MAXN],opt[MAXN];
inline bool judge(int Start,int End){
	if(Start+1>=End) return true;
	double temp=1.0*(double) arr[Start+1]/(double) arr[Start];
	for(int i=Start+2;i<=End;++i)
		if(temp!=1.0*(double) arr[i]/(double) arr[i-1]) return false;
	return true;
}
inline void chaifen(int now){
	if(now==n){
		bool flag=true;
		opt[n]=1;
		for(int i=1;i<=n;++i){
			for(int j=i;j<=n;++j){
				if(opt[j]){
					if(judge(i,j)==false){
						flag=false;
						break;
					}
					i=j;
					break;
				}
			}
			if(flag==false) break;
		}
		if(flag) ++ans;
		return;
	}
	opt[now]=0;
	chaifen(now+1);
	opt[now]=1;
	chaifen(now+1);
}
inline void dfs(int now){
	if(now==n+1){
		chaifen(1);
		return;
	}
	for(int i=l;i<=r;++i){
		arr[now]=i;
		dfs(now+1);
	}
}
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=x*10+c-'0';
	return x*f;
}
int main(){
	T=read();
	while(T--){
		n=read();l=read();r=read();
		ans=0;
		dfs(1);
		cout<<ans<<endl;
	}
}
