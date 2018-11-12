#include<cstdio>
#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
string s;
int mark1,mark2;
void com(int a,int len)
{
	mark1=0;mark2=0;
	for(int i=0;i<len;++i)
	{
		if(s[i]=='W') ++mark1;
		if(s[i]=='L') ++mark2;
		if(s[i]=='E')
			printf("%d:%d\n",mark1,mark2);
		if((mark1>=a||mark2>=a)&&abs(mark1-mark2)>=2)
		{
			printf("%d:%d\n",mark1,mark2);
			mark1=0;
			mark2=0;
		}
	}
}
int main()
{
	char a='\0';
	while(a!='E')
		{scanf("%c",&a);s+=a;}
	cout<<s;
	int len=s.length();
	com(11,len);
	printf("\n");
	com(21,len);
	return 0;
}
