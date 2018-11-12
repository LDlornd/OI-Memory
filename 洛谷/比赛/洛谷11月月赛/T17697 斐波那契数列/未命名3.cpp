#include<cstdio>
#include<iostream>
using namespace std;
int arr[50];
int main()
{
	int n;
	while(cin>>n)
	{	
		int ans=0;
		for(int a=1;a<=n;++a)
		{
			for(int b=1;b<=n;++b)
			{
				arr[0]=a;arr[1]=b;
				for(int i=2;i<40;++i)
				{
					arr[i]=arr[i-1]+arr[i-2];
					if(arr[i]==n) {++ans;break;}
					else if(arr[i]>n) break;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
