#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int MAXN=2001;
int n,p;
int arr[MAXN];
bool flag=false;
inline bool judge(int startplace){
	if(arr[startplace+p]==arr[startplace]) return false;
	arr[startplace+p]=arr[startplace]^1;
	return true;
}
int main(){
	scanf("%d%d",&n,&p);
	for(int i=1;i<=n;++i){
		char c=getchar();
		while(c!='0'&&c!='1'&&c!='.') c=getchar();
		if(c=='0') arr[i]=0;
		if(c=='1') arr[i]=1;
		if(c=='.') arr[i]=-1;
	}
	for(int i=1;i<=n-p;++i){
		if(flag) break;
		if(arr[i]!=-1) flag=judge(i);
		else{
			arr[i]=0;
			if(judge(i)==false) arr[i]=1;
			flag=judge(i);
		}
	}
	if(flag==false) printf("No");
	else{
		for(int i=1;i<=n;++i){
			if(arr[i]==-1) arr[i]=0;
			printf("%d",arr[i]);
		}
	}
	return 0;
}
