#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int MAXN=50001;
long long int ans=0;
int n;
int height[MAXN];
int Left[MAXN],Right[MAXN];
int Stack[MAXN],top=0;
int main(){
	ios::sync_with_stdio(false);
	memset(Left,0,sizeof(Left));
	memset(Right,0,sizeof(Right));
	cin>>n;
	for(int i=1;i<=n;++i) cin>>height[i];
	for(int i=1;i<=n;++i){
		Stack[++top]=i;
		while(top&&height[Stack[top]]<=height[Stack[top-1]]){
			Left[i]+=Left[Stack[top-1]];
			Stack[--top]=i;
		}
		++Left[i];
	}
	top=0;
	for(int i=n;i>=1;--i){
		Stack[++top]=i;
		while(top&&height[Stack[top]]<=height[Stack[top-1]]){
			Right[i]+=Right[Stack[top-1]];
			Stack[--top]=i;
		}
		++Right[i];
	}
	for(int i=1;i<=n;++i) ans=max(ans,(long long int)(Left[i]+Right[i]-1)*height[i]);
	cout<<ans<<endl;
	return 0;
}
