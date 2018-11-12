#include<cmath>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
int n,place,cnt=0;
double kx,ky,ans=0,temp=0;
struct point{
	double x,y;
}arr[MAXN];
double get_dist(double keyx,double keyy){
	double tmp=0;
	for(int i=1;i<=n;++i)
		tmp+=(abs(arr[i].x-keyx)+abs(arr[i].y-keyy));
	return tmp;
}
bool CMP(const point &a,const point &b){
	if(a.x==b.x) return a.y<b.y;
	else return a.x<b.x;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%lf%lf",&kx,&ky);
		arr[i].x=(kx+ky)/2;
		arr[i].y=(kx-ky)/2;
	}
	sort(arr+1,arr+n+1,CMP);
	if(n&1){
		place=(n>>1)+1;
		kx=arr[place].x;
		ky=arr[place].y;
	}
	else{
		place=n>>1;
		kx=(arr[place].x+arr[place+1].x)/2;
		ky=(arr[place].y+arr[place+1].y)/2;
	}
	ans=get_dist(kx,ky);cnt=1;
	if(get_dist(kx-0.5,ky-0.5)==ans) ++cnt;
	cout<<cnt<<endl;
	if(get_dist(kx-0.5,ky+0.5)==ans) ++cnt;
	cout<<cnt<<endl;
	if(get_dist(kx+0.5,ky-0.5)==ans) ++cnt;
	cout<<cnt<<endl;
	if(get_dist(kx+0.5,ky+0.5)==ans) ++cnt;
	printf("%lf\n%d",ans,cnt);
	return 0;
}
