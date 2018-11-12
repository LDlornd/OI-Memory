#include <iostream>
using namespace std;
long long int k, l, r, t;
void solve(long long int a)
{
    if(a==2)
    {
        k=1;
        l=1;
    }
    else if(a%2==0)
    {
        solve(a/2);
        t=k*k+2*k*l;
        l=k*k+l*l;
        k=t;
    }
    else if(a%2==1)
    {
        solve(a-1);
        t=k+l;
        l=k;
        k=t;
    }
    k%=20171111;
    l%=20171111;
}
int main()
{
    long long int a=0, p, q;
    long long int ans=0;
    cin>>a>>q>>p;
    if(p==5||p==7)
    {
	    q-=4;
	    q/=2;
        if(p==7)
            q-=1;
        if(q>0)
	        if(q%2==1)
	        {
	        	solve(q+2);
	        	ans+=k-1;
	        	ans%=20171111;
			}
			else
			{
				solve(q);
				ans+=k;
				solve(q+1);
				ans+=k-1;
				ans%=20171111;
			}
        if(a==5||a==7)
        	ans++;
    	if(q<=0)
    		cout<<'0';
    	else 
    		cout<<ans;
    }
    else if(p==3)
    	if(a!=3)
    		if(q>3)
    			cout<<'1';
    		else
    			cout<<'0';
    	else
    		if(q>3)
    			cout<<'2';
    		else
    			cout<<'1';
    else if(a==p)
        cout<<'1';
    else
        cout<<'0';
    return 0;
}
