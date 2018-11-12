#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<iostream>
using namespace std;
int main()
{
	freopen("testdatain.in","w",stdout);
	srand(time(0));
	int n=5;
	int m=20;
	cout<<n<<" "<<m<<endl;
	while(m--)
	{
		int a=rand()%(n-1)+1,b=rand()%(n-1)+1,c=rand()%(n-1)+1,d=rand()%(n-1)+1;
		bool flag1=rand()%2,flag2=rand()%2;
		if(flag1) a=1;
		if(flag2) b=1;
		//cout<<ra<<" "<<rand()%(n-1)+1<<" "<<rand()%(n-1)+1<<" "<<rand()%(n-1)+1<<endl;
		cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl; 
	}
}
