#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
inline bool CMP1(char a,char b)
{
	return a<b;
}
inline bool CMP2(char a,char b)
{
	return a>b;
}
int main()
{
	string s,t;
	cin>>s>>t;
	sort(s.begin(),s.end(),CMP1);
	sort(t.begin(),t.end(),CMP2);
	if(s<t) printf("Yes");
	else printf("No");
	return 0;
}
