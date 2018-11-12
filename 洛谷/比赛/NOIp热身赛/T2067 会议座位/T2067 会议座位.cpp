#include<cstdio>
#include<iostream>
#include<map>
using namespace std;
typedef long long int ll;
const int MAXN=100005;
string s;
ll ans=0;
int n;
int arr[MAXN],temp[MAXN];
map<string,int> mp;
bool judge(char c){
	if((c>='a'&&c<='z')||(c>='A'&&c<='Z')) return true;
	else return false;
}
void Merge(int s1,int e1,int e2){
	int p=s1,p1=s1,p2=e1+1;
	while(p1<=e1&&p2<=e2){
		if(arr[p1]<=arr[p2]) temp[p++]=arr[p1++];
		else{
			ans+=(e1-p1+1);
			temp[p++]=arr[p2++];
		}
	}
	while(p1<=e1) temp[p++]=arr[p1++];
	while(p2<=e2) temp[p++]=arr[p2++];
	for(int i=s1;i<=e2;++i) arr[i]=temp[i];
}
void merge_sort(int Start,int End){
	if(Start==End) return;
	int mid=(Start+End)>>1;
	merge_sort(Start,mid);
	merge_sort(mid+1,End);
	Merge(Start,mid,End);
}
void read(){
	s="";
	char c=getchar();
	while(judge(c)==false) c=getchar();
	for(;judge(c);c=getchar()) s+=c;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		read();
		mp.insert(make_pair(s,i));
	}
	for(int i=1;i<=n;++i){
		read();
		arr[i]=mp[s];
	}
	merge_sort(1,n);
	printf("%lld",ans);
	return 0;
}
