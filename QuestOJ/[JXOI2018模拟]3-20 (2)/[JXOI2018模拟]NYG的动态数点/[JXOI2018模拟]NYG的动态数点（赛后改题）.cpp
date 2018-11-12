#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
const int MAXN=500001;
int n,ans=0;
int arr[MAXN],log[MAXN],tot[MAXN];
int GCD[20][MAXN],MIN[20][MAXN];
vector<int> place[MAXN];
inline int gcd(int a,int b){
	if(a<b) swap(a,b);
	return (b==0)?a:gcd(b,a%b);
}
inline void getready(){
	log[0]=0;log[1]=0;
	for(int i=2;i<=n;++i) log[i]=log[i-1]+((1<<(log[i-1]+1))==i);
	for(int i=1;i<MAXN;++i)
		for(int w=0;w<20;++w)
			MIN[w][i]=2147283647;
	for(int i=1;i<=n;++i){GCD[0][i]=arr[i];MIN[0][i]=arr[i];}
	for(int w=1;w<=20;++w){
		for(int i=1;i<=n;++i){
			GCD[w][i]=gcd(GCD[w-1][i],GCD[w-1][i+(1<<(w-1))]);
			MIN[w][i]=min(MIN[w-1][i],MIN[w-1][i+(1<<(w-1))]);
		}
	}
}
inline int query_gcd(int Start,int End){
	int temp=log[End-Start+1];
	return gcd(GCD[temp][Start],GCD[temp][End-(1<<temp)+1]);
}
inline int query_min(int Start,int End){
	int temp=log[End-Start+1];
	return min(MIN[temp][Start],MIN[temp][End-(1<<temp)+1]);
}
inline bool judge(int len){
	bool flag=false;
	for(int i=1;i+len-1<=n;++i){
		if(query_gcd(i,i+len-1)==query_min(i,i+len-1)){
			++tot[len];flag=true;
			place[len].push_back(i);
		}
	}
	return flag;
}
inline int Search(){
	int l=1,r=n,templen=0;
	while(l<r){
		int mid=(l+r)>>1;
		if(judge(mid)){
			templen=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	if(judge(l)) templen=l;
	return templen;
}
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=x*10+c-'0';
	return x*f;
}
int main(){
	n=read();
	for(int i=1;i<=n;++i) arr[i]=read();
	getready();
	ans=Search();
	printf("%d %d\n",tot[ans],ans-1);
	for(int i=0;i<tot[ans];++i) printf("%d ",place[ans][i]);
	return 0;
}
