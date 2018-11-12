#include<cstdio>
#include<iostream>
#include<map>
using namespace std;
map<string,int> MAP;
inline string read()
{
	string x="";
	char c=getchar();
	while(c<'a'||c>'z') c=getchar();
	while(c>='a'&&c<='z') {x+=c;c=getchar();}
	return x;
}
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		string s=read();
		if(MAP.count(s))
		{
			printf("%s%d\n",s.c_str(),MAP[s]);
			++MAP[s];
		}
		else
		{
			printf("OK\n");
			MAP.insert(pair<string,int>(s,1));
		}
	}
	return 0;
}
