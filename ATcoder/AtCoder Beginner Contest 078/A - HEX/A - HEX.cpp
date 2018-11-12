#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	char a,b;
	scanf("%c %c",&a,&b);
	if(a<b) printf("<");
	else if(a>b) printf(">");
	else if(a==b) printf("=");
	return 0;
}
