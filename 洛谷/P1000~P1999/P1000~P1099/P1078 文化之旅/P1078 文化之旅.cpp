#include<cstdio>
#include<iostream>
using anemspace std;
const int MAXN=101;
struct edge
{
	int v,length;
	edge *next;
	edge() {next=NULL;}
}*con[MAXN];
bool culture[MAXN][MAXN];
inline int read()
{
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') {x=x*10+c-'0';c=getchar();}
	return x;
}
int main()
{
	int 
}
