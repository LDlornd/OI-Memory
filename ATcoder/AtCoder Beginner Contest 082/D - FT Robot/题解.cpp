#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[2][20010],gx,gy,len,n[2],kk;
char s[20010];
bool f[2][2][20010];
int main()
{
	scanf("%s",s+1);
	scanf("%d%d",&gx,&gy);
	len=strlen(s+1);
	int tmp;
	for(tmp=1;tmp<=len&&s[tmp]=='F';tmp++);
	kk=0;l
	for(int i=tmp;i<=len;i++)
		if(s[i]=='F') a[kk][n[kk]+1]++;
		else n[kk]++,kk^=1;
	f[0][0][8000+tmp-1]=f[0][1][8000]=1;
	n[kk]++;
	for(int k=0;k<=1;k++)
		for(int i=1;i<=n[k];i++)
		{
			memset(f[i&1][k],0,sizeof(f[i&1][k]));
			for(int j=-8000;j<=8000;j++)
				if(f[(i&1)^1][k][j+8000]==1) 
					f[i&1][k][j-a[k][i]+8000]=f[i&1][k][j+a[k][i]+8000]=1;
		}
	if(f[n[0]&1][0][gx+8000]&&f[n[1]&1][1][gy+8000]) printf("Yes");
	else printf("No");			 	
	return 0;
}
