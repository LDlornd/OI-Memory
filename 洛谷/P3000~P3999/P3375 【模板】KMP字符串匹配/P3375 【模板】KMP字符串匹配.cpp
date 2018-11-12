#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
char s1[1000000],s2[1000];
int nexta[1000];
void getready(char a[])
{
	nexta[0]=0;
	int len=strlen(a);
	int p,k;
	for(p=1,k=0;p<len;++p)
	{
		while(k>0&&a[p]!=a[k])
			k=nexta[k-1];
		if(a[p]==a[k]) ++k;
		nexta[p]=k;
	}
}
void KMP(char a[],char b[],int lena,int lenb)
{
	for(int i=0,j=0;i<lena;++i)
	{
		while(j>0&&a[i]!=b[j])
			j=nexta[j-1];
		if(a[i]==b[j]) ++j;
		if(j==lenb)
		{
			printf("%d\n",i-lenb+2);
			j=nexta[j-1];
		}
	}
}
int main()
{
	scanf("%s%s",s1,s2);
	getready(s2);
	int len1=strlen(s1),len2=strlen(s2);
	KMP(s1,s2,len1,len2);
	for(int i=0;i<len2;++i)
		if(i==0) printf("%d",nexta[i]);
		else printf(" %d",nexta[i]);
	return 0;
}
