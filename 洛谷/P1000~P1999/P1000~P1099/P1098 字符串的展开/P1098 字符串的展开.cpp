#include<cstdio>
#include<cstring>
using namespace std;
int p1,p2,p3;
void zhankai(char a,char b)
{
	if(a>='a'&&a<='z')
	{
		if(b<'a'||b>'z'||b<=a) {printf("-");return;}
		if(b==a+1) return;
		if(p1==3)
		{
			for(char i=b-1;i>a;--i)
			{
				for(int j=0;j<p2;++j)
					printf("*");
			}
			return;
		}
		if(p3==2)
		{
			for(char i=b-1;i>a;--i)
			{
				int m=p2+1;
				for(int j=0;j<p2;++j)
				{
					if(p1==1) printf("%c",i);
					if(p1==2) printf("%c",i-32);
				}
			}
			return;
		}
		for(char i=a+1;i<b;++i)
		{
			int m=p2+1;
			while(--m)
			{
				if(p1==1) printf("%c",i);
				if(p1==2) printf("%c",i-32);
			}
		}
		return;
	}
	if(a>='0'&&a<='9')
	{
		if(b<'0'||b>'9'||b<=a) {printf("-");return;}
		if(b==a+1) return;
		if(p1==3)
		{
			for(char i=b-1;i>a;--i)
			{
				for(int j=0;j<p2;++j)
					printf("*");
			}
			return;
		}
		if(p3==2)
		{
			for(char i=b-1;i>a;--i)
			{
				int m=p2+1;
				while(--m)
					printf("%c",i);
			}
			return;
		}
		for(char i=a+1;i<b;++i)
		{
			int m=p2+1;
			while(--m)
				printf("%c",i);
		}
		return;
	}
	printf("-");
	return;
}
int main()
{
	freopen("testin.in","r",stdin);
	freopen("WAout.out","w",stdout);
	char s[101];
	scanf("%d%d%d%s",&p1,&p2,&p3,s);
	int len=strlen(s);
	for(int i=0;i<len;++i)
	{
		if(s[i]!='-') {printf("%c",s[i]);continue;}
		zhankai(s[i-1],s[i+1]);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
