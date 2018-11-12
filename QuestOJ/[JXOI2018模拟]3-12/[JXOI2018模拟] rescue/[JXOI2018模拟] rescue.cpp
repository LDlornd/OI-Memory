#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=31;
int n,flag[MAXN],need=1,ans;
struct node{
	int data,num;
	node() {data=num=0;}
}arr[MAXN];
inline bool CMP(const node &a,const node &b){
	return a.num>b.num;
}
int main(){
	ios::sync_with_stdio(false);
	memset(flag,0,sizeof(flag));
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>arr[i].data;
		for(int j=1;j<i;++j)
			if(arr[i].data%arr[j].data==0) ++arr[j].num;
	}
	sort(arr+1,arr+n+1,CMP);
	flag[1]=2;
	for(ans=0;;++ans){
		need=0;
		for(int i=1;i<=n;++i){
			if(flag[i]==0) need=1;
			if(flag[i]==1) flag[i]=2;
		}
		if(need==0) break;
		for(int i=n;i>=1;--i){
			if(flag[i]!=2) continue;
			for(int j=i+1;j<=n;++j){
				if(flag[j]==0&&arr[j].data%arr[i].data==0){
					flag[j]=1;break;
				}
			}
		}
		for(int i=1;i<=n;++i) if(flag[i]==1) cout<<arr[i].data<<" ";cout<<endl;
	}
	cout<<ans;
	return 0;
}
