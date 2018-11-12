#include<cmath>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long int ll;
const int MAXN=50005;
int n;
double ans=0;
struct node{
	ll x,y,z;
	node(){x=y=z=0;}
}arr[MAXN];
double get_dist(int Start,int End){
	return sqrt((arr[Start].x-arr[End].x)*(arr[Start].x-arr[End].x)+(arr[Start].y-arr[End].y)*(arr[Start].y-arr[End].y)+(arr[Start].z-arr[End].z)*(arr[Start].z-arr[End].z));
}
bool CMP(const node &a,const node &b){
	return a.z<b.z;
}
template<typename T>
T read(){
	T x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	n=read<int>();
	for(int i=1;i<=n;++i) {arr[i].x=read<ll>();arr[i].y=read<ll>();arr[i].z=read<ll>();}
	sort(arr+1,arr+n+1,CMP);
	for(int i=2;i<=n;++i) ans=ans+get_dist(i,i-1);
	printf("%.3lf",ans);
	return 0;
}
