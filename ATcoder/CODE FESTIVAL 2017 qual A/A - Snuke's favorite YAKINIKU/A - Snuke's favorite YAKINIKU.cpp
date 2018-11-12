#include<cstdio>
#include<iostream>
#include<cstring> 
using namespace std;
char c[11];
int main()
{
	scanf("%s",c);
	int len=strlen(c);
	if(len<4||c[0]!='Y'||c[1]!='A'||c[2]!='K'||c[3]!='I') printf("No");
	else printf("Yes");
	return 0;
}
