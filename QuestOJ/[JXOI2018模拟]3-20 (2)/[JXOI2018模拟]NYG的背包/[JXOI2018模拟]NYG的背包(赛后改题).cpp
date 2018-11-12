#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long int ll;
const int MAXN=100001;
ll T,n,V,nv,cost,add,uptot=0,downtot=0;
bool flag;
struct backpack{
	ll a,b;
	backpack(ll aa=0,ll bb=0) {a=aa;b=bb;}
}up[MAXN],down[MAXN];
inline bool CMP(const backpack &x,const backpack &y){
	return x.a<y.a;
}
inline ll read(){
	ll x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=x*10+c-'0';
	return x*f;
}
int main(){
	//freopen("ex_backpack1.in","r",stdin);
	T=read();
	while(T--){
		uptot=downtot=0;
		flag=true;
		n=read();V=read();
		while(n--){
			cost=read();add=read();
			if(cost<=add) up[++uptot]=backpack(cost,add);
			else down[++downtot]=backpack(add,cost);
		}
		sort(up+1,up+uptot+1,CMP);
		sort(down+1,down+downtot+1,CMP);
		//cout<<uptot<<endl;
		for(int i=1;i<=uptot;++i){
			//cout<<up[i].a<<" "<<up[i].b<<endl;
			if(V<up[i].a){flag=false;break;}
			V+=(up[i].b-up[i].a);
		}
		nv=down[1].a;
		//cout<<downtot<<endl;
		for(int i=downtot;i>=1;--i){
			//cout<<down[i].a<<" "<<down[i].b<<endl;
			if(V<down[i].b){flag=false;break;}
			V-=(down[i].b-down[i].a);
		}
		//if(nv>V) flag=false;
		if(V<0) flag=false;
		if(flag) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
