#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
string s="";
int n,k,len;
inline string change(int key){
	string ss="";
	for(int i=7;i>=0;--i){
		if((1<<i)<=key) {key-=(1<<i);ss+="1";}
		else ss+="0";
	}
	return ss;
}
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	n=read();
	for(int i=0;i<n;i+=8){
		k=read();
		s+=change(k);
	}
	len=s.length();
	for(int i=0;i<len;++i){
		int place,temp=0;
		for(place=i;place+1<len;++place)
			if(s[place+1]!=s[i]) break;
		if(s[i]=='1') temp+=(1<<7);
		temp+=(place-i+1);
		i=place;
		printf("%d ",temp);
	}
	return 0;
}
