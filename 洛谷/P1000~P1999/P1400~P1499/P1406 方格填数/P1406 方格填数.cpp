#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
const int MAXN=17;
int n,N,ans=0,sum=0;
int num[MAXN],temp[MAXN];
bool flag=false,vis[MAXN];
inline bool check(int a,int b,int c=0,int d=0){
	if(temp[a]+temp[b]+temp[c]+temp[d]==sum) return true;
	else return false;
}
inline void dfs_1(int now){
	temp[now]=num[now];
}
inline void dfs_2(int now){
	if(now==4){
		temp[4]=sum-temp[3];
		if(check(1,4)==false||check(2,4)==false) return;
		flag=true;return;
	}
	for(int i=1;i<=4;++i){
		if(vis[i]) continue;
		temp[now]=vis[i];
		if(now==2&&check(1,2)==false) continue;
		if(now==3&&(check(1,3)==false||check(2,3)==false)) continue;
		vis[i]=true;
		dfs_2(now+1);
		if(flag) return;
		vis[i]=false;
	}
}
inline void dfs_3(int now){
	if(now==9){
		temp[9]=sum-temp[7]-temp[8];
		if(check(1,5,9)==false||check(3,6,9)==false) return;
		flag=true;return;
	}
	for(int i=1;i<=9;++i)
	{
		if(vis[i]) continue;
		temp[now]=num[i];
		if(now==3&&check(1,2,3)==false) continue;
		if(now==6&&check(4,5,6)==false) continue;
		if(now==7&&(check(1,4,7)==false||check(3,5,7)==false)) continue;
		if(now==8&&check(2,5,8)==false) continue;
		vis[i]=true;
		dfs_3(now+1);
		if(flag) return;
		vis[i]=false;
	}
}
inline void dfs_4(int now){
	if(now==16){
		temp[16]=sum-temp[13]-temp[14]-temp[15];
		if(check(1,6,11,16)==false||check(4,8,12,16)==false) return;
		flag=true;return;
	}
	for(int i=1;i<=16;++i){
		if(vis[i]) continue;
		temp[now]=num[i];
		if(now==4&&check(1,2,3,4)==false) continue;
		if(now==8&&check(5,6,7,8)==false) continue;
		if(now==12&&check(9,10,11,12)==false) continue;
		if(now==13&&(check(1,5,9,13)==false||check(4,7,10,13)==false)) continue;
		if(now==14&&check(2,6,10,14)==false) continue;
		if(now==15&&check(3,7,11,15)==false) continue;
		vis[i]=true;
		dfs_4(now+1);
		if(flag) return;
		vis[i]=false;
	}
}
inline bool CMP(int a,int b){
	return a<b;
}
int main()
{
	freopen("testdata.in","r",stdin);
	ios::sync_with_stdio(false);
	memset(vis,0,sizeof(vis)); 
	cin>>n;N=n*n;
	for(int i=1;i<=N;++i){
		cin>>num[i];sum+=num[i];
	}
	sort(num+1,num+N+1,CMP);
	sum/=n;temp[0]=0;
	if(n==1) dfs_1(1);
	if(n==2) dfs_2(1);
	if(n==3) dfs_3(1);
	if(n==4) dfs_4(1);
	cout<<sum<<endl;
	for(int i=1;i<=N;++i)
		if(i%n!=0) cout<<temp[i]<<" ";
		else cout<<temp[i]<<endl;
	return 0;
}
