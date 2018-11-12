#include<cstdio>
#include<iostream>
using namespace std;
int main(){
	int sum=0;
	for(int k=1;k<=100;++k){
		int ans=0;
		for(int i=1;i<=k;++i)
			for(int j=1;j<=k;++j)
				if(k%(i*j)==0) ++ans;
		sum+=ans;
		cout<<k<<" "<<ans<<endl;
	}
}
