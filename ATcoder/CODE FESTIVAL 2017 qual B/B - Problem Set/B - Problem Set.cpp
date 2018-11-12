#include<cstdio>
#include<iostream>
#include<map>
using namespace std;
map<int,int> flag;
int main()
{
	int m,n,x;
	scanf("%d",&m);
	for(int i=0;i<m;++i)
	{
		scanf("%d",&x);
		if(flag.count(x)) ++flag[x];
		else flag.insert(pair<int,int>(x,1));
	}
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		scanf("%d",&x);
		if(flag.count(x))
		{
			if(flag[x]==0) {printf("NO");return 0;}
			--flag[x];
		}
		else {printf("NO");return 0;}
	}
	printf("YES");
	return 0;
}
