#include<cstdio>
#include<iostream>
#include<string>
#include<map>
using namespace std;
const int MAXN=101;
map<string,double> mp;
int len,tot=0,sum=0;
int place[MAXN];
double m[MAXN],ans=0;
string s,ss;
inline void getready(){
	mp.clear();
	mp.insert(make_pair("H",1));
	mp.insert(make_pair("C",12));
	mp.insert(make_pair("N",14));
	mp.insert(make_pair("O",16));
	mp.insert(make_pair("F",19));
	mp.insert(make_pair("Na",23));
	mp.insert(make_pair("Mg",24));
	mp.insert(make_pair("Al",27));
	mp.insert(make_pair("Si",28));
	mp.insert(make_pair("P",31));
	mp.insert(make_pair("S",32));
	mp.insert(make_pair("Cl",35.5));
	mp.insert(make_pair("K",39));
	mp.insert(make_pair("Ca",40));
	mp.insert(make_pair("Mn",55));
	mp.insert(make_pair("Fe",56));
	mp.insert(make_pair("Cu",64));
	mp.insert(make_pair("Zn",65));
	mp.insert(make_pair("Ag",108));
	mp.insert(make_pair("I",127));
	mp.insert(make_pair("Ba",137));
	mp.insert(make_pair("Hf",178.5));
	mp.insert(make_pair("Pt",195));
	mp.insert(make_pair("Au",197));
	mp.insert(make_pair("Hg",201));
}
int main(){
	getready();
	cin>>s;
	len=s.length();
	for(int i=0;i<len;++i){
		if(s[i]=='~'||s[i]=='(') place[++tot]=i;
	}
	place[++tot]=len;place[0]=-1;
	ss="";
	for(int i=1;i<=tot;++i){
		int j=place[i-1]+1,num=0,num1=0;sum=0;
		for(;s[j]>='0'&&s[j]<='9';++j) num=(num<<3)+(num<<1)+s[j]-'0';
		if(num==0) num=1;
		for(;j<place[i];++j){
			if(s[j]>='A'&&s[j]<='Z') {m[sum++]=mp[ss];ss="";}
			if(s[j]=='_'||s[j]==')'){
				m[sum++]=mp[ss];ss="";
				int nowj=j;
				if(s[j]==')') ++j;j+=2;
				num1=0;
				for(;s[j]>='0'&&s[j]<='9';++j) num1=(num1<<3)+(num1<<1)+s[j]-'0';
				if(s[nowj]=='_') m[sum-1]*=num1;
			}
			ss+=s[j];
		}
		if((s[place[i]-1]>='a'&&s[place[i]-1]<='z')||(s[place[i]-1]>='A'&&s[place[i]-1]<='Z')) m[sum++]=mp[ss]; 
		double tempans=0;
		for(int j=1;j<sum;++j) tempans+=m[j];
		if(place[i-1]>=0&&s[place[i-1]]=='(') num*=num1;
		ans+=tempans*num;
	}
	if(ans!=(int)ans) printf("%.1lf",ans);
	else printf("%d",(int)ans);
	return 0;
}
