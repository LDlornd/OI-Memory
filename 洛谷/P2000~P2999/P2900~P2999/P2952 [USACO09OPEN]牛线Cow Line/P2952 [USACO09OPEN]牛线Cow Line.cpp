#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int MAXN=1000001;
char s[10];
int dl[MAXN],head=1,tail=1,id=1;
inline void left_insert()
{
	if(head==1) head=MAXN-1;
	else --head;
	dl[head]=id++;
}
inline void right_insert()
{
	dl[tail]=id++;
	if(tail==MAXN-1) tail=1;
	else ++tail;
}
inline void left_delete(int num)
{
	for(int i=0;i<num;++i)
		if(head==MAXN-1) head=1;
		else ++head;
}
inline void right_delete(int num)
{
	for(int i=0;i<num;++i)
	{
		if(tail==1) tail=MAXN-1;
		else --tail;
	}
}
int main()
{
	freopen("testdata.in","r",stdin);
	freopen("ans.out","w",stdout);
	int n,x;
	char c1,c2;
	//scanf("%d\n",&n);
	cin>>n;
	for(int w=0;w<n;++w)
	{
		//cin.getline(s,10,'\n');
		cin>>c1>>c2;
		if(c1=='A'&&c2=='L') left_insert();
		if(c1=='A'&&c2=='R') right_insert();
		if(c1=='D'&&c2=='L') {cin>>x;left_delete(x);}
		if(c1=='D'&&c2=='R') {cin>>x;right_delete(x);}
	}
	int i=head;
	while(i!=tail)
	{
		printf("%d\n",dl[i]);
		if(i==MAXN-1) i=1;
		else ++i;
	}
	return 0;
}
