#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string s[10000];
bool CMP1(char a,char b)
{
	return a<b;
}
bool CMP2(string a,string b)
{
	return a<b;
}
int main()
{
	int n,ans=1;
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		cin>>s[i];
		sort(s[i].begin(),s[i].end(),CMP1);
	}
	sort(s,s+n,CMP2);
	for(int i=0;i<n-1;++i)
		if(s[i]!=s[i+1]) ++ans;
	printf("%d",ans);
	return 0;
}
