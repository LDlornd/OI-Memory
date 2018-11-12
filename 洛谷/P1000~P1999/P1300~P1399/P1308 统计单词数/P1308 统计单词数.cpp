#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct word
{
	string w;
	int l;
};
char toL(char a)
{
	if(a>='a'&&a<='z') a-=32;
	return a;
}
int main()
{
	vector<struct word> wd;
	string a,k;
	bool flag=false;
	int ans=0,num=0,pos=0;
	getline(cin,k);getline(cin,a);
	transform(k.begin(),k.end(),k.begin(),toL);
	transform(a.begin(),a.end(),a.begin(),toL);
	k=' '+k+' ';a=' '+a+' ';
	int m=a.find(k,pos);
	while(m!=-1)
	{
		if(!flag) ans=pos+1;
		flag=true;++num;
		pos=m+1;
		m=a.find(k,pos);
	}
	if(num==0) cout<<-1;
    else cout<<num<<" "<<ans;
	return 0;
}
