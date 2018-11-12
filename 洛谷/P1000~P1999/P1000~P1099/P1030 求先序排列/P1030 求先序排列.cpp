#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
string mid,after;
inline void gouzao(int midstart,int midend,int afterstart,int afterend)
{
	//cout<<midstart<<" "<<midend<<" "<<afterstart<<" "<<afterend<<endl;
	if(midstart>midend||afterstart>afterend) return;
	cout<<after[afterend];
	if(midstart==midend) return;
	for(int i=midstart;i<=midend;++i)
	{
		if(mid[i]==after[afterend])
		{
			gouzao(midstart,i-1,afterstart,afterstart+i-midstart-1);
			gouzao(i+1,midend,afterend-midend+i,afterend-1);
			break;
		}
	}
}
int main()
{
	cin>>mid>>after;
	int len=mid.length();
	gouzao(0,len-1,0,len-1);
	return 0;
}
