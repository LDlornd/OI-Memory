#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
char a[51];
int main()
{
	scanf("%s",a);
	int len=strlen(a)-8;
	a[len]='\0';
	printf("%s",a);
	return 0;
}
