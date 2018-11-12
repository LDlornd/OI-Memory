#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
int T,len;
string s;
inline bool judge1(int Start,int End){
	int mid=(Start+End)>>1;
	for(int i=Start,j=End;i<=mid;++i,--j)
		if(s[i]!=s[j]) return false;
	return true;
}
inline bool judge2(int Start,int End){
	if((len&1)==0) return false;
	int mid=(Start+End)>>1;
	for(int i=Start+1;i<mid;++i)
		if(s[i]!=s[i-1]) return false;
	return true;
}
inline bool judge3(int Start,int End){
	for(int i=Start+2;i<=End;i+=2)
		if(s[i]!=s[i-2]) return false;
	for(int i=Start+3;i<=End;++i)
		if(s[i]!=s[i-2]) return false;
	return true;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--){
		cin>>len>>s;
		if(judge1(0,len-1)==false) cout<<1<<endl;
		else if(judge2(0,len-1)||judge3(0,len-1)) cout<<-1<<endl;
		else cout<<2<<endl;
	}
	return 0;
}
