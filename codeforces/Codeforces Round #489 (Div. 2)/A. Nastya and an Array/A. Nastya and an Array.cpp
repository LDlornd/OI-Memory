#include<cstdio>
#include<iostream>
#include<map>
using namespace std;
const int MAXN=1e5+1;
int n,key,ans=0;
map<int,bool> mp;
int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%d",&key);
		if(key==0||mp.count(key)) continue;
		++ans;mp.insert(make_pair(key,true));
	}
	printf("%d",ans);
	return 0;
}
