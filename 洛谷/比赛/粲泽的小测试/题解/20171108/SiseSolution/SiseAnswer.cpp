#include <iostream>
using namespace std;
int main()
{
	int Ship[11]={0, 1, 3, 5, 7, 10, 15, 16, 18, 21, 23}, Siprice[11]={0}, EverySi[11]={0}, s[100010]={0};
	long long int  solution[100010]={0}, q; 
	int SiStone, i, j;
	cin>>SiStone;
	for(i=1;i<=10;i++)
		cin>>Siprice[i];
	for(i=1;i<=10;i++)
	{
		q=-1000;
		for(j=1;j<=i;j++)
			if(EverySi[i-j]+Siprice[j]>q)
				q=EverySi[i-j]+Siprice[j];
		EverySi[i]=q;
	}
	for(i=1;i<=10;i++)
		EverySi[i]-=Ship[i];
	for(i=1;i<=SiStone;i++)
	{
		q=-1000;
		if(i>10)
			for(j=1;j<=10;j++)
				if(solution[i-j]+EverySi[j]>q)
					q=solution[i-j]+EverySi[j];
				else;
		else
			for(j=1;j<=i;j++)
				if(solution[i-j]+EverySi[j]>q)
					q=solution[i-j]+EverySi[j];
		solution[i]=q;
	}
	cout<<solution[SiStone];
	return 0;
} 
