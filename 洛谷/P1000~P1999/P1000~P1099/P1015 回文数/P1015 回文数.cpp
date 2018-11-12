#include<cstdio>
#include<cstring>
using namespace std;
int a[150],b[150],c[150];
int len=0;
void change(int s1[],int s2[],int lenx)
{
	for(int i=0;i<lenx;++i)
		s2[lenx-1-i]=s1[i];
}
bool judge(int s1[])
{
	for(int i=0,j=len-1;i<j;++i,--j)
		if(s1[i]!=s1[j]) return false;
	return true;
}
bool add(int s1[],int s2[],int s3[],int z)
{
	change(a,b,len);
	for(int i=0;i<len;++i)
	{
		s3[i]=s1[i]+s2[i];
	}
	for(int i=0;i<len;++i)
	{
		s3[i+1]+=s3[i]/z;
		s3[i]%=z;
	}
	if(s3[len]!=0) ++len;
	return judge(c);
}
int main()
{
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	int n,ans=0;
	char m[101];
	scanf("%d %s",&n,m);
	for(int i=0;m[i]!='\0';++i)
	{
		if(m[i]>='A'&&m[i]<='F') a[i]=m[i]-'A'+10;
		else a[i]=m[i]-'0';
		++len;
	}
	for(int k=0;k<30;++k)
	{
		bool flag=add(a,b,c,n);
		if(flag==true) {ans=k+1;break;}
		memset(a,0,sizeof(a));
		for(int i=0;i<len;++i)
			a[i]=c[i];
	}
	if(ans==0) printf("Impossible!");
	else printf("STEP=%d",ans);
	return 0;
}
