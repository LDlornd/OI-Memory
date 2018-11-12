#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
string s;
long long int n,M=0,A=0,R=0,C=0,H=0;
long long int ans=0;
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>s;
		if(s[0]=='M') ++M;
		if(s[0]=='A') ++A;
		if(s[0]=='R') ++R;
		if(s[0]=='C') ++C;
		if(s[0]=='H') ++H;
	}
	ans+=(M*A*R+M*A*C+M*A*H);
	ans+=(M*R*C+M*R*H+M*C*H);
	ans+=(A*R*C+A*R*H+A*C*H);
	ans+=(R*C*H);
	printf("%lld",ans);
	return 0;
}
