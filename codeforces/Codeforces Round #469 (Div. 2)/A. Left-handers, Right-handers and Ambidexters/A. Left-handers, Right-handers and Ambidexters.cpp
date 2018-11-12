#include<cstdio>
#include<iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	int Left,Right,shuang;
	cin>>Left>>Right>>shuang;
	if(Left>Right) swap(Left,Right);
	shuang-=(Right-Left);
	if(shuang<0) Right+=shuang;
	else Right+=(shuang>>1);
	cout<<Right*2;
	return 0;
}
