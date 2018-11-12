#include<cstdio>
#include<cstring>
#include<iostream>
#include<map>
using namespace std;
const int MAXN=1e4+1;
const int LEN=2e5+1;
struct node{
	int rank,place;
	node(int rr=0,int pp=0) {rank=rr;place=pp;}
};
int n,len,sum;
int arr[LEN];
bool flag[MAXN<<1];
map<int,node> mp1;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		sum=0;
		memset(flag,0,sizeof(flag));
		len=read();
		for(int j=1;j<=len;++j) sum+=(arr[j]=read());
		for(int j=1;j<=len;++j){
			if(flag[arr[j]+MAXN]) continue;
			flag[arr[j]+MAXN]=true;
			if(mp1.count(sum-arr[j])){
				printf("YES\n%d %d\n",mp1[sum-arr[j]].rank,mp1[sum-arr[j]].place);
				printf("%d %d",i,j);
				return 0;
			}
			else mp1.insert(make_pair(sum-arr[j],node(i,j)));
		}
	}
	printf("NO");
	return 0;
}
