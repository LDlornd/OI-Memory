#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN=18;
int n,m,k;
int arr[1<<MAXN],temp[1<<MAXN];
bool flag[1<<(MAXN+1)];
bool judge(int key){
	for(int i=1;i<=m;++i) if(flag[arr[i]]==false) return false;
	for(int i=1;i<key;++i)
		for(int j=i+1;j<=key;++j)
			if((temp[i]&temp[j])&&flag[temp[i]&temp[j]]==false) return false;
	int temp=1<<n;
	for(int i=1;i<temp;++i)
		for(int j=i+1;j<temp;++j)
			if(flag[i]==false&&flag[j]==false&&(i&j)&&flag[i&j]) return false;
	return true;
}
bool dfs(int now,int cnt){
	if(now==((1<<n))&&cnt!=k) return false;
	if(cnt==k) return judge(cnt);
	flag[now]=true;temp[cnt]=now;
	if(dfs(now+1,cnt+1)) return true;
	flag[now]=false;
	return dfs(now+1,cnt);
}
void get_10_pts(){
	if(dfs(1,0)==false) printf("-1");
	else{
		n=1<<n;
		for(int i=1;i<n;++i) printf("%d",flag[i]);
	}
}
void get_30_pts(){
	int temp=
}
void get_x_pts(){
	n=(1<<n);
	for(int i=1;i<n;++i) printf("1");
}
int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	n=read();m=read();k=read();
	for(int i=1;i<=m;++i) arr[i]=read();
	if(m>k) printf("-1");
	else if(k==((1<<n)-1)) get_x_pts();
	else if(m==0) get_30_pts();
	else get_10_pts();
	return 0;
}
