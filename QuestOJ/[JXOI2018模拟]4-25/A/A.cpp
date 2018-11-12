#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long int ll;
const int MAXN=2501;
const int mod=1e9+7;
ll ans=0;
int n,m,T,u,v,l;
int dist[MAXN],num[MAXN],Size[MAXN];
int Queue[MAXN<<3],head,tail;
bool inq[MAXN];
struct zdl{
	int len,gnum;
	zdl(int ll=0,int gg=0) {len=ll;gnum=gg;}
};
vector<zdl> arr[MAXN];
struct edge{
	int v,len;
	edge *nex;
	edge() {v=len=0;nex=NULL;}
}*con[MAXN];
inline void ins(int Start,int End,int key){
	edge *p=new(edge);
	p->v=End;p->len=key;
	p->nex=con[Start];con[Start]=p;
	p=new(edge);
	p->v=Start;p->len=key;
	p->nex=con[End];con[End]=p;
}
inline void spfa(){
	for(int i=2;i<=n;++i) dist[i]=2147483647;
	dist[1]=num[1]=0;inq[1]=true;
	Queue[head=tail=1]=1;
	while(head<=tail){
		int nv=Queue[head++];
		for(edge *p=con[nv];p;p=p->nex){
			int vv=p->v;
			if(dist[vv]>dist[nv]+p->len){
				dist[vv]=dist[nv]+p->len;
				num[vv]=num[nv]+1;
				arr[vv].push_back(zdl(dist[vv],num[vv]));
				++Size[vv];
				if(inq[vv]==false){
					Queue[++tail]=vv;
					inq[vv]=true;
				}
			}
		}
		inq[nv]=false;
	}
}
inline bool CMP(const zdl &a,const zdl &b){
	if(a.gnum==b.gnum) return a.len<b.len;
	return a.gnum>b.gnum;
}
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	n=read();m=read();T=read();
	while(m--){
		u=read();v=read();l=read();
		ins(u,v,l);
	}
	spfa();
	if(T==0){
		for(int i=1;i<=n;++i) (ans+=dist[i])%=mod;
	}
	else{
		for(int i=1;i<=n;++i){
			sort(arr[i].begin(),arr[i].end(),CMP);
			for(int j=0;j<Size[i];++j)
				if(arr[i][j].gnum>=num[i]&&arr[i][j].len>=dist[i]){
					arr[i].erase(arr[i].begin()+j,arr[i].begin()+j+1);
					--Size[i];--j;
				}
				else break;
			for(int j=0;j<Size[i]-1;++j)
				if(arr[i][j].gnum==arr[i][j+1].gnum){
					arr[i].erase(arr[i].begin()+j+1,arr[i].begin()+j+2);
					--Size[i];--j;
				}
		}
		for(int i=2;i<=n;++i){
			int mintemp=2147483647,nowtime=0;
			ll tempans=0;
			while(Size[i]&&nowtime<T){
				mintemp=2147483647;
				for(int k=0;k<Size[i];++k){
					int temp=(arr[i][k].len-dist[i])/(num[i]-arr[i][k].gnum);
					if(temp<mintemp){
						mintemp=temp;
						arr[i].erase(arr[i].begin(),arr[i].begin()+k);
						Size[i]-=k;k=0;
					}
				}
				if(nowtime+mintemp>=T){
					ll k=T-nowtime+1;
					tempans=(tempans+(ll) dist[i]*k%mod+k*(k-1)/2%mod*num[i]%mod)%mod;
					nowtime=T+1;
					break;
				}
				else{
					ll k=mintemp+1;
					tempans=(tempans+(ll) dist[i]*k%mod+(k*(k-1)/2%mod*num[i]%mod))%mod;
					for(int j=0;j<Size[i];++j)
						arr[i][j].len+=(k*arr[i][j].gnum);
					nowtime=nowtime+k;
				}
				num[i]=arr[i][0].gnum;
				dist[i]=arr[i][0].len;
				arr[i].erase(arr[i].begin(),arr[i].begin()+1);
				--Size[i];
			}
			if(nowtime<T){
				ll k=T-nowtime+1;
				tempans=(tempans+(ll) dist[i]*k%mod+k*(k-1)/2%mod*num[i]%mod)%mod;
				nowtime=T+1;
			}
			(ans+=tempans)%=mod;
		}
	}
	printf("%lld",ans);
	fclose(stdin);fclose(stdout);
	return 0;
}
