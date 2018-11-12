#include<cstdio>
#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
int main()
{
	freopen("testdata.in","w",stdout);
	srand(time(0));
	int n=rand()%100;
	printf("%d\n",n);
	for(int i=1;i<=n;++i)
	{
		char c1=rand()%26+'a',c2=rand()%26+'A';
		bool flag=rand()%2;
		if(flag) printf("%c",c1);
		else printf("%c",c2);
	}
	fclose(stdout);
	return 0;
}
