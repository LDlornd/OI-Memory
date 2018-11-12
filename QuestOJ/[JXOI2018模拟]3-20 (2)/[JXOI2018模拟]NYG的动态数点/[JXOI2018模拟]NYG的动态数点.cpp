#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
const int MAXN=500001;
int n,ans=1;
int arr[MAXN];
vector<int> V[MAXN];
inline int gcd(int a,int b){
	if(a<b) swap(a,b);
	if(b==0) return a;
	return gcd(b,a%b);
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
	for(int Left=1;Left<=n;++Left){
		for(int Right=Left+ans-1;Right<=n;++Right){
			int temp=arr[Left];
			for(int i=Left+1;i<=Right;++i) temp=gcd(temp,arr[i]);
			for(int i=Left;i<=Right;++i){
				if(arr[i]==temp){
					ans=max(ans,Right-Left);
					V[Right-Left].push_back(Left);
					break;
				}
			}
		}
	}
	int Size=V[ans].size();
	printf("%d %d\n",Size,ans);
	for(int i=0;i<Size;++i) printf("%d ",V[ans][i]);
	return 0;
}
