#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int num[26],ans1,ans2,k;
void print(int x,int y)
{
	if(ans2>(x/2)) {printf("No");return;}
	else {printf("Yes");return;}
}
int main()
{
	memset(num,0,sizeof(num));
	char c;
	int n,m;
	scanf("%d%d\n",&n,&m);
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
		{
			if(j==m-1) scanf("%c\n",&c);
			else scanf("%c",&c);
			++num[c-'a'];
		}
	for(int i=0;i<26;++i)
		if(num[i]!=0)
		{
			k+=(num[i]/4);
			if(num[i]%4==1) ++ans1;
			if(num[i]%4==2) ++ans2;
			if(num[i]%4==3) {++ans1;++ans2;}
		}
	if(ans1>1) {printf("No");return 0;}
	if(m%2==0&&n%2==0)
	{
		if(ans1==0&&ans2==0) printf("Yes");
		else printf("No");
		return 0;
	}
	if(m%2==0&&n%2!=0) {print(m,n);return 0;}
	if(m%2!=0&&n%2==0) {print(n,m);return 0;}
	if(m%2!=0&&n%2!=0)
	{
		if(ans2>(m/2+n/2)) printf("No");
		else printf("Yes");
		return 0;
	}
}
