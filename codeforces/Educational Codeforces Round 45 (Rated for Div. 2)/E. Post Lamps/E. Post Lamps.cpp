#include<cstdio>
#include<iostream>
# define ll I64d
using namespace std;
typedef long long int ll;
const int MAXN=1e6+1;
ll ans=1e15+1;
int n,m,k,lst=-1,now,tot=0,maxtot=0;
int cost[MAXN],fa[MAXN];
bool flag[MAXN];
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	n=read();m=read();k=read();
	for(int i=1;i<=n;++i) fa[i]=i-1;
	if(m) tot=1;
	while(m--){
		now=read()+1;
		flag[now]=true;
		//cout<<now<<" "<<lst<<" "<<tot<<endl;
		if(now==lst+1){
			++tot;
			fa[now]=fa[now-1];
		}
		else{
			maxtot=max(maxtot,tot);
			tot=1;
		}
		lst=now;
	}
	maxtot=max(maxtot,tot);
	for(int i=1;i<=k;++i) cost[i]=read();
	//cout<<maxtot<<" "<<k<<endl;
	for(int i=maxtot+1;i<=k;++i){
		now=1;tot=0;
		while(now<=n){
			if(now==0) break;
			if(flag[now]) now=fa[now];
			else{
				now=now+i;
				++tot;
			}
		}
		//cout<<now<<" "<<tot<<endl;
		if(now>n) ans=min(ans,(ll)cost[i]*tot);
	}
	if(ans==1e15+1) printf("-1");
	else printf("%lld",ans);
	return 0;
}
