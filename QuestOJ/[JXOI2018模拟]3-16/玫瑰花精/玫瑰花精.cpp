#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
const int MAXN=200001;
int n,m,opt,key;
int arr[MAXN];
int Left[MAXN],Right[MAXN];
bool flag[MAXN];
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;++i) Left[i]=Right[i]=MAXN+1;
	while(m--){
		cin>>opt>>key;
		if(opt==1){
			int temp=0,place;
			for(int i=1;i<=n;++i){
				if(flag[i]==false&&min(Left[i],Right[i])>temp){
					temp=min(Left[i],Right[i]);
					place=i;
				}
			}
			flag[place]=true;arr[place]=key;
			for(int i=place-1;i>=1;--i){
				Right[i]=place-i;
				if(flag[i]) break;
			}
			for(int i=place+1;i<=n;++i){
				Left[i]=i-place;
				if(flag[i]) break;
			}
			cout<<place<<endl;
		}
		else{
			int place;
			for(int i=1;i<=n;++i) if(arr[i]==key) {place=i;break;}
			for(int i=place-1;i>=1;--i){
				Right[i]+=Right[place];
				if(flag[i]) break;
			}
			for(int i=place+1;i<=n;++i){
				Left[i]+=Left[place];
				if(flag[i]) break;
			}
			flag[place]=false;
		}
	}
	return 0;
}
