#include<cstdio>
#include<string>
#include<iostream>
#include<map>
using namespace std;
string s,last;
int n,len;
map<string,bool> mp;
int main(){
	scanf("%d",&n);
	cin>>last;len=last.length();
	mp.insert(make_pair(last,true));
	while(--n){
		cin>>s;
		if(mp.count(s)||s[0]!=last[len-1]){
			printf("No");
			return 0;
		}
		mp.insert(make_pair(s,true));
		last=s;len=last.length();
	}
	printf("Yes");
	return 0;
}
