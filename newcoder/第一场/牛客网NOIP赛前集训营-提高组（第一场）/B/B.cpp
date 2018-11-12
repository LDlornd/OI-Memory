#include<cstdio>
#include<iostream>
using namespace std;
typedef long long int ll;
ll L,R,L1,R1,ans=0;
bool judge(int key){
	int temp=1;
	while(key){
		temp*=(key%10);
		key/=10;
	}
	if(temp>=L1&&temp<=R1) return true;
	else return false;
}
int main(){
	scanf("%lld%lld%lld%lld",&L,&R,&L1,&R1);
	for(int i=L;i<=R;++i)
		if(judge(i)) ++ans;
	printf("%lld",ans);
	return 0;
}
