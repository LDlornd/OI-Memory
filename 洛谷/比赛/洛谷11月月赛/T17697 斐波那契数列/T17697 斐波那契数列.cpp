#include<cstdio>
#include<iostream>
using namespace std;
typedef long long int ll;
const int mod=1e9+7;
ll a[46];
int x,y,xzxgbs,yzxgbs;
inline void exgcd(int a,int b)
{
	if(b==0)
	{
		x=1;y=0;
		return;
	}
	exgcd(b,a%b);
	int k=x;
	x=y;y=k-a/b*y;
}
int main()
{
	a[0]=0;
	a[1]=1;
	for(int i=2;i<46;++i)
	{
		a[i]=a[i-1]+a[i-2];
		cout<<i<<" "<<a[i]<<endl;
	}
	int n,ans=0;
	scanf("%d",&n);
	for(int i=2;i<46;++i)
	{
		//f(i)=g(i)*f(1)+g(i-1)*f(0);
		if(a[i]>n) break;
		exgcd(a[i],a[i-1]);
		cout<<a[i]<<" "<<a[i-1]<<"!!!!!!"<<endl;
		x*=n;y*=n;
		if(x<=0)
		{
			int num=-x/a[i-1]+1;
			y-=num*a[i];
			x+=num*a[i-1];
			if(y<=0) continue;
			ans+=y/a[i]+(1&&y%a[i]);
			ans%=mod;
			/*while(y>0)
			{
				//cout<<x<<" "<<y<<endl;
				y-=a[i];x+=a[i-1];
				//++ans;
			}*/
		}
		else if(y<=0)
		{
			int num=-y/a[i]+1;
			x-=num*a[i-1];
			y+=num*a[i];
			if(x<=0) continue;
			ans+=(x/a[i-1]+(1&&x%a[i-1]));
			//ans%=mod;
			/*while(x>0)
			{
				//cout<<x<<" "<<y<<endl;
				x-=a[i-1];y+=a[i];
				//++ans;
			}*/
			ans%=mod;
		}
		ans%=mod;
		cout<<ans<<endl;
	}
	printf("%d",ans);
	return 0;
}
