#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int tox[4]={-1,0,1,0};
int toy[4]={0,1,0,-1};
char MAP[12][12];
int main()
{
	memset(MAP,'*',sizeof(MAP));
	int cx,cy,ct=0,fx,fy,ft=0;
	for(int i=1;i<=10;++i)
	{
		scanf("%s",MAP[i]+1);
		MAP[i][11]='*';
	}
	for(int i=1;i<=10;++i)
		for(int j=1;j<=10;++j)
		{
			if(MAP[i][j]=='C') {cx=i;cy=j;}
			if(MAP[i][j]=='F') {fx=i;fy=j;}
		}
	//cout<<cx<<" "<<cy<<endl<<fx<<" "<<fy<<endl;
	int cnx=cx,cny=cy,fnx=fx,fny=fy;
	for(int i=1;;++i)
	{
		if(MAP[cnx+tox[ct]][cny+toy[ct]]=='*')
			ct=(ct+1)%4;
		else {cnx+=tox[ct];cny+=toy[ct];}
		if(MAP[fnx+tox[ft]][fny+toy[ft]]=='*')
			ft=(ft+1)%4;
		else {fnx+=tox[ft];fny+=toy[ft];}
		//printf("%d fx==%d fy==%d cx==%d cy==%d\n",i,fnx,fny,cnx,cny);
		//system("pause");
		if(fnx==cnx&&fny==cny) {printf("%d",i);break;}
		if(i>=1000000) {printf("0");break;}
	}
	return 0;
}
