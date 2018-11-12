#include<cstdio>
#include<iostream>
using namespace std;
typedef long long int ll;
const int MAXN=300001;
int n,a,b,l,r;
bool flag1,flag2;
ll ans=0;
int more[MAXN],Less[MAXN],mnum1[MAXN],lnum1[MAXN],mnum2[MAXN],lnum2[MAXN];
inline void getstring(){
	a=b=l=r=0;
	flag1=true;flag2=true;
	char c=getchar(),cc=c;
	while(c!='('&&c!=')') c=getchar();
	while(c=='('||c==')'){
		if(c=='(') ++a;
		else ++b;
		if(r==0&&c==')') --l;
		else if(r!=0&&c==')') --r;
		else ++r;
		cc=c;
		c=getchar();
	}
}
int main(){
	scanf("%d",&n);
	while(n--){
		getstring();
		if(a>b){
			++more[a-b];
			if(l==0) ++mnum1[a-b];
			if(r==0) ++mnum2[a-b];
		}
		else if(a<b){
			++Less[b-a];
			if(l==0) ++lnum1[b-a];
			if(r==0) ++lnum2[b-a];
		}
		else if(l==0){
			++lnum1[0];++lnum2[0];
		}
	}
	for(int i=1;i<MAXN;++i){
		ans+=(ll)mnum1[i]*lnum2[i];
		ans+=(ll)lnum1[i]*mnum2[i];
	}
	ans+=(ll)lnum1[0]*lnum2[0];
	printf("%lld",ans);
	return 0;
}
