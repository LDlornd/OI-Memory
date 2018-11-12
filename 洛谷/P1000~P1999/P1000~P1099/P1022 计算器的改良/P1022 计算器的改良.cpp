#include<cstdio>
#include<iostream>
#include<string>
#include<queue>
using namespace std;
queue<int> xishu,changshu;
int main()
{
	char c;
	string s;
	cin>>s;
	int len=s.length(),p,sum=0;
	bool flag=true;
	for(int i=0;i<len;++i)
	{
		if(s[i]=='=')
		{
			if(sum!=0) {changshu.push(sum);sum=0;}
			p=i;
			break;
		}
		if(s[i]>='a'&&s[i]<='z')
		{
			c=s[i];
			if(sum!=0) xishu.push(sum);
			else
			{
				if(flag) xishu.push(1);
				else xishu.push(-1);
			}
			sum=0;
		}
		if(s[i]=='-')
		{
			if(sum!=0) {changshu.push(sum);sum=0;}
			flag=false;
		}
		if(s[i]=='+')
		{
			if(sum!=0) {changshu.push(sum);sum=0;}
			flag=true;
		}
		if(s[i]>='0'&&s[i]<='9')
		{
			sum*=10;
			if(flag) sum+=(s[i]-'0');
			else sum-=(s[i]-'0');
		}
	}
	flag=false;
	for(int i=p+1;i<len;++i)
	{
		if(s[i]>='a'&&s[i]<='z')
		{
			c=s[i];
			if(sum!=0) xishu.push(sum);
			else
			{
				if(flag) xishu.push(1);
				else xishu.push(-1);
			}
			sum=0;
		}
		if(s[i]=='-')
		{
			if(sum!=0) {changshu.push(sum);sum=0;}
			flag=true;
		}
		if(s[i]=='+')
		{
			if(sum!=0) {changshu.push(sum);sum=0;}
			flag=false;
		}
		if(s[i]>='0'&&s[i]<='9')
		{
			sum*=10;
			if(flag) sum+=(s[i]-'0');
			else sum-=(s[i]-'0');
		}
	}
	changshu.push(sum);
	while(xishu.front()!=xishu.back())
	{
		xishu.back()+=xishu.front();
		xishu.pop();
	}
	while(changshu.front()!=changshu.back())
	{
		changshu.back()+=changshu.front();
		changshu.pop();
	}
	double ans=	(double) -changshu.front()/xishu.front();
	if(ans==0) printf("%c=0.000",c);
	else printf("%c=%.3lf",c,ans);
	return 0;
}
