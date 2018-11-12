#include<cstdio>
#include<iostream>
using namespace std;
int n,tot;
bool light[26];
int main(){
	scanf("%d",&n);
	while(n--){
		tot=0;
		for(int i=1;i<=25;++i){
			char c=getchar();
			while(c!='0'&&c!='1') c=getchar();
			tot+=(light[i]=(c=='1'));
			
		}
		dfs
		cout<<endl;
	}
}
