#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
const int MAXN1=100;
const int MAXN2=3000;
int n,u,v,first,place=0,num=0;
int du[MAXN1],result[MAXN2],now=0;
char s[5];
int Edge[MAXN1][MAXN1];
bool flag=true;
inline int charchange(char c)
{
	return c-'A'+1;
}
inline char intchange(int c)
{
	return 'A'-1+c;
}
inline void Find(int start)
{
	for(int i=1;i<MAXN1;++i)
		if(Edge[start][i])
		{
			--Edge[start][i];--Edge[i][start];
			Find(i);
		}
	result[++now]=start;
}
int main()
{
	memset(du,0,sizeof(du));
	memset(Edge,0,sizeof(Edge));
	scanf("%d\n",&n);
	while(n--)
	{
		scanf("%s",s);
		u=charchange(s[0]);v=charchange(s[1]);
		++du[v];++du[u];
		++Edge[u][v];++Edge[v][u];
	}
	for(int i=1;i<MAXN1;++i)
	{
		if(du[i]&1)
		{
			++num;
			if(place==0) place=i;
		}
		if(du[i]&&flag) {first=i;flag=false;}
	}
	if(num>2) {printf("No Solution");return 0;}
	else if(num==2) Find(place);
	else Find(first);
	for(int i=now;i>=1;--i)
		printf("%c",intchange(result[i]));
	return 0;
}
