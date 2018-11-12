#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	int num=0;
	char c;
	while(scanf("%c",&c))
	{
		if(c=='@') break;
		if(c=='(') ++num;
		if(c==')') --num;
	}
	if(num==0) printf("YES");
	else printf("NO");
	return 0;
}
