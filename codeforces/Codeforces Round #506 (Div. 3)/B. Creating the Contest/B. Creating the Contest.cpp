#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN=2e5+1;
int n,ans=0;
int arr[MAXN];
int Search(int Start,int key){
	int Left=Start+1,Right=n,tempans=0;
	while(Left<=Right){
		int mid=(Left+Right)>>1;
		if(arr[mid]<=key){
			tempans=mid;
			Left=mid+1;
		}
		else Right=mid-1;
	}
	return tempans;
}
int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	n=read();;
	for(int i=1;i<=n;++i) arr[i]=read();
	for(int i=1;i<=n;++i){
		int temp=i,nex;
		while((nex=Search(temp,arr[temp]<<1))!=0) temp=nex;
		ans=max(ans,temp-i+1);
	}
	printf("%d",ans);
	return 0;
}
