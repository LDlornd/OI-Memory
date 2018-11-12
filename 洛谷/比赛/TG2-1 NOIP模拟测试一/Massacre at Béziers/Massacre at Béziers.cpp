#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
struct forg
{
	long long int x,y,z;//第i只青蛙会每过xi秒会连续叫yi秒,从第二次开始每次休息结束后这只青蛙连续叫的时间会增加zi秒。
};
forg a[100000];
long long int getans(long long int a,long long int b,long long int c)
{
	if(a==0)
	{
		double temp=-c/b;
		return (long long int) temp;
	}
	//cout<<a<<" "<<b<<" "<<c<<endl;
	double judge=sqrt(b*b-4*a*c);
	double temp=(-b+judge)/(2*a);
	//cout<<judge<<" "<<temp<<endl;
	return (long long int) temp;
}
int main()
{
	//freopen("sample5.in","r",stdin);
	int n,t;
	long long int ans=0;
	scanf("%d%d",&n,&t);
	for(int i=1;i<=n;++i)
	{
		scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].z);
		long long int h=getans(a[i].z,2*a[i].x+2*a[i].y-a[i].z,-2*t);
		//cout<<"h=="<<h<<endl;
		long long int k=(h*a[i].y+h*(h-1)*a[i].z/2);
		//cout<<k<<endl;
		ans+=k;
		//cout<<"ans1=="<<ans<<" ans2==";
		k+=((h+1)*a[i].x);
		if(k<t) ans+=(t-k);
		//cout<<ans<<endl<<endl;
	}
	printf("%lld",ans);
	return 0;
}
